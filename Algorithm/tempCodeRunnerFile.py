N, Q = map(int, input().split())

guests = [0 for _ in range(N + 1)]

for i, guest in enumerate(map(int, input().split()),1):
        guests[i + 1] = guests[i] + guest

for _ in range(Q):
    start, end = map(int, input().split())
    if start > end:
        raise ValueError("must start less than end")
    print(guests[end] - guests[start-1])
