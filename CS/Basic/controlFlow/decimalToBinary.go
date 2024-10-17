package main

import (
	"fmt"
	"strconv"
)

func decimalToBinary(decNumber int32) string {
	decimalString := ""

	for decNumber > 0 {
		decimalString = strconv.Itoa(int(decNumber) % 2) + decimalString
		decNumber = decNumber / 2
	}

	if len(decimalString) == 0{
		return "0"
	}

	return decimalString
}

func main(){
	fmt.Println(decimalToBinary(2))
}