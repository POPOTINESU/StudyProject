package main

import (
	// "fmt"
	"strconv"
)

// func main() {
// 	fmt.Println(irreducibleFraction(12, 24))
// }

func irreducibleFraction(x int32, y int32) string {
	if y == 0 {
		panic("Error: Division by zero")
	}

	gcd := calculateGCD(x, y)

	top := x / gcd
	bottom := y / gcd

	if bottom == 1 {
		return strconv.Itoa(int(top))
	}

	return strconv.Itoa(int(top)) + "/" + strconv.Itoa(int(bottom))
}

func calculateGCD(x int32, y int32) int32 {
	if y == 0 {
		return x
	}

	return calculateGCD(y, x%y)
}
