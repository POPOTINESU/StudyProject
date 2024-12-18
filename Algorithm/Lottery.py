N = int(input())

results = [0 for _ in range(N + 1)]

for index, value in enumerate(map(int, input().split()), 1):
    results[index] = results[index - 1] + value


def get_result(start, end):
    total_count = end - start + 1

    win_count = results[end] - results[start - 1]
    lose_count = total_count - win_count

    if win_count == lose_count:
        return "draw"
    elif win_count > lose_count:
        return "win"

    return "lose"


Q = int(input())
for _ in range(Q):
    start, end = map(int, input().split())
    print(get_result(start, end))
