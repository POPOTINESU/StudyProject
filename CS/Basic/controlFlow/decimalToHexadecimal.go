package main

import (
	// "fmt"
	"strconv"
)

func decimalToHexadecimal(decNumber int32) string {
	if decNumber < 16 {
		return convertDecimalToHexDecimal(decNumber)
	}

	HexDecimalString := ""
	for decNumber > 0 {
		HexDecimalString = convertDecimalToHexDecimal(decNumber % 16) + HexDecimalString
		decNumber /= 16
	}

	return HexDecimalString
}

func convertDecimalToHexDecimal(decimalNumber int32) string {
	switch decimalNumber {
	case 10:
		return "A"
	case 11:
		return "B"
	case 12:
		return "C"
	case 13:
		return "D"
	case 14:
		return "E"
	case 15:
		return "F"
	default:
		return strconv.Itoa(int(decimalNumber))
	}
}

// func main() {
// 	fmt.Println(decimalToHexadecimal(15))
// 	fmt.Println(decimalToHexadecimal(0))
// 	fmt.Println(decimalToHexadecimal(532454))
// }	
