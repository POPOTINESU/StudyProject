package main

// import (
// 	"fmt"
// )

func doYouFail(s string) string {
	absenceCount := 0

	for i := 0; i < len(s); i += 1 {
		if string(s[i]) == "A" {
			absenceCount += 1
			if absenceCount == 3 {
				return "fail"
			}
		}
	}

	return "pass"
}

// func main() {
// 	fmt.Println(doYouFail("AAPPAP"))
// }
