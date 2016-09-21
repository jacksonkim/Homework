/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	
	Week 4, Program 1, PersonData and CustomerData
		or Mailing List Registration - 9/14/2012

		Description: Display the usage of the PersonData and CustomerData
			classes created earlier.

			I know this program is sloppy as hell. But it works.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "PersonData.h"
#include "CustomerData.h"

using namespace std;

void menu(int&);
void newCustomer(CustomerData&);
void displayCustomers(CustomerData, int);
void mailingList(CustomerData &);

int main()
{
	const int SIZE = 5;
	CustomerData customers[SIZE] = { (80645) };

	 int menuOption = 0,
		 customerOption;

	cout << "Welcome to the Mailing List Registration for Aspired Creativity.\n";
	cout << "Caps lock is recommended for all future entries. This program will not\n";
	cout << "be able to work efficiently without it. For consistency, you see.\n";
	cout << "\n";
	cout << "Below you will see a list of menu options:\n";

	do
	{

		cout << "\n";
		cout << setw(4) << "1." << setw(35) << "Register New Customer\n";
		cout << setw(4) << "2." << setw(35) << "Display customer information\n";
		cout << setw(4) << "3." << setw(35) << "Mailing List Registration\n";
		cout << setw(4) << "4." << setw(35) << "Log out\n";
		cout << "Please enter your option: ";
		cin >> menuOption;

		switch (menuOption)
		{
		case 1:
			for (int counter = 0; counter <= SIZE-1; counter++)
			{
				displayCustomers(customers[counter], counter+1);
			};
			cout << "\nFor which customer? ";
			cin >> customerOption;

			newCustomer(customers[customerOption-1]);

			break;
		case 2:
			for (int counter = 0; counter <= SIZE-1; counter++)
			{
				displayCustomers(customers[counter], counter+1);
			};
			break;
		case 3:
			for (int counter = 0; counter <= SIZE-1; counter++)
			{
				displayCustomers(customers[counter], counter+1);
			};
			cout << "\nFor which customer? ";
			cin >> customerOption;

			mailingList(customers[customerOption-1]);

			break;
		case 4:
			break;
		default:
			//that's not it at all
			break;
		}

	} while (menuOption != 4);

	cout << "\n";
	system("pause");
	return 0;

};

void displayCustomers(CustomerData cust, int number)
{
	cout << "\n";
	cout << "Customer " << number << ": ";
	cout << "\nCustomer ID Number: "<< cust.getNum() << "\n";
	cout << cust.getFirst() << " " << cust.getLast() << "\n";
	cout << cust.getAddress() << "\n";
	cout << cust.getCity() << ", " << cust.getState() << " " << cust.getZip() << "\n";
	cout << "Phone: " << cust.getPhone() << "\n";
	cout << "Subscribed to Mailing List? ";
	if (cust.getList() == false)
		cout << "No\n";
	else
		cout << "Yes\n";

};

void newCustomer(CustomerData &cust1)
{
	string fName,
		lName,
		street,
		city,
		state,
		phone;

	int zip;

	char correct = 'N';

	do
	{
	cout << "\n";
		cout << "Please enter in the new customer's FIRST NAME: ";
		cin >> fName;

		cout << "\n";
		cout << "Please enter in the new customer's LAST NAME: ";
		cin >> lName;

		cout << "\n";
		cout << "Please enter in the new customer's STREET ADDRESS: ";
		cin. ignore();
		getline(cin, street);

		cout << "\n";
		cout << "Please enter in the new customer's CITY: ";
		cin. ignore();
		getline(cin, city);

		cout << "\n";
		cout << "Please enter in the new customer's STATE: ";
		cin >> state;

		cout << "\n";
		cout << "Please enter in the new customer's ZIP CODE: ";
		cin >> zip;

		cout << "\n";
		cout << "Please enter in the new customer's PHONE NUMBER: ";
		cin >> phone;

		cout << "\n";
		cout << fName << " " << lName << "\n";
		cout << street << "\n";
		cout << city << ", " << state << " " << zip << "\n";
		cout << "Phone: " << phone << "\n";
		cout << "Is all of this information correct?\n";
		cout << "Enter Y for correct.\n";
		cin >> correct;
		

	} while (correct != 'Y');

	cust1.setAll(fName, lName, street, city, state, zip, phone);
	cust1.setNum(rand()%12);

	mailingList(cust1);

};

void mailingList(CustomerData &cust2)
{
	char mailer;

	cout << "Would they like to register for the mailing list?\n";
	cout << "Please enter Y or N: ";
	cin >> mailer;

	if (mailer == 'Y' || mailer == 'y')
		cust2.setList(true);
	else if (mailer == 'N' || mailer == 'n')
		cust2.setList(false);

};