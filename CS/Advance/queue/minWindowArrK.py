from collections import deque


def minWindowArrK(intArr, k) -> list:
    dq = deque()
    answer = []
    for i in range(0, k):
        while len(dq) != 0 and intArr[i] < intArr[dq[-1]]:
            dq.pop()
        dq.append(i)

    for i in range(k, len(intArr)):
        answer.append(intArr[dq[0]])

        while len(dq) != 0 and dq[0] <= i - k:
            dq.popleft()

        while len(dq) != 0 and intArr[i] < intArr[dq[-1]]:
            dq.pop()

        dq.append(i)


    answer.append(intArr[dq.popleft()])
    return answer


print(minWindowArrK([24,5,67,60,24,64,23,536,345],3))
