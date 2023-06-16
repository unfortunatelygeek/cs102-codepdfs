#include <iostream>
#include <string>
#include <exception>
#include <limits>
using namespace std;

/*As exception is already a pre-defined class in C++, we can simply use it by inheriting it
from the exception class. This is called user-defined exception. We can then use functionalities limited to
exception class by this inheritance*/

class MonthError : public exception {                  
public:
    const char* what() const throw() {
        return "Invalid month";
    }
};

class DayError : public exception {
public:
    const char* what() const throw() {
        return "Invalid day for the corresponding month";
    }
};

// Function to convert numerical month to alphabetic month
string getMonthName(int month) {                                
    static const string monthNames[] = {"", "January", "February", "March", "April","May", "June", "July", "August","September", "October", "November", "December"};

    if (month < 1 || month > 12)
        throw MonthError();

    return monthNames[month];
}

// Function to check if the day is valid for the corresponding month
bool isValidDay(int month, int day) {                           
    static const int daysInMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month])
        throw DayError();

    return true;
}

// Function to check if the character is a special character other than slash
bool isSpecialCharacter(char ch) {
    static const string specialCharacters = "!@#$%^&*()_+=-{}[]|\\:;<>,.?~`";
    return specialCharacters.find(ch) != string::npos;
}

int main() 
{
    char choice;
    do {
        int month, day;
        char slash;

        cout << "Enter Date in month/day numeric notation: ";
        cin >> month >> slash >> day;                           //slash is used to store the '/' character

        try {
            if (isSpecialCharacter(slash))
                throw runtime_error("Invalid date format"); //we can use runtime_error because we inherited MonthError and DayError from exception class
            string monthName = getMonthName(month);
            isValidDay(month, day);
            cout << "That is the same as" << endl;
            cout << monthName << " " << day << endl;
        } 
        catch (const MonthError ex) {
            cout << ex.what() << endl;
            cout << "Try Again!" << endl;
            continue;
        } 
        catch (const DayError ex) {
            cout << ex.what() << endl;
            cout << "Try Again!" << endl;
        }
        catch (const exception ex) {
            cout << "Invalid input. Special character other than '/' is not allowed." << endl;
            cout << "Try Again!" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //to ignore the rest of the input
        }
        cout << "Again? (y/n): ";
        cin >> choice;
    } 
    while (choice == 'y' || choice == 'Y');

    cout << "End of program." << endl;

    return 0;
}
