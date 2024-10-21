#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal
{
public:
    string species;
    double weightKg;
    double heightM;
    bool predator;

    Animal(string species, double weightKg, double heightM, double predator)
        : species(species), weightKg(weightKg), heightM(heightM), predator(predator) {}

    void domesticate()
    {
        this->predator = false;
    }
};

class Hunter
{
public:
    string name;
    double weightKg;
    double heightM;
    double strength;
    double cageCubicMeters;

    Hunter(string name, double weightKg, double heightM, double strength, double cageCubicMeters)
        : name(name), weightKg(weightKg), heightM(heightM), strength(strength), cageCubicMeters(cageCubicMeters) {}

    double strengthKg()
    {
        return this->weightKg * this->strength;
    }

    bool canCaptureAnimal(Animal *animal)
    {
        double hunterStrength = strengthKg();
        return hunterStrength >= animal->weightKg && this->cageCubicMeters >= animal->heightM && animal->predator;
    }

    bool attemptToDomesticate(Animal *animal)
    {
        double hunterStrength = strengthKg();
        if (hunterStrength > animal->weightKg * 2)
            animal->domesticate();

        return animal->predator;
    }
    void capturedAnimals(vector<Animal> animals)
    {
        vector<Animal> capturedAnimalList;
        for (int i = 0; i < animals.size(); i++)
        {
            Animal animal = animals[i];
            string animalSpecies = animal.species;
            if (!canCaptureAnimal(&animal))
                cout << animalSpecies << endl;
        }
    }

    vector<Animal> domesticateTheAnimals(vector<Animal> animals)
    {
        vector<Animal> notDomesticateAnimals;
        for (int i = 0; i < animals.size(); i++)
        {
            Animal animal = animals[i];
            string animalSpecies = animal.species;
            if (!attemptToDomesticate(&animal))
            {
                notDomesticateAnimals.push_back(animal);
            }
        }
        return notDomesticateAnimals;
    }
};

void entry()
{
    Animal tiger("Tiger", 290, 2.6, true);
    Animal cow("Cow", 1134, 1.5, false);
    Animal snake("Snake", 100, 1.2, true);
    Animal cat("Cat", 10, 0.5, false);
    vector<Animal> animals = {tiger, cow, snake, cat};
    Hunter hunternator("Hunternator", 124.73, 1.85, 15, 3);

    hunternator.capturedAnimals(animals);

    vector<Animal> notDomesticAnimals = hunternator.domesticateTheAnimals(animals);

    hunternator.capturedAnimals(notDomesticAnimals);
}

int main(){
    entry();
    return 0;
}