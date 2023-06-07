#include <iostream>
using namespace std;

class ComplexNumber
{
private:
    int real;
    int imag;

public:

    // First Constructor - Takes no argument
    ComplexNumber()
    {
        real = 0;
        imag = 0;
    }

    // Second Constructor - Takes one argument
    ComplexNumber(int value)
    {
        real = value;
        imag = 0;
    }

    // Third Constructor - Takes two arguments
    ComplexNumber(int realValue, int imagValue)
    {
        real = realValue;
        imag = imagValue;
    }

    /*What follows is an overloaded addition operator function for the ComplexNumber class.
    operator+ is the name of the overloaded addition operator.
    It specifies that this function will be called when the + operator is used on objects of the ComplexNumber class.*/
    ComplexNumber operator+(const ComplexNumber& other)
    {
        ComplexNumber sum;
        sum.real = real + other.real;
        sum.imag = imag + other.imag;
        return sum;
    }

    // Display the complex number
    void display()
    {
        cout << real << " + " << imag << "i" <<endl;
    }
};

int main()
{
    cout << "This program was brought to you by Aditi Rao. " << endl;
    int value, real_value, imaginary_value;

    // Constructor Overloading
    // First Constructor - Takes no argument
    ComplexNumber num1;
    cout << "Complex Number 1: " << endl;
    num1.display();

    // Second Constructor - Takes one argument
    cout << "Enter a value for Complex Number 2: ";
    cin >> value;
    ComplexNumber num2(value);
    cout << "Complex Number 2: " << endl;
    num2.display();

    // Third Constructor - Takes two arguments
    cout << "Enter real part for Complex Number 3: ";
    cin >> real_value;
    cout << "Enter imaginary part for Complex Number 3: ";
    cin >> imaginary_value;
    cout << "Complex Number 3: " << endl;
    ComplexNumber num3(real_value, imaginary_value);
    num3.display();

    // Addition of two complex numbers
    ComplexNumber num4 = num2 + num3;
    cout << "Sum of Complex Number 2 and 3:" << endl;
    num4.display();

    return 0;
}
