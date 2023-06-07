#include <iostream>
#include <math.h>
using namespace std;

class Logarithm 
{
public:
    virtual double calcLog(double number) = 0;
};

class Log10 : public Logarithm 
{
public:
    double calcLog(double number) 
    {
        return log10(number);
    }
};

class LogE : public Logarithm 
{
public:
    double calcLog(double number) 
    {
        return log(number);
    }
};

class Log2 : public Logarithm 
{
public:
    double calcLog(double number) 
    {
        return log2(number);
    }
};

int main() 
{
    double number = 100.0;

    Logarithm* logObj;

    logObj = new Log10();
    double result1 = logObj->calcLog(number);
    cout << "Log10(" << number << ") = " << result1 << endl;

    logObj = new LogE();
    double result2 = logObj->calcLog(number);
    cout << "LogE(" << number << ") = " << result2 << endl;

    logObj = new Log2();
    double result3 = logObj->calcLog(number);
    cout << "Log2(" << number << ") = " << result3 << endl;

    return 0;
}
