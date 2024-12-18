days = int(input())
attendance = int(input())

attendees = [0] * (days + 2)

for index in range(attendance):
    start, end = map(int, input().split())
    if start > end:
        raise ValueError("start is less than end value")
    attendees[start] += 1
    attendees[end + 1] -= 1

for index in range(1, days + 1):
    attendees[index] += attendees[index - 1]

for day in range(1, days + 1):
    print(attendees[day])
