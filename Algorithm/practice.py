def maximum_profit(amounts: list[int]) -> int:
    max_profit = -200_000
    min_buy_price = 1_000_000_001

    for amount in amounts:
        max_profit = max(max_profit, amount - min_buy_price)
        min_buy_price = min(amount, min_buy_price)

    return max_profit


if __name__ == "__main__":
    days = int(input())
    amounts = list(map(int, input().split(" ")))

    maximum_profit(amounts)
