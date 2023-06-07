#include <iostream>
#include <string>

using namespace std;

class Account
{
	private:
		string DepositorName, AccountNumber, AccountType;
		float Balance;

	public:

		// Setter methods
		void setDepositorName(string name)
		{
			DepositorName = name;
		}

		void setAccountNumber(string acc_no)
		{
			AccountNumber = acc_no;
		}

		void setAccountType(string acc_type)
		{
			AccountType = acc_type;
		}

		void setBalance(float bal)
		{
			Balance = bal;
		}

		//getter methods
        string getDepositorName()
		{
			return DepositorName;
		}

		string getAccountNumber()
		{
			return AccountNumber;
		}

		string getAccountType()
		{
			return AccountType;
		}

		float getBalance()
		{
			return Balance;
		}

		// Member function to deposit an amount
		void Deposit()
		{
			float deposit;
			cout << "\nKindly enter the amount to be deposited: " << endl;
			cin >> deposit;
			Balance += deposit;
		}

		// Member function to withdraw an amount after checking the balance
		void Withdrawal()
		{
			float withdrawal;
			cout << "\nKindly Enter amount to be withdrawn: " << endl;
			cin >> withdrawal;
			if (Balance > withdrawal)
				Balance -= withdrawal;
			else
				cout << "\nInsufficient Funds. " << endl;
		}

		// Member function to display name and balance
		void Display()
		{
			cout << "Name of the depositor: " << DepositorName << endl;
			cout << "Balance: " << Balance << endl;
		}
};

int main()
{

	cout << "Good Morning!\nTo create a new account, press 1. \nTo deposit money in your existing bank account, press 2. \nTo withdraw money from your bank account press 3. \nTo display your balance, press 4. \nTo exit the program, press 5." << endl;
	cout << endl;
	Account account1;
	string name, acc_no, acc_type;
	float bal;
	bool isAccountCreated = false;
	int sw_var;
	cin >> sw_var;
	do
	{
		switch (sw_var)
		{
			case 1:
				if (isAccountCreated)
                    cout << "\nBank Account has already been created." << endl;
                else
				{
					cout << "\nEnter Depositor Name: ";
					cin.ignore();
					getline(cin, name);
					cout << "Enter Account Number: ";
					cin >> acc_no;
					cout << "Enter Account Type: ";
					cin.ignore();
					getline(cin, acc_type);
					cout << "Enter Initial Balance: ";
					cin >> bal;
					account1.setDepositorName(name);
					account1.setAccountNumber(acc_no);
					account1.setAccountType(acc_type);
					account1.setBalance(bal);
					isAccountCreated = true;
				}
				cout << "Press 0 to exit the loop.\n " << endl;
				cin >> sw_var;
			break;

			case 2:
				if (isAccountCreated)
					account1.Deposit();
				else
					cout << "\nThis Bank Account has not been created yet." << endl;
				cout << "Press 0 to exit the loop.\n " << endl;
				cin >> sw_var;
			break;

			case 3:
				if (isAccountCreated)
					account1.Withdrawal();
				else
					cout << "\nThis Bank Account has not been created yet." << endl;
				cout << "Press 0 to exit the loop.\n " << endl;
				cin >> sw_var;
			break;

			case 4:
				if (isAccountCreated)
					account1.Display();
				else
					cout << "\nThis Bank Account has not been created yet." << endl;
				cout << "Press 0 to exit the loop.\n " << endl;
				cin >> sw_var;
				break;

			default:
				cout << "Incorrect Input." << endl;
				cout << "Please, try again.\n " << endl;
				cin >> sw_var;
		}
	}
	while (sw_var != 0);
	return 0;
}





