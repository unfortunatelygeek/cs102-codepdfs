#include <iostream>
#include <string>
using namespace std;

class STUDENT // Base Class STUDENT
{
protected:
    int rollno;
    string name;
public:
    void get_data() // Function to get student data
    {
        cout << "Enter Roll No: ";
        cin >> rollno;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
    }
};

class EXAM : public STUDENT // Derived Class EXAM publicly inherited from Base Class STUDENT
{
protected:
    int marks[6];
public:
    void set_marks() // Function to set marks
    {
        cout << "Enter Marks of 6 Subjects: " << endl;
        for (int i = 0; i < 6; i++) 
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }
};

class RESULT : public EXAM // Derived Class RESULT publicly inherited from Derived Class EXAM
{
private:    // Private Data Members because we don't want it to be directly accessible outside of the class
    int totalmarks;
public:
    void calculate_total_marks()  // Function to calculate total marks
    {
        totalmarks = 0;
        for (int i = 0; i < 6; i++) 
        {
            totalmarks += marks[i];
        }
    }
    void display_result()        // Function to display result
    {
        cout << "Roll No: " << rollno << endl;
        cout << "Name: " << name << endl;
        for (int i = 0; i < 6; i++) {
            cout << "Subject " << i + 1 << " Marks: " << marks[i] << endl;
        }
        cout << "Total Marks: " << totalmarks << endl;
    }
};

int main() 
{
    RESULT r;
    r.get_data();
    r.set_marks();
    r.calculate_total_marks();
    r.display_result();
    return 0;
}
