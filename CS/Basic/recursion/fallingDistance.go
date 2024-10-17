package main

import (
	"fmt"
	"math"
)

func fallingDistance(planet string, time int32) int32 {
	return int32(convertMeterToMile(calculateFallingDistance(planet, time)))
}

func calculateFallingDistance(planet string, time int32) float64 {
	return 0.5 * gravitySpeed(planet) * math.Pow(float64(time), 2.0)
}

func convertMeterToMile(meter float64) float64 {
	MIRE_PER_METER := 0.000621371

	return meter * MIRE_PER_METER
}

func gravitySpeed(planet string) float64 {
	switch planet {
	case "Earth":
		return 9.8
	case "Jupiter":
		return 24.79
	case "Mercury":
		return 3.7
	default:
		return 0
	}
}

func main() {
	fmt.Println(fallingDistance("Earth", 5000))
}
