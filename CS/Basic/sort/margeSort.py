def mergeSort(arr: list[int]) -> list[int]:
    if len(arr) <= 1:
        return arr
    middle = len(arr) // 2
    leftArr = mergeSort(arr[0:middle])
    rightArr = mergeSort(arr[middle:])

    leftIndex, rightIndex, key = 0, 0, 0

    while leftIndex < len(leftArr) and rightIndex < len(rightArr):
        if leftArr[leftIndex] <= rightArr[rightIndex]:
            arr[key] = leftArr[leftIndex]
            leftIndex += 1
        else:
            arr[key] = rightArr[rightIndex]
            rightIndex += 1

        key += 1

    while leftIndex < len(leftArr):
        arr[key] = leftArr[leftIndex]
        leftIndex += 1
        key += 1

    while rightIndex < len(rightArr):
        arr[key] = rightArr[rightIndex]
        rightIndex += 1
        key += 1

    return arr


print(mergeSort([2, 12, 5, 10, 9, 8]))
