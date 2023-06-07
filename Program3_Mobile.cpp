#include <iostream>
#include <string>

using namespace std;

class Mobile    // Base class Mobile
{
protected:
    string brand;

public:
    void setBrand(string b) 
    {
        brand = b;
    }
};

class Model : public Mobile // Derived class Model publicly inherited from Base class Mobile
{
protected:
    string model;
    int price;

public:
    void setModel(string m, int p) 
    {
        model = m;
        price = p;
    }
    int getPrice() 
    {
        return price;
    }
};

class Bill : public Model // Derived class Bill publicly inherited from Derived class Model
{
public:
    void printBill() 
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << getPrice() << endl;
    }
};

int main() 
{
    Bill b;
    string brand, model;
    int price;

    cout << "Enter brand: ";
    cin >> brand;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter price: ";
    cin >> price;

    b.setBrand(brand);
    b.setModel(model, price);

    b.printBill();

    return 0;
}
