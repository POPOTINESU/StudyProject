package main

import (
	"fmt"
)

func reverseString(s string) string {
	if len(s) == 1 {
		return s
	}

	return string(s[len(s)-1]) + reverseString(s[0:len(s)-1])
}

func main() {
	// var n int32
	// fmt.Scan(&n)
	fmt.Println(reverseString("I am a software engineer"))
}
