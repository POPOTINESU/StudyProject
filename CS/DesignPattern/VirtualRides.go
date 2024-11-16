package main

import "fmt"

type Attraction interface {
	KidFriendliness() float32
	TeenFriendliness() float32
	AdultFriendliness() float32
	Scarriness() float32
	Thrill() float32
	Laughter() float32
	Sightseeing() float32
	Comfortableness() float32
}

type Friendliness struct {
	kidFriendlinessScore   float32
	teenFriendlinessScore  float32
	adultFriendlinessScore float32
	scarriness             float32
	thrill                 float32
	laughter               float32
	sightseeing            float32
	comfortableness        float32
}

func (f Friendliness) KidFriendliness() float32 {
	return f.kidFriendlinessScore
}

func (f Friendliness) TeenFriendliness() float32 {
	return f.teenFriendlinessScore
}

func (f Friendliness) AdultFriendliness() float32 {
	return f.adultFriendlinessScore
}

func (f Friendliness) Scarriness() float32 {
	return f.scarriness
}

func (f Friendliness) Thrill() float32 {
	return f.thrill
}

func (f Friendliness) Laughter() float32 {
	return f.laughter
}

func (f Friendliness) Sightseeing() float32 {
	return f.sightseeing
}

func (f Friendliness) Comfortableness() float32 {
	return f.comfortableness
}

func main() {
	ride := Friendliness{
		kidFriendlinessScore:   8.5,
		teenFriendlinessScore:  6.3,
		adultFriendlinessScore: 7.0,
		scarriness:             5.0,
		thrill:                 9.0,
		laughter:               8.2,
		sightseeing:            6.0,
		comfortableness:        7.5,
	}

	var attraction Attraction = ride

	fmt.Println("Kid Friendliness:", attraction.KidFriendliness())
	fmt.Println("Teen Friendliness:", attraction.TeenFriendliness())
	fmt.Println("Adult Friendliness:", attraction.AdultFriendliness())
	fmt.Println("Scarriness:", attraction.Scarriness())
	fmt.Println("Thrill:", attraction.Thrill())
	fmt.Println("Laughter:", attraction.Laughter())
	fmt.Println("Sightseeing:", attraction.Sightseeing())
	fmt.Println("Comfortableness:", attraction.Comfortableness())
}