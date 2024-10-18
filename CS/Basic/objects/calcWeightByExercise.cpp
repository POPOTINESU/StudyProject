#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

using namespace std;

class Diet
{
private:
    static constexpr double NEED_FOR_LOSE_1KG = 7700.0;
    static constexpr double CALORIE_CONSTANT = 3.5;
    static constexpr double CALORIE_DIVISOR = 200.0;

    double totalDietHour;
    double consumedCalories;
    double weight;

public:
    Diet(double totalDietHour, double consumedCalories, double weight)
        : totalDietHour(totalDietHour), consumedCalories(consumedCalories), weight(weight) {}

    double calculateCaloriePerMinute(const string& exercise) const
    {
        int met = getMetValue(exercise);
        return met * CALORIE_CONSTANT * weight / CALORIE_DIVISOR;
    }

    double performExercise(const string& exercise, int minutes)
    {
        if (minutes <= 0)
            throw invalid_argument("Exercise duration must be greater than 0.");

        for (int minute = 0; minute < minutes; ++minute)
        {
            consumedCalories += calculateCaloriePerMinute(exercise);
        }

        totalDietHour += static_cast<double>(minutes) / 60.0;
        return calculateAndUpdateWeight();
    }

    double getWeight() const
    {
        return weight;
    }

private:
    int getMetValue(const string& exercise) const
    {
        if (exercise == "running")
            return 8;
        else if (exercise == "walking")
            return 3;
        else if (exercise == "tennis")
            return 5;
        else if (exercise == "rope jump")
            return 9;
        else
            throw invalid_argument("Unsupported exercise type: " + exercise);
    }

    double calculateAndUpdateWeight()
    {
        double loseWeight = consumedCalories / NEED_FOR_LOSE_1KG;
        weight = floor((weight - loseWeight) * 10) / 10;
        return weight;
    }
};

double calcWeightByExercise(const string& exercise, int minutes)
{
    Diet carly(0, 0, 85.5);
    return carly.performExercise(exercise, minutes);
}

int main()
{
    try
    {
        cout << calcWeightByExercise("running", 100) << endl;
        cout << calcWeightByExercise("walking", 150) << endl;
        cout << calcWeightByExercise("tennis", 120) << endl;
        cout << calcWeightByExercise("rope jump", 30) << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }
}