package main

// import (
// 	"fmt"
// )

func simpleSummation(n int32) int32 {
	if n == 0 {
		return 0
	}
	return simpleSummation(n-1) + n
}

// func main() {
// 	var n int32
// 	fmt.Scan(&n)
// 	fmt.Println(simpleSummation(n))
// }
