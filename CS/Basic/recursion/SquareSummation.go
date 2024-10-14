package main

import (
	// "fmt"
	"math"
)

func squareSummation(n int32) int32 {
	if n <= 1 {
		return 1
	}

	return squareSummation(n-1) + int32(math.Pow(float64(n), 2))
}

// func main() {
// 	var n int32
// 	fmt.Scan(&n)
// 	fmt.Println(squareSummation(n))
// }
