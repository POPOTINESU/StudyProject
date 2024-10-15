package main

// import (
// 	"fmt"
// )

func recursiveIsPrime(n int32) bool{
    if n <= 1{
		return false
	}

	return !isDiv(n, n-1)

}


func isDiv(n int32, div int32) bool{
	if div == 1{
		return false
	}

	if n % div == 0{
		return true
	}

	return isDiv(n, div -1)
}



// func main(){
// 	fmt.Println(recursiveIsPrime(12))
// }