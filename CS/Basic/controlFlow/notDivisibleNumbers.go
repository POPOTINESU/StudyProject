package main

import (
	// "fmt"
	"strconv"
)

func notDivisibleNumbers(x int32, y int32) string {
	// 最後の文字から、-を引く
	// あまりがあった際に追加する

	answer := ""

	for i := 1; i <= int(x); i += 1 {
		mod := i % int(y)
		if mod != 0 {
			answer += strconv.Itoa(i) + "-"
		}
	}

	return answer[0 : len(answer)-1]
}

// func main(){
// 	fmt.Println(notDivisibleNumbers(20,3))
// }