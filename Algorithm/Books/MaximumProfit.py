def maximum_profit() -> None:
    days = int(input())
    amounts = [int(input()) for _ in range(days)]

    min_amount = amounts[0]
    max_profit = -10000000001

    for day in range(1, days):
        max_profit = max(max_profit, amounts[day] - min_amount)
        min_amount = min(min_amount, amounts[day])

    print(max_profit)


if __name__ == "__main__":
    maximum_profit()