package main

func fibonacciTotal(n int32) int32 {
	if n < 1 {
		return n
	}

	return fibonacciTotalHelper(0, 1, n, 0)
}

func fibonacciTotalHelper(f1 int32, f2 int32, n int32, total int32) int32 {
	if n < 1 {
		return total + f1
	}

	return fibonacciTotalHelper(f2, f1+f2, n-1, total+f1)
}
