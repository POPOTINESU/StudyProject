def calcDistanceList(pointsList) -> list:
    def calcDistance(string: str) -> int:
        points = string.split("-")
        return abs(int(points[0]) - int(points[1]))

    return [calcDistance(s) for s in pointsList]
