def insert_sort(items: list) -> list:
    total = len(items)

    for current_index in range(1, total):
        target = items[current_index]
        sorted_index = current_index - 1

        while sorted_index >= 0 and items[sorted_index] > target:
            items[sorted_index + 1] = items[sorted_index]
            sorted_index -= 1

        items[sorted_index + 1] = target

    return items


if __name__ == "__main__":
    total = int(input())
    items = list(map(int, input().split(" ")))
    print(insert_sort(items))
