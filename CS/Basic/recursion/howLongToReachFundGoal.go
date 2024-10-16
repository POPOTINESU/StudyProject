package main

func howLongToReachFundGoal(capitalMoney int32, goalMoney int32, interest int32) int32 {
	if capitalMoney >= goalMoney{
		return 0
	}
	return howLongToReachFundGoalHelper(0, float64(capitalMoney), float64(goalMoney), interest)
}

func howLongToReachFundGoalHelper(year int32, capitalMoney float64, goalMoney float64, interest int32) int32 {
	
	if capitalMoney >= goalMoney {
		return year
	}
	
	if year >= 80 {
		return 80
	}
	newCapitalMoney := calculateAmount(capitalMoney, interest)
	newGoalMoney := calculateGoalMoney(year, float64(goalMoney))

	return howLongToReachFundGoalHelper(year+1, newCapitalMoney, newGoalMoney, interest)
}

func calculateAmount(capitalMoney float64, interest int32) float64 {
	annalRate := 1 + (float64(interest) / 100)

	return capitalMoney * float64(annalRate)
}

func calculateGoalMoney(year int32, goalMoney float64) float64 {
	var annualRate float64

	if year%2 == 0 {
		annualRate = 1.02
	} else {
		annualRate = 1.03
	}

	return goalMoney * annualRate
}
