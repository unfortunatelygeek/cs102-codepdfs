#include <iostream>
using namespace std;

const double LITRES_PER_GALLON = 0.264179;  

class Car {
private:
    double litres;
    double miles;

public:
    void setFuelConsumption(double litres) {
        this->litres = litres;
    }

    void setMileage(double miles) {
        this->miles = miles;
    }

    double calculateMilesPerGallon() {
        double gallons = litres / LITRES_PER_GALLON;
        double miles_per_gallon = miles / gallons;
        return miles_per_gallon;
    }
};

int main() {
    Car car;
    char repeat;

    do {
        double litres, miles;

        cout << "Enter the number of litres of gasoline consumed: ";
        cin >> litres;
        car.setFuelConsumption(litres);

        cout << "Enter the number of miles traveled: ";
        cin >> miles;
        car.setMileage(miles);

        double miles_per_gallon = car.calculateMilesPerGallon();
        cout << "The car delivered " << miles_per_gallon << " miles per gallon." << endl;

        cout << "Do you want to calculate again? (Y/N): ";
        cin >> repeat;
        cout << endl;
    } 
    while (repeat == 'Y' || repeat == 'y');

    return 0;
}
