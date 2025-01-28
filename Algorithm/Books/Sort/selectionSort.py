def selectionSort(total):
    items = list(map(int, input().split(" ")))

    for i in range(len(items)):
        min_index = i

        for j in range(i, len(items)):
            if items[min_index] > items[j]:
                min_index = j

        items[min_index], items[i] = items[i], items[min_index]
    print(items)


if __name__ == "__main__":
    selectionSort(int(input()))
