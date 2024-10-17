package main

import (
	// "fmt"
)

func redirectionUrl(language string) string {
	switch language {
	case "English":
		return "www.example.org/en"
	case "Japanese":
		return "www.example.org/ja"
	case "Spanish":
		return "www.example.org/es"
	case "Russian":
		return "www.example.org/ru"
	default:
		return "www.example.org/"

	}
}

// func main() {
// 	fmt.Println(redirectionUrl("English"))
// }
