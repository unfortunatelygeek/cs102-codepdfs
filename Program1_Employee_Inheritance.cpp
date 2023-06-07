#include <iostream>
#include <string.h>
using namespace std;

class Employee 
{
protected:      // Protected Data Members because we want it to be accessible in the derived classes
    int emp_id;
    string name;
public:
    Employee(int id, string nm)     // Parametrized Constructor
    {
        emp_id = id;
        name = nm;
    }
    int getEmpId()          // Getter Function to get Employee ID
    {
        return emp_id;
    }
    string getName()       // Getter Function to get Employee Name
    {
        return name;
    }
};

class FullTimeEmployee : public Employee    // Inheriting Employee Class in FullTimeEmployee Class publicly
{
private:        // Private Data Members because we don't want it to be directly accessible outside of the class
    double basic_salary;
    double dearness_allowance;
    double hra;
public:
    FullTimeEmployee(int id, string nm, double bs, double da, double hr) : Employee(id, nm)  //Constructor for subclass FullTimeEmployee of Employee
    {
        basic_salary = bs;
        dearness_allowance = da;
        hra = hr;
    }
    double calculateSalary() 
    {
        return basic_salary + dearness_allowance + hra;
    }
};

class PartTimeEmployee : public Employee 
{
private:
    double rate_per_hour;
    int total_hours;
public:
    PartTimeEmployee(int id, string nm, double rph, int th) : Employee(id, nm) //Constructor for subclass PartTimeEmployee of Employee
    {
        rate_per_hour = rph;
        total_hours = th;
    }
    double calculateWages() 
    {
        return rate_per_hour * total_hours * 30;
    }
};

int main() 
{
    // Taking input from user for Full Time Employee
    int id, total_hours;
    double bs, da, hr, rate_per_hour;
    string employee_name;
    cout << "Enter Full Time Employee details:" << endl;
    cout << "Enter employee ID: ";
    cin >> id;
    cin.ignore();       // To ignore the newline character left in the buffer by the previous input statement
    cout << "Enter employee name: ";
    getline(cin, employee_name);        // To take input with spaces in between
    cout << "Enter basic salary: ";
    cin >> bs;
    cout << "Enter dearness allowance: ";
    cin >> da;
    cout << "Enter house rent allowance: ";
    cin >> hr;
    FullTimeEmployee fte(id, employee_name, bs, da, hr);

    // Taking input from user for Part Time Employee
    cout << "Enter Part Time Employee details:" << endl;
    cout << "Enter employee ID: ";
    cin >> id;
    cin.ignore();       // To ignore the newline character left in the buffer by the previous input statement
    cout << "Enter employee name: ";
    getline(cin, employee_name);
    cout << "Enter rate per hour: ";
    cin >> rate_per_hour;
    cout << "Enter total hours worked in a day: ";
    cin >> total_hours;
    PartTimeEmployee pte(id, employee_name, rate_per_hour, total_hours);

    //Printing Full Time Employee details
    cout << "Full Time Employee details:" << endl;
    cout << "ID: " << fte.getEmpId() << endl;
    cout << "Name: " << fte.getName() << endl;
    cout << "Salary: " << fte.calculateSalary() << endl;

    //Printing Part Time Employee details
    cout << "Part Time Employee details:" << endl;
    cout << "ID: " << pte.getEmpId() << endl;
    cout << "Name: " << pte.getName() << endl;
    cout << "Wages: " << pte.calculateWages() << endl;

    return 0;
}
