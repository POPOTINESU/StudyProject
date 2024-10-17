package main

import (
	"fmt"
	"strconv"
)

func isPalindromeInteger(n int32) bool {
	nString := strconv.Itoa(int(n))
	loopCount := len(nString)/2
	for i := 0; i < int(loopCount); i++ {
		if nString[i] != nString[len(nString)-i-1] {
			return false
		}
	}

	return true
}

func main() {
	fmt.Println(isPalindromeInteger(121))
}
