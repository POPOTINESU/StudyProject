package main

// import (
// 	"fmt"
// )

func hammingDistanceInString(string1 string, string2 string) int32 {
	// 文字の数が同じである前提
	if len(string1) != len(string2) {
		return 0
	}
	if len(string1) == 0{
		return 0
	}

	var count int32

	for i := 0; i < len(string1); i++ {
		if string1[i] != string2[i] {
			count += 1
		}
	}

	return count
}

// func main() {
// 	fmt.Println(hammingDistanceInString("toned", "roses"))
// }
