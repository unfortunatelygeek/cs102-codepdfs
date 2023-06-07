#include <iostream>
#include <string>
using namespace std;

class Cow
{
private:
	string Name;
	long int ID_Number;

	int DOB; 				// Date of Birth
	int DORC; 				// Date of Most Recent Calving

	int TotalMilk;

public:

	Cow()					//Default Constructor
    	{
        	Name = "";
        	ID_Number = 0;
        	DOB = 0;
        	DORC = 0;
        	TotalMilk = 0;
    	}

    //Parameterized constructor to show Parameterized Constructor Intialization
    Cow(string name, long int id, int dob, int dorc, int totalMilk)
	{
		Name = name;
		ID_Number = id;
		DOB = dob;
		DORC = dorc;
		TotalMilk = totalMilk;
	}

	// Setter methods to show Setter and Getter Methods
	void setName(string name)
	{
		Name = name;
	}

	void setID(long int id)
	{
		ID_Number = id;
	}

	void setDOB(int dob)
	{
		DOB = dob;
	}

	void setDORC(int dorc)
	{
		DORC = dorc;
	}

	void setTotalMilk(int totalMilk)
	{
		TotalMilk = totalMilk;
	}

	// Getter methods
	string getName()
	{
		return Name;
	}

	long int getID()
	{
		return ID_Number;
	}

	int getDOB()
	{
		return DOB;
	}

	int getDORC()
	{
		return DORC;
	}

	int getTotalMilk()
	{
		return TotalMilk;
	}

	// Method to add milk production
	void addMilk(int milk)
	{
		TotalMilk += milk;
	}

	// Method to find average milk production
	double findAverageMilk()
	{
		if (DORC != 0)
		{
			(double)(TotalMilk) / (DORC - DOB);
		}
		else
		{
			return 0;
		}
	}

	// Method to reset total milk output
	void resetTotalMilk()
	{
		TotalMilk = 0;
	}
};

int main()
{
    cout << "This program was brought to you by Aditi Rao." << endl;
	Cow C1("Arthur", 394029843, 19032022, 28032023, 500); // Example of creating Cow object with constructor
	Cow C2; 								// Example of creating Cow object with setter and getter methods

	// Set values using setter methods
	C2.setName("Merlin");
	C2.setID(29182932);
	C2.setDOB(21042021);
	C2.setDORC(22032023);
	C2.setTotalMilk(300);

	// Get values using getter methods
	cout << "Cow1 Name: " << C1.getName() << endl;
	cout << "Cow1 ID: " << C1.getID() << endl;
	cout << "Cow1 DOB: " << C1.getDOB() << endl;
	cout << "Cow1 DORC: " << C1.getDORC() << endl;
	cout << "Cow1 TotalMilk: " << C1.getTotalMilk() << endl;

	cout << "Cow2 Name: " << C2.getName() << endl;
	cout << "Cow2 ID: " << C2.getID() << endl;
	cout << "Cow2 DOB: " << C2.getDOB() << endl;
	cout << "Cow2 DORC: " << C2.getDORC() << endl;
	cout << "Cow2 TotalMilk: " << C2.getTotalMilk() << endl;

	// Add milk production for Cow1 and Cow2
	C1.addMilk(200);
	C2.addMilk(100);
}
