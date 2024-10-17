package main

import (
	"fmt"
	"strconv"
)

func perfectNumberList(n int32) string {
	answer := ""
	for i := 1; i <= int(n); i += 1 {
		if isPerfectNumber(int32(i)) {
			answer += strconv.Itoa(i) + "-"
		}
	}


	return answer[0: len(answer)-1]
}

func isPerfectNumber(n int32) bool {

	perfectNumber := 0

	for i := 1; i <= int(n); i++ {
		if int(n)%i == 0 {
			perfectNumber += i
		}
	}

	return perfectNumber == int(n)
}

func main() {
	fmt.Println(perfectNumberList(1000))
}
