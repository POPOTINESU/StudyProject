package main

import (
	"fmt"
)

func countDivisibleByK(n int32, k int32) int32 {
	if n%k != 0 {
		return 0
	}

	return countDivisibleByK(n/k, k) + 1
}

func main() {
	fmt.Println(countDivisibleByK(1024, 2))
}
