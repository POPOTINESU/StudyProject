package main

// import "fmt"

func oneComplement(bits string) string {
	// 1の補数自体は、単純に文字を反転させるだけ
	oneComplementString := ""
	for i := 0; i < len(bits); i += 1 {
		if string(bits[i]) == "0" {
			oneComplementString += "1"
		} else {
			oneComplementString += "0"
		}
	}

	return oneComplementString
}

// func main() {
// 	fmt.Println(oneComplement("0"))
// 	fmt.Println(oneComplement("1"))
// 	fmt.Println(oneComplement("101"))
// }
