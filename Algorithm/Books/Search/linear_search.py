def liner_search(items: list, targets: set) -> int:
    counter = sum(1 for item in items if item in targets)
    return counter


if __name__ == "__main__":
    n = int(input())
    items = list(map(int, input().split(" ")))
    q = int(input())
    targets = set(map(int, input().split(" ")))

    print(liner_search(items, targets))
