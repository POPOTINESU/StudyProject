package main

import (
	"strconv"
)

func divisor(number int32) string {
	if number == 1 {
		return "1"
	}
	return divisorHelper(number, number)
}

func divisorHelper(number int32, count int32) string {
	if count == 1{
		return strconv.Itoa(int(number))
	}
	if number % count == 0 {
		return strconv.Itoa(int(number / count)) + "-" + divisorHelper(number, count-1)
	}

	return divisorHelper(number, count-1)
}
