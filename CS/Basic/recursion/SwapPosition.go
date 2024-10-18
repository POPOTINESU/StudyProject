package main

// import(
// 	"fmt"
// )

func swapPosition(s string) string {
	if len(s) <= 1 {
		return s
	}

	if len(s) == 2 {
		return string(s[1]) + string(s[0])
	}

	return string(s[1]) + string(s[0]) + swapPosition(s[2:])
}

// func main() {
// 	fmt.Println(swapPosition("badce"))
// }
