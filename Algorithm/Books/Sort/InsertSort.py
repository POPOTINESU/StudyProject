def insertSort(total):
    items = list(map(int, input().split(" ")))

    for index in range(1, len(items)):
        left = index - 1
        target = items[index]

        while left >= 0 and items[left] > target:
            items[left + 1] = items[left]
            left -= 1

        items[left + 1] = target

    print(items)


if __name__ == "__main__":
    insertSort(int(input()))
