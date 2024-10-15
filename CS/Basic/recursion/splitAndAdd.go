package main

import (
	"fmt"
)

func splitAndAdd(digits int32) int32 {
	if (digits < 10){
		return digits
	}

	return digits % 10 + splitAndAdd(digits/10)
}

func main() {
	fmt.Println(splitAndAdd(19))
}
