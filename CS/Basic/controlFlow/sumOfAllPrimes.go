package main

// import "fmt"

func sumOfAllPrimes(n int32) int32 {
	benefits := 0
	for i := 1; i <= int(n); i +=1{
		if isPrimeYear(int32(i)) {
			benefits += i
		}
	}


	return int32(benefits)
}

func isPrimeYear(year int32) bool {
	if year == 1 {
		return false
	}
	if year <= 3 {
		return true
	}

	for i := 2; i < int(year); i += 1 {
		if year%int32(i) == 0 {
			return false
		}
	}
	return true
}

// func main() {
// 	fmt.Println(sumOfAllPrimes(1000))
// }