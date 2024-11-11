def convertMeter(distance: str) -> float:
    unit = {"km": 1000.0, "m": 1.0, "cm": 0.01, "mm": 0.001}
    num = unit.get(distance[-2:], 1.0)
    return num * int(distance[:-2]) if num != 1.0 else float(distance[:-1])

def over100m(l) -> list:
    converted_list = [convertMeter(x) for x in l]
    return [x for x in converted_list if x >= 100]
