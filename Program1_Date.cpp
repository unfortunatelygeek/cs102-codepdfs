#include <iostream>
using namespace std;

class Date
{
private:
    int year, month, day, hrs, mins, sec;

public:

    // Default constructor
    Date()
    {
        year = 2000;
        month = 1;
        day = 1;
        hrs = 0;
        mins = 0;
        sec = 0;
    }

    // Setter method for date with only year, month and date
    void setDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
        hrs = 0;
        mins = 0;
        sec = 0;
    }

    // Setter method for date and time without seconds
    void setDate(int y, int m, int d, int h, int mi)
    {
        year = y;
        month = m;
        day = d;
        hrs = h;
        mins = mi;
        sec = 0;
    }

    // Setter method for date and time with seconds
    void setDate(int y, int m, int d, int h, int mi, int s)
    {
        year = y;
        month = m;
        day = d;
        hrs = h;
        mins = mi;
        sec = s;
    }

    // Display method to display date and time

    void displayDate()
    {
        if (hrs == 0 && mins == 0 && sec == 0)
            cout << "\n" << day << "-" << month << "-" << year << " " << endl;
        else if (sec == 0)
            cout << "\n" << day << "-" << month << "-" << year << " " << hrs << ":" << mins << endl;
        else
            cout << "\n" << day << "-" << month << "-" << year << " " << hrs << ":" << mins << ":" << sec << endl;
    }
};

int main()
{
    cout << "This program was brought to you by Aditi Rao, 2022200003. \n" << endl;
    Date newDate;

    cout << "You are to choose the method of date presentation. \n1. To show year, month and day \n2. To show hours and minutes as well \n3. To show seconds as well.\n" << endl;
    int sw_var;
    cin >> sw_var;

    switch (sw_var)
    {
    case 1:
        {
            int year, month, day;
            cout << "\nEnter year: ";
            cin >> year;
            cout << "Enter month: ";
            cin >> month;
            cout << "Enter day: ";
            cin >> day;
            newDate.setDate(year, month, day);
            newDate.displayDate();
            break;
        }
    case 2:
        {
            int year, month, day, hrs, mins;
            cout << "\nEnter year: ";
            cin >> year;
            cout << "Enter month: ";
            cin >> month;
            cout << "Enter day: ";
            cin >> day;
            cout << "Enter hours: ";
            cin >> hrs;
            cout << "Enter minutes: ";
            cin >> mins;
            newDate.setDate(year, month, day, hrs, mins);
            newDate.displayDate();
            break;
        }
        case 3:
        {
            int year, month, day, hrs, mins, sec;
            cout << "\nEnter year: ";
            cin >> year;
            cout << "Enter month: ";
            cin >> month;
            cout << "Enter day: ";
            cin >> day;
            cout << "Enter hours: ";
            cin >> hrs;
            cout << "Enter minutes: ";
            cin >> mins;
            cout << "Enter seconds: ";
            cin >> sec;
            newDate.setDate(year, month, day, hrs, mins, sec);
            newDate.displayDate();
            break;
        }
        default:
            cout << "\nInvalid choice" << endl;
    }
    return 0;
}
