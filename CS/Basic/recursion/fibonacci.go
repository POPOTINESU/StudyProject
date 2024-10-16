package main

// func fibonacci(n int32) int32 {
// 	if n == 0 {
// 		return 0
// 	}
// 	if n == 1 {
// 		return 1
// 	}

// 	return fibonacci(n-1) + fibonacci(n-2)
// }
// 上記でも計算できるが計算量が多くなる

// 0 1 1 2 3 5(f1) 8(f2)
func fibonacciHelper(f1 int32, f2 int32, n int32) int32 {
	if n == 0 {
		return f1
	}

	return fibonacciHelper(f2, f1+f2, n-1)
}

func fibonacci(n int32) int32 {
	return fibonacciHelper(0, 1, n)
}
