from functools import reduce


def calcProfit(stock: str) -> int:
    buyPrice, numberOwned, currentPrice = map(int, stock.split("-"))
    return (currentPrice * numberOwned) - (buyPrice * numberOwned)


def calcProfitsOrLosses(stockList) -> int:
    # sumの方が簡潔だが、reduceの勉強なのでこのまま
    return reduce(lambda profit, stock: profit + calcProfit(stock), stockList, 0)
