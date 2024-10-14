package main
// import (
//     "fmt"
// )

func numberOfDots(x int32) int32{
	if x == 0 {
		return 0
	}

    return numberOfDots(x-1) + x
}

// func main(){
// 	fmt.Println(numberOfDots(10))
// }