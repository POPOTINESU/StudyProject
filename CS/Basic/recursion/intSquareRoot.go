package main

import (
	// "fmt"
	"math"
)

func intSquareRoot(n int32) int32 {
	return int32(square(float64(n), 1))
}

func square(target float64, guess float64) float64 {
	newGuess := (guess + target/guess) / 2

	if isSquareRootCloseEnough(guess, newGuess) {
		return newGuess
	}

	return square(target, newGuess)
}

func isSquareRootCloseEnough(guess float64, newGuess float64) bool {
	return 100*math.Abs((guess-newGuess)/newGuess) < 0.001
}

// func main() {
// 	fmt.Println(intSquareRoot(12))
// }
