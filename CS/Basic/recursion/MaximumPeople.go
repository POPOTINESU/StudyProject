package main

// import (
// 	"fmt"
// )

func maximumPeople(x int32, y int32) int32 {
	if y == 0 {
		return x
	}

	return maximumPeople(y, x%y)
}

// func main() {
// 	fmt.Println(maximumPeople(12, 18))
// }
