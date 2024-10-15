package main

// import (
// 	"fmt"
// )

func multipleOfTwoTotal(n int32) int32 {
	if n == 0 {
		return 0
	}

	if n == 1 {
		return 2
	}

	return multipleOfTwoTotalHelper(n) + multipleOfTwoTotal(n-1)
}

func multipleOfTwoTotalHelper(n int32) int32 {
	if n == 1 {
		return 2
	}

	return multipleOfTwoTotalHelper(n-1) + 2*n
}

// func main() {
// 	fmt.Println(multipleOfTwoTotal(3))
// }
