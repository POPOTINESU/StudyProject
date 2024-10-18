package main

import (
	// "fmt"
	"strconv"
)

func fizzBuzz(n int32) string {
	answer := ""
	for i := 1; i <= int(n); i += 1 {
		if i%3 == 0 && i%5 == 0 {
			answer += "FizzBuzz" + "-"
		} else if i%3 == 0 {
			answer += "Fizz" + "-"
		} else if i%5 == 0 {
			answer += "Buzz" + "-"
		} else {
			answer += strconv.Itoa(int(i)) + "-"
		}
	}

	return answer[0 : len(answer)-1]
}

// func main(){
// 	fmt.Println(fizzBuzz(7))
// }
