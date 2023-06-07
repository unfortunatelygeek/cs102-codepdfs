#include <iostream>
using namespace std;

const double LITRES_PER_GALLON = 0.264179;  //A constant value that will not change

double milesPerGallon(double litres, double miles) {
    double gallons = 0;
    gallons += (litres / LITRES_PER_GALLON);
    double miles_per_gallon = 0;
    miles_per_gallon += (miles / gallons);
    return miles_per_gallon;
}

int main() {
    double litres, miles;
    char repeat;

    do {
        cout << "Enter the number of litres of gasoline consumed: ";
        cin >> litres;
        cout << "Enter the number of miles traveled: ";
        cin >> miles;

        double miles_per_gallon = milesPerGallon(litres, miles);
        cout << "The car delivered " << miles_per_gallon << " miles per gallon." << endl;

        cout << "Do you want to calculate again? (Y/N): ";
        cin >> repeat;
        cout << endl;
    } 
    while (repeat == 'Y' || repeat == 'y');
    return 0;
}
