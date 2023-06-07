#include <iostream>
#include <string>
using namespace std;

class Publication 
{
protected:
    string title;
    float price;

public:
    void getData() 
    {
        cout << "Kindly enter the title: ";
        getline(cin, title);

        cout << "Kindly enter the price: ";
        cin >> price;
        cin.ignore(); // Ignore the newline character
    }

    void putData() 
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication 
{
private:
    int pageCount;

public:
    void getData() 
    {
        Publication::getData(); // Call base class function

        cout << "Kindly enter the page count: ";
        cin >> pageCount;
        cin.ignore(); // Ignore the newline character
    }

    void putData() 
    {
        Publication::putData(); // Call base class function
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication 
{
private:
    float playingTime;

public:
    void getData() 
    {
        Publication::getData(); // Call base class function

        cout << "Kindly enter the playing time (in minutes): ";
        cin >> playingTime;
        cin.ignore(); // Ignore the newline character
    }

    void putData() 
    {
        Publication::putData(); // Call base class function
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() 
{
    Book book;
    Tape tape;

    cout << "Enter book details:\n";
    book.getData();

    cout << "\nEnter tape details:\n";
    tape.getData();

    cout << "\nBook details:\n";
    book.putData();

    cout << "\nTape details:\n";
    tape.putData();

    return 0;
}
