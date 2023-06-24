#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
    private:
        string title;
        string author;
        int yearofPublication;

    public:
        Book() {
            title = "";
            author = "";
            yearofPublication = 0;
        }
        Book(string title, string author, int yearofPublication) {
            this->title = title;
            this->author = author;
            this->yearofPublication = yearofPublication;
        }

        string getTitle() {
            return title;
        }

        void displayBook() {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Year of Publication: " << yearofPublication << endl;
        }
};

int main() 
{
    vector <Book> books;
    int choice;

    do {
        cout << "1. Add a book" << endl;
        cout << "2. Display books" << endl;
        cout << "3. Search a book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                string title, author;
                int yearofPublication;

                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year of publication: ";
                cin >> yearofPublication;

                Book book(title, author, yearofPublication);
                books.push_back(book);
                break;
            }

            case 2: {
                for (int i = 0; i < books.size(); i++) {
                    books[i].displayBook();
                    cout << endl;
                }
                break;
            }

            case 3: {
                string searchTitle;
                bool found = false;

                cout << "Enter the book title: ";
                cin.ignore();
                getline(cin, searchTitle);
                if (books.size() > 0) {
                    for (int i = 0; i < books.size(); i++) {
                        if (books[i].getTitle() == searchTitle) {
                            books[i].displayBook();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Book not found." << endl;
                    }
                }
                else {
                    cout << "No books added yet." << endl;
                }
                break;
            }

            case 4: {
                cout << "Thank you for using the program." << endl;
                break;
            }

            default: {
                cout << "Invalid choice." << endl;
                break;
            }
            cout << endl;
        }
    } 
    while (choice != 4);

    return 0;
}