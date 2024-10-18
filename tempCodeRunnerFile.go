package main

import (
	"fmt"
)

func fibonacci(n int32) int32 {
	// 0, 1, 1, 2, 3, 5

	if n < 2 {
		return n
	}

	f1 := 0
	f2 := 1
	prev_f1 := 0

	for i := 0; i < int(n); i++ {
		prev_f1 = f1
		f1 = f2
		f2 += prev_f1
	}

	return int32(f1)
}

func main() {
	fmt.Println(fibonacci(5))
}
