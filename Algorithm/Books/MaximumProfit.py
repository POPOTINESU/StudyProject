def maximum_profit() -> None:
    days = int(input())
    amounts = [int(input()) for _ in range(days)]
    
    max_profit = -1000000000
    min_amount = amounts[0]
    
    for i in range(1, len(amounts)):
        max_profit = max(max_profit, amounts[i] - min_amount)
        min_amount = min(min_amount, amounts[i])
    
    print(max_profit)

if __name__ == "__main__":
    maximum_profit()