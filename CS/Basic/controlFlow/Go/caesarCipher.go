package main

import (
	// "fmt"
	"strings"
)

func caesarCipher(message string, n int32) string {
	st := strings.Join(strings.Fields(message), "")
	answer := ""

	for i := 0; i < len(st); i++ {
		char := st[i]

		if char >= 'a' && char <= 'z' {
			runeNum := rune(char) + rune(n%26)

			if runeNum > 'z' {
				runeNum -= 26
			}

			answer += string(runeNum)
		}
	}
	return answer
}

// func main() {
// 	fmt.Println(caesarCipher("it is during our darkest moments that we must focus to see the light", 5))
// }
