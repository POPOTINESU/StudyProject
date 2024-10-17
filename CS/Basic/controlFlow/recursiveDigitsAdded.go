package main

// import (
//     "fmt"
// )

func recursiveDigitsAdded(digits int64) int32 {
    if digits < 10 {
        return int32(digits)
    }
    return int32(divideTotalNumber(digits, 0, 0))
}

func divideTotalNumber(digits int64, currentSum int64, accumulatedSum int64) int64 {
    if digits < 10 {
        currentSum += digits

        if currentSum < 10 {
            return accumulatedSum + currentSum
        }
        return divideTotalNumber(currentSum, 0, accumulatedSum+currentSum)
    }

    return divideTotalNumber(digits/10, currentSum+(digits%10), accumulatedSum)
}

// func main() {
// 	fmt.Println(recursiveDigitsAdded(40830291317656))
// }
