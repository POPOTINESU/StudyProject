package main

// import (
// 	"fmt"
// )

func screenViewMode(height int32, width int32) string {
	// Goだと三項演算子はない

	if height >= width {
		return "portrait"
	} else {
		return "landscape"
	}
}

// func main() {
// 	fmt.Println(screenViewMode(200, 150))
// }
