def calcSpeed(data: str) -> int:
    point1, point2, time = map(int, data.split("-"))
    return int(abs(point1 - point2) / time)


def upper10mpsList(pointsData) -> list:
    return list(
        filter(lambda speed: speed >= 10, [calcSpeed(speed) for speed in pointsData])
    )
