#include <iostream>
using namespace std;

class Vehicle
{
    public:
        int wheels;
        int engineCapacity;

    public:

        Vehicle(): wheels(0), engineCapacity(0) {}
        Vehicle(int wheels, int engineCapacity): wheels(wheels), engineCapacity(engineCapacity) {}
        virtual void specs() = 0;
        virtual void display_stats() = 0;
        virtual ~Vehicle() {}
};

class LMV : public Vehicle
{
    protected:
        int speed;
        int mileage;
        float rpm;
    
    public:
        LMV(): speed(0), mileage(0), rpm(0.0) {}
        void specs()
        {
            cout << "Enter the number of wheels: ";
            cin >> wheels;
            cout << "Enter the engine capacity: ";
            cin >> engineCapacity;
            cout << "Enter the speed: ";
            cin >> speed;
            cout << "Enter the mileage: ";
            cin >> mileage;
            cout << "Enter the RPM: ";
            cin >> rpm;
        }

        void display_stats()
        {
            cout << "Number of wheels: " << wheels << endl;
            cout << "Engine capacity: " << engineCapacity << endl;
            cout << "Speed: " << speed << endl;
            cout << "Mileage: " << mileage << endl;
            cout << "RPM: " << rpm << endl;
        }

        ~LMV() {}
};

class HMV : public Vehicle
{
    protected:
        int speed;
        int mileage;
        float rpm;
    
    public:
        HMV(): speed(0), mileage(0), rpm(0.0) {}
        void specs()
        {
            cout << "Enter the number of wheels: ";
            cin >> wheels;
            cout << "Enter the engine capacity: ";
            cin >> engineCapacity;
            cout << "Enter the speed: ";
            cin >> speed;
            cout << "Enter the mileage: ";
            cin >> mileage;
            cout << "Enter the RPM: ";
            cin >> rpm;
        }

        void display_stats()
        {
            cout << "Number of wheels: " << wheels << endl;
            cout << "Engine capacity: " << engineCapacity << endl;
            cout << "Speed: " << speed << endl;
            cout << "Mileage: " << mileage << endl;
            cout << "RPM: " << rpm << endl;
        }

        ~HMV() {}
};

class TW : public Vehicle
{
    protected:
        int speed;
        int mileage;
        float rpm;
    
    public:

        TW(): speed(0), mileage(0), rpm(0.0) {}
        void specs()
        {
            cout << "Enter the number of wheels: ";
            cin >> wheels;
            cout << "Enter the engine capacity: ";
            cin >> engineCapacity;
            cout << "Enter the speed: ";
            cin >> speed;
            cout << "Enter the mileage: ";
            cin >> mileage;
            cout << "Enter the RPM: ";
            cin >> rpm;
        }

        void display_stats()
        {
            cout << "Number of wheels: " << wheels << endl;
            cout << "Engine capacity: " << engineCapacity << endl;
            cout << "Speed: " << speed << endl;
            cout << "Mileage: " << mileage << endl;
            cout << "RPM: " << rpm << endl;
        }

        ~TW() {}
};


int main()
{
    Vehicle *vehicles[3];
    vehicles[0] = new LMV();
    vehicles[1] = new HMV();
    vehicles[2] = new TW();

    for (int i = 0; i < 3; i++)
    {
        vehicles[i]->specs();

        if (vehicles[i]->wheels == 2)
        {
            TW *tw = dynamic_cast<TW*>(vehicles[i]);
            if (tw)
            {
                tw->display_stats();
            }
        }
        else
        {
            vehicles[i]->display_stats();
        }
    }

    for (int i = 0; i < 3; i++)
    {
        delete vehicles[i];
    }

    return 0;
}
