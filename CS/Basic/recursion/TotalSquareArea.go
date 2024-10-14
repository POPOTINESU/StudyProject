package main

// import (
// 	"fmt"
// )

func totalSquareArea(x int32) int32 {
	if x == 0 {
		return 0
	}

	return totalSquareArea(x-1) + int32(calculateSquareArea(int(x))) * x
}

func calculateSquareArea(side int) int {
	return side * side
}

// func main() {
// 	fmt.Println(totalSquareArea(3))
// }
