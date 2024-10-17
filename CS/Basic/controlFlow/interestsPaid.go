package main

// import "fmt"

func interestsPaid(initialLoan int32, didPayOnTime bool) float64 {
	commission := 2.5
	return float64(initialLoan)*(1+calculateInterest(didPayOnTime)) + commission
}

func calculateInterest(didPayOnTime bool) float64 {
	if didPayOnTime {
		return 0.02
	} else {
		return 0.15
	}
}

// func main() {
// 	fmt.Println(interestsPaid(100, true))
// }
