def selectionSort(total):
    items = list(map(int, input().split(" ")))

    for i in range(total):
        swap_index = i
        for j in range(i, total):
            if items[swap_index] > items[j]:
                swap_index = j

        items[i], items[swap_index] = items[swap_index], items[i]

    print(items)


if __name__ == "__main__":
    selectionSort(int(input()))
