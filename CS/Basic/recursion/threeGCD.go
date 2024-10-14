package main

// import (
// 	"fmt"
// )

func threeGCD(x int32, y int32, z int32) int32 {
	return GCD(GCD(x, y), z)
}

func GCD(x int32, y int32) int32 {
	if y == 0 {
		return x
	}

	return GCD(y, x%y)
}

// func main() {
// 	fmt.Println(threeGCD(12, 18, 24))
// }
