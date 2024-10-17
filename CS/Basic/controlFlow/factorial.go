package main

import "fmt"

func factorial(n int32) int64 {
	i := 1
	total := 1
	for i < int(n)+1 {
		total *= i
		i += 1
	}

	return int64(total)
}

func main() {
	fmt.Println(factorial(15))
}
