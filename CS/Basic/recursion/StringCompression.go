package main

import (
	// "fmt"
	"strconv"
)

func stringCompression(s string) string {
	// 長さが0になるまで減らす
	if len(s) == 0 {
		return ""
	}
	count := stringCount(s[0], s[1:], 1)

	if count == 1 {
		return string(s[0]) + stringCompression(s[1:])
	} else {
		return string(s[0]) + strconv.Itoa(count) + stringCompression(s[count:])
	}
}

func stringCount(target byte, s string, count int) int {
	if len(s) == 0 || target != s[0] {
		return count
	}

	return stringCount(target, s[1:], count+1)
}

// func main() {
// 	fmt.Println(stringCompression("aaabbb"))
// }
