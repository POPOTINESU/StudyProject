def reverse_poland():
    items = list(map(str, input("Enter RPN expression: ").split()))
    stack = []

    for item in items:
        match item:
            case "+":
                b = stack.pop()
                a = stack.pop()
                stack.append(a + b)
            case "-":
                b = stack.pop()
                a = stack.pop()
                stack.append(a - b)
            case "*":
                b = stack.pop()
                a = stack.pop()
                stack.append(a * b)
            case "/":
                b = stack.pop()
                a = stack.pop()
                stack.append(a / b)
            case _:
                stack.append(int(item))

    return stack.pop()


print(reverse_poland())
