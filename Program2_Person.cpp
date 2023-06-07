#include <iostream>
#include <string>
using namespace std;

class person 
{
protected:
    int phone_number;
    string name;

public:
    void read() 
    {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter phone number: ";
        cin >> phone_number;
        cin.ignore();
    }

    void show() 
    {
        cout << "Name: " << name << endl;
        cout << "Phone number: " << phone_number << endl;
    }
};

class student : public person 
{
private:
    int roll_number;
    string course;

public:
    void read() 
    {
        person::read();
        cout << "Enter roll number: ";
        cin >> roll_number;
        cin.ignore(); // Ignore the newline character
        cout << "Enter course: ";
        getline(cin, course);
    }

    void show() 
    {
        person::show();
        cout << "Roll number: " << roll_number << endl;
        cout << "Course: " << course << endl;
    }
};

int main() 
{
    student s;
    s.read();
    s.show();
    return 0;
}
