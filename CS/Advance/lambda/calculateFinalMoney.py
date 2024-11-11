from functools import reduce


def calculateFinalMoney(interests, capital) -> int:
    total = reduce(lambda total, rate: total * (1 + (rate / 100)), interests, capital)
    return int(total)
