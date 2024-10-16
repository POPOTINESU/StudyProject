package main

func recursiveDigitsAdded(digits int64) int32 {
	if digits < 10 {
		return int32(digits)
	}
	return int32(divideTotalNumber(digits, 0, 0))
}

func divideTotalNumber(digits int64, total int64, finalTotal int64) int64 {
	if digits < 10 {
		total += digits

		if total < 10 {
			return finalTotal + total
		}
		return divideTotalNumber(total, 0, finalTotal+total)
	}

	return divideTotalNumber(digits/10, total+(digits%10), finalTotal)
}
