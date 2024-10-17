package main

// import "fmt"

func factorial(n int32) int64 {
	// 今回forで繰り返す
	result := 1
	for i := 1; i <= int(n); i++ {
		result *= i
	}

	return int64(result)
}

// func main() {
// 	fmt.Println(factorial(15))
// }
