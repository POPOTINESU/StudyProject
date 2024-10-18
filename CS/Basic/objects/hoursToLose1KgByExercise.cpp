#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Diet
{
public:
    static double NEED_FOR_LOSE_1KG;

    double totalDietHour;
    double consumedCalories;
    double weight;

public:
    Diet(double weight, double totalDietHour, double consumedCalories)
    {
        this->totalDietHour = totalDietHour;
        this->weight = weight;
        this->consumedCalories = consumedCalories;
    }

    double calculateHoursToLose1KgByExercise(string exercise)
    {
        int met;
        if (exercise == "running")
            met = 8;
        if (exercise == "walking")
            met = 3;
        if (exercise == "tennis")
            met = 5;
        if (exercise == "rope jump")
            met = 9;

        int totalMinutes = 0;
        while (consumedCalories < NEED_FOR_LOSE_1KG)
        {
            consumedCalories += calculateCalPerMinutes(met);
            totalMinutes += 1;
        }

        totalDietHour = convertMinuteToHour(totalMinutes);

        return totalDietHour;
    }

private:
    double convertMinuteToHour(int minute)
    {   
        // 小数の丸め込みによっての誤差をなくすため
        return floor(double(minute) / (60.0+ 0.00001) * 10.0) / 10.0;
    }

    double calculateCalPerMinutes(int met)
    {
        return met * 3.5 * weight / 200.0;
    }
};
double Diet::NEED_FOR_LOSE_1KG = 7700.0;

double hoursToLose1KgByExercise(string exercise)
{
    // 体重が85.5kgからスタート
    Diet carly = Diet(85.5, 0, 0);

    return carly.calculateHoursToLose1KgByExercise(exercise);
}

int main()
{
    cout << hoursToLose1KgByExercise("walking") << endl;
}