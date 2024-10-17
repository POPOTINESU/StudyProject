package main

import "fmt"

func isPrime(number int32) bool {
	if number == 1 {
		return false
	}
	if number <= 3 {
		return true
	}

	for i := 2; i < int(number); i += 1 {
		if int(number)%i == 0 {
			return false
		}
	}

	return true
}

func main() {
	fmt.Println(isPrime(4))
}
