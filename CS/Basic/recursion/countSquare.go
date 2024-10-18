package main

// import (
// 	"fmt"
// )

func countSquare(x int32, y int32) int32 {
	return calculateArea(x, y) / calculateArea(GCM(x, y), GCM(x, y))
}

func calculateArea(xSize int32, ySize int32) int32 {
	return xSize * ySize
}

func GCM(x int32, y int32) int32 {
	if y == 0 {
		return x
	}

	return GCM(y, x%y)
}

// func main() {
// 	fmt.Println(countSquare(28, 32))
// }
