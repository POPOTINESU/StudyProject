def bubbleSort(total):
    items = list(map(int, input().split(" ")))

    if total < 2:
        return

    for i in range(total):
        flag = False
        for j in range(total - 1, i, -1):
            if items[j] < items[j - 1]:
                items[j], items[j - 1] = items[j - 1], items[j]
                flag = True

        if not flag:
            break

    print(items)


if __name__ == "__main__":
    bubbleSort(int(input()))
