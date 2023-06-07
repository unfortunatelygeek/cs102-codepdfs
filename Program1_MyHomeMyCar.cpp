#include <iostream>
#include <string>

using namespace std;

class Home 
{
private:
    int num_rooms;
    double size_sqm;

public:
    Home(int num_rooms = 0, double size_sqm = 0.0) //Constructor
    {
        this->num_rooms = num_rooms;
        this->size_sqm = size_sqm;
    }

    int getNumRooms() const 
    {
        return num_rooms;
    }

    void setNumRooms(int num_rooms) 
    {
        this->num_rooms = num_rooms;
    }

    double getSizeSqM() const 
    {
        return size_sqm;
    }

    void setSizeSqM(double size_sqm) 
    {
        this->size_sqm = size_sqm;
    }

    void display() const 
    {
        cout << "Number of rooms: " << num_rooms << endl;
        cout << "Size in square meters: " << size_sqm << endl;
    }
};

class Car 
{
private:
    string car_number;
    int seating_capacity;
    string model_name;

public:
    Car() 
    {
        car_number = "";
        seating_capacity = 0;
        model_name = "";
    }

    Car(string car_number, int seating_capacity, string model_name) 
    {
        this->car_number = car_number;
        this->seating_capacity = seating_capacity;
        this->model_name = model_name;
    }

    string getCarNumber() const 
    {
        return car_number;
    }

    void setCarNumber(string car_number) 
    {
        this->car_number = car_number;
    }

    int getSeatingCapacity() const 
    {
        return seating_capacity;
    }

    void setSeatingCapacity(int seating_capacity) 
    {
        this->seating_capacity = seating_capacity;
    }

    string getModelName() const 
    {
        return model_name;
    }
    void setModelName(string model_name) 
    {
        this->model_name = model_name;
    }

    void display() const 
    {
        cout << "Car number: " << car_number << endl;
        cout << "Seating capacity: " << seating_capacity << endl;
        cout << "Model name: " << model_name << endl;
    }
};

class MotorHome : public Car, public Home 
{
public:
    enum CATEGORY {LUXURY, FIRST_CLASS, MIDDLE_CLASS, ECONOMY};
    CATEGORY category;

public:
    MotorHome(int num_rooms = 0, double size_sqm = 0.0, string car_number = "", int seating_capacity = 0, string model_name = "", CATEGORY category = ECONOMY) 
        : Car(car_number, seating_capacity, model_name), Home(num_rooms, size_sqm) 
    {
        this->category = category;
    }

    void setCategory(CATEGORY category) 
    {
        this->category = category;
    }

    string getCategory() const 
    {
        switch(category) 
        {
            case LUXURY:
                return "Luxury";
            case FIRST_CLASS:
                return "First Class";
            case MIDDLE_CLASS:
                return "Middle Class";
            case ECONOMY:
                return "Economy";
            default:
                return "";
        }
    }

    void display() const 
    {
        Car::display();
        Home::display();
        cout << "Category: " << getCategory() << endl;
    }
};

int main() 
{
    int choice;
    MotorHome myMotorHome;
    int numRooms;
    double size;
    string carNumber;
    int seatingCapacity;
    string modelName;
    int category;

    do 
    {
        cout << "Hello, welcome to the Motor Home Configuration System!" << endl;
        cout << "Please choose from the following options:" << endl;
        cout << "1. Set number of rooms" << endl;
        cout << "2. Set size in square meters" << endl;
        cout << "3. Set car number" << endl;
        cout << "4. Set seating capacity" << endl;
        cout << "5. Set model name" << endl;
        cout << "6. Set category" << endl;
        cout << "7. Display details" << endl;
        cout << "8. Quit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) 
        {
            case 1:
                cout << "Enter number of rooms: ";
                cin >> numRooms;
                myMotorHome.setNumRooms(numRooms);
                break;

            case 2:
                cout << "Enter size in square meters: ";
                cin >> size;
                myMotorHome.setSizeSqM(size);
                break;

            case 3:
                cout << "Enter car number: ";
                cin >> carNumber;
                myMotorHome.setCarNumber(carNumber);
                break;

            case 4:
                cout << "Enter seating capacity: ";
                cin >> seatingCapacity;
                myMotorHome.setSeatingCapacity(seatingCapacity);
                break;

            case 5:
                cout << "Enter model name: ";
                cin >> modelName;
                myMotorHome.setModelName(modelName);
                break;

            case 6:
                cout << "Choose category:" << endl;
                cout << "1. Luxury" << endl;
                cout << "2. First Class" << endl;
                cout << "3. Middle Class" << endl;
                cout << "4. Economy" << endl;
                cin >> category;
                switch(category) 
                {
                    case 1:
                        myMotorHome.setCategory(MotorHome::LUXURY);
                        break;
                    case 2:
                        myMotorHome.setCategory(MotorHome::FIRST_CLASS);
                        break;
                    case 3:
                        myMotorHome.setCategory(MotorHome::MIDDLE_CLASS);
                        break;
                    case 4:
                        myMotorHome.setCategory(MotorHome::ECONOMY);
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                }
                break;

            case 7:
                myMotorHome.display();
                break;

            case 8:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } 
    while(choice != 8);
cout << "Thank you for using the Motor Home Configuration System!" << endl;
return 0;
}