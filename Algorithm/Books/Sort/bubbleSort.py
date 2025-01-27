def bubbleSort(total):
    items = list(map(int, input().split(" ")))

    for i in range(len(items)):
        flag = False
        for j in range(len(items) - 1, i, -1):
            if items[j] < items[j - 1]:
                items[j], items[j - 1] = items[j - 1], items[j]
                flag = True

        if not flag:
            # when flag is True, already sorted array
            break
        
    print(items)
if __name__ == "__main__":
    bubbleSort(int(input()))
