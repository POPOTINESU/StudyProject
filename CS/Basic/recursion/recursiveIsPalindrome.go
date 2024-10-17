package main

import (
	// "fmt"
	"strings"
)

func recursiveIsPalindrome(s string) bool {

	newString := strings.ToLower(strings.ReplaceAll(s, " ", ""))

	rs := stringReverse(newString)

	return isRecursive(newString, rs)
}

func isRecursive(s string, rs string) bool {
	if len(s) == 0 {
		return true
	}

	if s[0] != rs[0] {
		return false
	}

	return isRecursive(s[1:], rs[1:])
}

func stringReverse(s string) string {
	rs := []rune(s)
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		rs[i], rs[j] = rs[j], rs[i]
	}

	return string(rs)
}


// func main(){
// 	fmt.Println(recursiveIsPalindrome("Top spot"))
// }