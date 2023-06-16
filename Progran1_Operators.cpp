#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

static string str;

void read()
{
    cout << "Kindly enter the expression: ";
    getline(cin, str);
}


void checkZeroError()
{
    int pos = str.find('/');
    if (str[pos + 1] == '0') {
        throw "Divide by zero error.";
    }
}

void checkLogError()
{
    int pos = str.find("log");
    if (str[pos + 3] == '1' && str[pos + 4] == '\0') {
        throw "Logarithm of 1 error.";
    }
}

bool checkNumeric()
{
    bool hasNumeric = false;
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            hasNumeric = true;
        } 
        else {
            if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str.substr(i, 3) != "log" && str[i] != '^') {
                if (isalpha(str[i])) {
                    throw "Invalid expression. Non-numeric input.";
                }
                else {
                    throw "Invalid expression. Unsupported operator.";
                }
            }
            if (str.substr(i, 3) == "log") {
                i += 2;
            }
        }
    }
    return hasNumeric;
}

bool checkOperatorValidity()
{
    if ((str.find('+') != string::npos) || (str.find('-') != string::npos) || (str.find('/') != string::npos) || (str.find('*') != string::npos) || (str.find("log") != string::npos) || (str.find('^') != string::npos)) {
        if (str.find('/') != string::npos) {
            checkZeroError();
        } 
        else if (str.find("log") != string::npos) {
            checkLogError();
        }
        return true;
    } 
    else {
        return false;
    }
}

bool checkOperatorPosition()
{
    if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == 'l' || str[0] == '^' || str[str.length() - 1] == '+' || str[str.length() - 1] == '-' || str[str.length() - 1] == '*' || str[str.length() - 1] == '/' || str[str.length() - 1] == 'l' || str[str.length() - 1] == '^') {
        return false;
    } 
    else {
        return true;
    }
}

void compute()
{
    int opPos = -1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str.substr(i, 3) == "log" || str[i] == '^') {
            opPos = i;
            break;
        }
    }

    if (opPos == -1) {
        throw "Invalid operator.";
    }

    int a, b;
    try {
        if (str.substr(opPos, 3) == "log") {
            a = stoi(str.substr(0, opPos));
            b = stoi(str.substr(opPos + 3));
        } 
        else {
            a = stoi(str.substr(0, opPos));
            b = stoi(str.substr(opPos + 1));
        }
    } 
    catch (const invalid_argument) {    // Catches invalid_argument exception
        throw "Invalid operands.";
    }

    char op = str[opPos];
    switch (op) {
        case '+':
            cout << (a + b) << endl;
            break;
        case '-':
            cout << (a - b) << endl;
            break;
        case '*':
            cout << (a * b) << endl;
            break;
        case '/':
            cout << ((float)a / b) << endl;
            break;
        case 'l':
            cout << ((float)log(b) / log(a)) << endl;
            break;
        case '^':
            cout << pow(a, b) << endl;
            break;
    }
}



int main()
{
    cout << "Operators can be  +, -, *, /, log and ^" << endl;
    cout << "Kindly enter the expression in the form of a + b, a - b, a * b, a / b, a log b (for loga(b)) or a ^ b" << endl;
    char choice;
    do {
        read();
        try {
            if (checkNumeric()) {
                if (checkOperatorValidity()) {
                    if (checkOperatorPosition()) {
                        compute();
                    } 
                    else {
                        throw "Invalid expression. Incorrect operator position.";
                    }
                } 
                else {
                    throw "Invalid expression. Unsupported operator.";
                }
            } 
            else {
                throw "Invalid expression. Non-numeric input.";
            }
        } 
        catch (const char* errorMsg) {
            cout << "Error: " << errorMsg << endl;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        cin.ignore();
    } 
    while (choice == 'y' || choice == 'Y');

    return 0;
}