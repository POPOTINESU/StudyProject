#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Animal
{
private:
    static double activityMultiplier;

    string name;
    double weightKg;
    double heightM;
    bool isPredator;
    double speedKph;

public:
    Animal(const string &name, const double weightKg, const double heightM, const double isPredator, const double speedKph)
        : name(name), weightKg(weightKg), heightM(heightM), isPredator(isPredator), speedKph(speedKph) {}

    double getBmi() const
    {
        return truncateTo2DecimalPlaces(weightKg / pow(heightM, 2));
    }

    double getDailyCalories() const
    {
        return truncateTo2DecimalPlaces(70 * pow(weightKg, 0.75) * activityMultiplier);
    }

    bool isDangerous() const
    {
        return isPredator || heightM >= 1.7 || speedKph >= 35;
    }

private:
    double truncateTo2DecimalPlaces(double decimalNumber) const
    {
        return floor(decimalNumber * 100) / 100;
    }
};

double Animal::activityMultiplier = 1.2;

void entry()
{
    Animal rabbit("rabbit", 10, 0.3, false, 20);
    cout << rabbit.getBmi() << endl;
    cout << rabbit.isDangerous() << endl;

    Animal snake("snake", 30, 1, true, 30);
    cout << snake.isDangerous() << endl;
    cout << snake.getDailyCalories() << endl;

    Animal elephant("elephant", 300, 3, false, 5);
    cout << elephant.getBmi() << endl;
    cout << elephant.getDailyCalories() << endl;

    Animal gazelle("gazelle", 50, 1.5, false, 100);
    cout << gazelle.getDailyCalories() << endl;
    cout << gazelle.isDangerous() << endl;
}

int main()
{
    entry();
    return 0;
}