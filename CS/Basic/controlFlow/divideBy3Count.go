package main

// import (
// 	"fmt"
// )

func divideBy3Count(n int32) int32 {
	divCount := 0

	for n%3 == 0 {
		divCount += 1
		n /= 3
	}

	return int32(divCount)
}

// func main() {
// 	fmt.Println(divideBy3Count(9))
// }
