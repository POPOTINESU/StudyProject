package main

import (
	"fmt"
)

func factorial(n int32) int64 {
	i_64 := int64(n)

	if i_64 <= 1 {
		return 1
	}

	return factorial(int32(i_64)-1) * i_64
}

func main() {
	var n int32
	fmt.Scan(&n)
	fmt.Println(factorial(n))
}
