package main

// import (
// 	"fmt"
// )

func product(x int32, y int32) int32 {
	if x == 0 || y == 0 {
		return 0
	}

	if y < 0 {
		return product(x, y+1) - x
	}
	
	return product(x, y-1) + x
}

// func main() {
// 	fmt.Println(product(5, 3))
// }
