#include <iostream>
#include <string>
#include <algorithm> // for std::sort
using namespace std;

class Employee
{
	private:
    		string name;
    		int age;
    		double salary;

	public:

    //Default Constructor
    Employee()
            {
        		name = "unknown";
        		age = 18;
        		salary = 20000;
    		}

    // Parameterized constructor
    Employee(string n, int a, double s)
    {
        name = n;
        age = a;
        salary = s;
    }

    // Setter methods
    void setName(string n)
    {
        name = n;
    }

    void setAge(int a)
    {
        age = a;
    }

    void setSalary(double s)
    {
        salary = s;
    }

    // Getter methods
    string getName()
	{
        return name;
    }

    int getAge()
	{
        return age;
    }

    double getSalary()
	{
        return salary;
    }

    // Method to print Employee details
    void printDetails()
	{
        cout << "Name: " << name << ", Age: " << age << ", Salary: $" << salary << endl;
    }
};

void Sort(Employee arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].getAge() > arr[j + 1].getAge())
            {
                Employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main()
{

    Employee employees[10];

    //Using the Setter Method
    employees[0].setName("Adonis");
    employees[0].setAge(30);
    employees[0].setSalary(50000);

    //Using the Parameterized Constructor method
    employees[1] = Employee("Venus", 25, 90000);

    for (int i = 2; i < 10; i++)
    {
        cout << "Enter details for Employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.ignore();
        string name;
        getline(cin, name);
        employees[i].setName(name);

        cout << "Age: ";
        int age;
        cin >> age;
        employees[i].setAge(age);

        cout << "Salary: ";
        double salary;
        cin >> salary;
        employees[i].setSalary(salary);
    }

    //Sorting the employees by age by bubble sort technique.
    Sort(employees, 10);

    // Print details of 10 employees sorted by age
    cout << "Employees sorted by age:" << endl;
    for (int i = 0; i < 10; i++)
    {
        employees[i].printDetails();
    }

    return 0;
}

