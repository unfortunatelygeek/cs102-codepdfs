#include <iostream>

using namespace std;

class FibonacciSeries
{
    private:
        int num1, num2, num3, n;

    public:

    // Parameterized constructor
    FibonacciSeries(int count)
    {
        num1 = 0;
        num2 = 1;
        num3 = 0;
        n = count;
    }

    // Function to generate and display Fibonacci series
    void MakeFibonacci()
    {
        cout << "Fibonacci series: ";
        for (int i = 0; i < n; i++)
        {
            cout << num1 << " ";
            num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
        }
        cout << endl;
    }
};

int main()
{
    int count;
    cout << "Enter the number of terms in Fibonacci series: ";
    cin >> count;

    FibonacciSeries fib(count);

    fib.MakeFibonacci();

    return 0;
}
