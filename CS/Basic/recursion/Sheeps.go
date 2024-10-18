package main

import (
	// 	"fmt"
	"strconv"
)

func sheeps(count int32) string {

	if count == 1 {
		return formatSheep(int(count))
	}

	return sheeps(count-1) + formatSheep(int(count))
}

func formatSheep(count int) string {
	return strconv.Itoa(int(count)) + " sheep " + "~ "
}

// func main() {
// 	fmt.Println(sheeps(2))
// }
