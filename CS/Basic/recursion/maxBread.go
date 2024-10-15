package main

// import (
// 	"fmt"
// )

func maxBread(money int32, price int32, sticker int32) int32 {
	bread := money / price

	return maxBreadHelper(sticker, bread, bread)
}

func maxBreadHelper(sticker int32, bread int32, holdSticker int32) int32 {

	if sticker > holdSticker {
		return bread
	}

	addBread := holdSticker / sticker
	consumeSticker := sticker * addBread

	return maxBreadHelper(sticker, bread+addBread, holdSticker-consumeSticker+addBread)
}

// func main() {
// 	fmt.Println(maxBread(10, 2, 3))
// }
