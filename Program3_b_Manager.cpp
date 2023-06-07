#include <iostream>
#include <string>

using namespace std;

class Person 
{
protected:
    string name;
    string gender;
    int age;

public:
    void get_data() 
    {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Gender: ";
        getline(cin, gender);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore(); 
    }
};

class Worker : public Person 
{
protected:
    float base_salary;
    int shift;

public:
    void set_data() 
    {
        cout << "Enter Base Salary: ";
        cin >> base_salary;
        cout << "Enter Shift (in hours): ";
        cin >> shift;
        cin.ignore(); 
    }
};

class Manager : public Worker 
{
private:
    string dept;
    int num_people;
    float bonus;

public:
    void display_payment() 
    {
        cout << "Enter Department: ";
        cin.ignore();
        getline(cin, dept);
        cout << "Enter Number of People: ";
        cin >> num_people;
        cout << "Enter Bonus: ";
        cin >> bonus;

        float total_payment = (base_salary * shift) + (num_people * bonus);
        cout << "Total Payment: Rs." << total_payment << endl;
    }
};

int main() {
    Manager m;
    m.get_data();
    m.set_data();
    m.display_payment();
    return 0;
}
