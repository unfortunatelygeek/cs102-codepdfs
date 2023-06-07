#include <iostream>
using namespace std;

class Product
{
protected:
    string barcode;
    string nameProduct;

public:
    Product() : barcode(""), nameProduct("") {}
    Product(string barcode, string nameProduct) : barcode(barcode), nameProduct(nameProduct) {}

    string getBarcode()
    {
        return barcode;
    }

    string getNameProduct()
    {
        return nameProduct;
    }

    virtual void scanner() = 0;  /*Pure virtual function. Error when not written: undefined reference to `vtable for Product'
                                    collect2.exe: error: ld returned 1 exit status*/ 
    virtual void printer() = 0;
};

class PrepackedFood : public Product
{
protected:
    double unitPrice;

public:
    // PrepackedFood() : Product("", ""), unitPrice(0) {}
    PrepackedFood(string barcode, string name, double unitPrice) : Product(barcode, name), unitPrice(unitPrice) {}

    void scanner()
    {
        cout << "Scanning Prepacked Food: " << nameProduct << " (Barcode: " << barcode << ")" << endl;
        cout << "Unit Price: " << unitPrice << "Rs." << endl;
    }

    void printer()
    {
        cout << "Your Order Item: " << nameProduct << " (Barcode: " << barcode << ")" << endl;
        cout << "Unit Price: " << unitPrice << "Rs." << endl;
    }
};

class FreshFood : public Product
{
protected:
    double weight;
    double pricePerKg;

public:
    // FreshFood() : Product("", ""), weight(0), pricePerKg(0) {}
    FreshFood(string barcode, string name, double weight, double pricePerKg) : Product(barcode, name), weight(weight), pricePerKg(pricePerKg) {}

    void scanner()
    {
        cout << "Scanning Fresh Food: " << nameProduct << " (Barcode: " << barcode << ")" << endl;
        cout << "Weight: " << weight << "kg" << endl;
        cout << "Price per Kg: " << pricePerKg << "Rs." << endl;
    }

    void printer()
    {
        double totalPrice = weight * pricePerKg;
        cout << "Your Order Item: " << nameProduct << " (Barcode: " << barcode << ")" << endl;
        cout << "Weight: " << weight << "g" << endl;
        cout << "Total Price: " << totalPrice << "Rs." << endl;
    }
};

int main()
{
    Product *productObj;

    productObj = new PrepackedFood("123456789", "Shin Ramen", 40);
    productObj->scanner();
    productObj->printer();

    productObj = new FreshFood("987654321", "Mushrooms", 0.25, 230);
    productObj->scanner();
    productObj->printer();

    return 0;
}
