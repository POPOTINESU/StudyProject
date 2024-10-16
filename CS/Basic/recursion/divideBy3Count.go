package main

func divideBy3Count(n int32) int32 {
	if n < 3 {
		return 0
	}

	return divideBy3CountHelper(n, 0)
}

func divideBy3CountHelper(n int32, count int32) int32 {
	if n%3 != 0 {
		return count
	}

	return divideBy3CountHelper(n/3, count+1)
}
