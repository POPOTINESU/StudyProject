time = int(input())
employees = int(input())

time_table = [0] * (time + 1)

for _ in range(employees):
    start, end = map(int, input().split())
    time_table[start] += 1
    time_table[end + 1] -= 1

for t in range(1,time + 1):
    time_table[t] += time_table[t - 1]

for t in range(time + 1):
    print(time_table[t])
