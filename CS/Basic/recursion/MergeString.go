package main

// import (
// 	"fmt"
// )

func mergeString(s1 string, s2 string) string {
	if s1 == "" {
		return s2
	} else if s2 == "" {
		return s1
	}

	return string(s1[0]) + string(s2[0]) + mergeString(s1[1:], s2[1:])
}

// func main() {
// 	// var n int32
// 	// fmt.Scan(&n)
// 	fmt.Println(mergeString("abc", "def"))
// }
