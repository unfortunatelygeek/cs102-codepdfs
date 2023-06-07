#include <iostream>
#include <cmath>

using namespace std;

class Power
{
public:
    int raisePower(int a, int b)
    {
        return pow(a, b);
    }


    double raisePower(double a, int b = 2)
    {
        return pow(a, b);
    }
};

int main()
{
    Power obj_pow;

    // Testing the function with integer arguments
    cout << "2 raised to the power of 3: " << obj_pow.raisePower(2, 3) << endl;

    // Testing the function with double and integer arguments
    cout << "2.5 raised to the power of 2: " << obj_pow.raisePower(2.5) << endl;
    cout << "2.5 raised to the power of 3: " << obj_pow.raisePower(2.5, 3) << endl;

    return 0;
}
