package main
// import (
//     "fmt"
// )
func commonPrefix(s1 string, s2 string) string {
	if  len(s1) == 0 || len(s2) == 0 || s1[0] != s2[0] {
		return ""
	}

	return string(s1[0]) + commonPrefix(s1[1:], s2[1:])
}

// func main(){
// 	fmt.Println(commonPrefix("aut","autenim"))
// }