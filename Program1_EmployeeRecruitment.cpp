#include <iostream>
using namespace std;
class Posting
{
private:
    int courseWork;
    int AptTest;
    int TechTest;
    int interview;

public:
    Posting() : courseWork(0), AptTest(0), TechTest(0), interview(0){}
    Posting(int courseWork, int AptTest, int TechTest, int interview) //Parameterized constructor for a Programmer
    {
        this->courseWork = courseWork;
        this->AptTest = AptTest;
        this->TechTest = TechTest;
        this->interview = interview;
    }
    Posting(int TechTest,int interview) //Parameterized constructor for a Team Leader
    {
        this->courseWork = 0;
        this->AptTest = 0;
        this->TechTest = TechTest;
        this->interview = interview;
    }
    explicit Posting(int interview) //Parameterized constructor for a Project Manager
    {
        this->courseWork = 0;
        this->AptTest = 0;
        this->TechTest = 0;
        this->interview = interview;
    }
    void displayPost(int choice)
    {
        int totalMarks = courseWork + AptTest + TechTest + interview;
        if (totalMarks >= 80 && courseWork >= 0 && AptTest >= 0 && TechTest >= 0 && interview >= 0)
        {
            if (totalMarks >= 90 && choice == 3)
                cout << "\nCongratulations! The Employee selected for the post of Project Manager" << endl;
            else if (totalMarks >= 85 && choice == 2)
                cout << "\nCongratulations! The Employee selected for the post of Team Leader" << endl;
            else if (choice == 1)
                cout << "\nCongratulations, the Employee selected for the post of Programmer" << endl;
            else
                cout << "\nSorry, but the employee has not been recruited to their desired post. "<< endl;
        }
        else
            cout << "\nSorry, but the employee has not been recruited to their desired post." << endl;
    }
};

int main()
{
    cout << "This program was brought to you by Aditi Rao." << endl;
    Posting emp;
    int choice, courseWork, AptTest, TechTest, interview;
    cout << "This is a program that allows for employee recruitment. \nBased on the post to which the employee is to be recruited to, please make your choice. \n1. Programmer.\n2. Team Leader\n3. Project Manager.\n" << endl;
    cin >> choice;
    int i = 0;
    while (choice != 0)
    {
        switch(choice)
        {
            case 1:
                cout << "\nTo recruit a programmer, you must input the marks of 4 tests." << endl;
                cout << "Kindly enter marks obtained in Course Work: ";
                cin >> courseWork;
                cout << "Kindly enter marks obtained in Aptitude Test: ";
                cin >> AptTest;
                cout << "Kindly enter marks obtained in Technical Test: ";
                cin >> TechTest;
                cout << "Kindly enter marks obtained in Interview: ";
                cin >> interview;
                {
                    Posting emp(courseWork, AptTest, TechTest, interview);
                    emp.displayPost(choice);
                }
                break;
            case 2:
                cout << "\nTo recruit a team leader, you must input the marks of 2 tests." << endl;
                cout << "Enter marks obtained in Technical Test: ";
                cin >> TechTest;
                cout << "Enter marks obtained in Interview: ";
                cin >> interview;
                {
                    Posting emp(TechTest, interview);
                    emp.displayPost(choice);
                }
                break;
            case 3:
                cout << "\nTo recruit a project manager, you must input the marks of 1 interview." << endl;
                cout << "Enter marks obtained in the Interview." << endl;
                cin >> interview;
                {
                    Posting emp(interview);
                    emp.displayPost(choice);
                }
                break;
            default:
                cout << "\nYou've given incorrect input. Please, try again." << endl;
        }
        cout << "\nKindly enter 0 if you wish to exit the loop.\n " << endl;
        cin >> choice;
    };
}
