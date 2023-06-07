#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;

class Item
{
    private:
        int code;
        string name;
        double price;
    public:
        // Item class declaration
class Item {
public:
    // Default Constructor
    Item() {
        code = 0;
        name = "";
        price = 0.0;
    }

    // Parameterized Constructor
    Item(int c, const string& n, double p) {
        code = c;
        name = n;
        price = p;
    }

    // Getter Methods
    int getCode() const {
        return code;
    }

    const string& getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};

};

class ShoppingList
{
    private:
        Item items[MAX_ITEMS];
        int itemCount;
    public:
        ShoppingList() : itemCount(0) {}

        void addItem(int code, const string& name, double price)
        {
            for (int i = 0; i < itemCount; i++)
            {
                if (items[i].getCode() == code)
                {
                    cout << "Item with code " << code << " already exists in the shopping list." << endl;
                    return;
                }
            }
            if (itemCount < MAX_ITEMS)
            {
                items[itemCount++] = Item(code, name, price);
                cout << "Item added: " << name << " (Code: " << code << ", Price: " << price << ")" << endl;
            }
            else
            {
                cout << "Cannot add item. Shopping list is full." << endl;
            }
        }

        void removeItem(int code)
        {
            int index = -1;
            for (int i = 0; i < itemCount; i++)
                {
                    if (items[i].getCode() == code)
                    {
                        index = i;
                        break;
                    }
                }
            if (index != -1)
            {
                cout << "Item removed: " << items[index].getName() << " (Code: " << items[index].getCode() << ", Price: " << items[index].getPrice() << ")" << endl;
                if (index < itemCount - 1)
                {
                    for (int i = index; i < itemCount - 1; i++)
                    {
                        items[i] = items[i + 1];
                    }
                }
                itemCount--;
            }
            else
            {
                cout << "Item with code " << code << " not found." << endl;
            }
        }

        void displayItems() const
        {
            cout << "Items in the shopping list:" << endl;
            for (int i = 0; i < itemCount; i++)
                {
                    cout << "Code: " << items[i].getCode() << ", Name: " << items[i].getName() << ", Price: " << items[i].getPrice() << endl;
                }
        }
        double calculateTotalPrice() const
        {
            double total = 0.0;
            for (int i = 0; i < itemCount; i++)
            {
                total += items[i].getPrice();
            }
            return total;
        }
};

int main()
{
    cout << "This code was brought to you by Aditi Rao." << endl;
    ShoppingList shop;
    int choice, code;
    string name;
    double price;
    while (true)
    {
        cout << "\n\n1. Add Item\n2. Remove Item\n3. Display Items\n4. Calculate Total Price\n5. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter item code: ";
                cin >> code;
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter item price: ";
                cin >> price;
                shop.addItem(code, name, price);
                break;

            case 2:
                cout << "Enter item code to remove: ";
                cin >> code;
                shop.removeItem(code);
                break;

            case 3:
                shop.displayItems();
                break;

            case 4:
                cout << "Total price: " << shop.calculateTotalPrice() << endl;
                break;

            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    }
    return 0;
}
