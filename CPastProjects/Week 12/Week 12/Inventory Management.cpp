/* CIST 2361 - Inventory Management
	Kimberly Jackson - 4/18/2012

	Description: Program is set up to hold information about an
		inventory. Users will be able to add new items to the inventory,
		display inventory, and alter pre-existing information. Items in 
		inventory will be stored in a structure
	*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib> //including this for the random function

using namespace std;

const int DESC_SIZE = 32,
	DATE_SIZE = 16;

struct inventory
{
	public:
		string descrip,
			dateadded;
		int qoh;
		float wholecost,
			retailcost;
};

fstream inventry;

void display(inventory, string);
void edit(inventory, string);
void add(inventory, string);

int main()
{
	int menu;
	inventory inven;
	string search;
	char again;
	inventry.open("inventory.txt");

	cout << "Welcome to the Inventory Management screen.\n";
	cout << "This program display inventory one item at a time.\n";

	do
	{
	cout << "Please choose a menu option below: (numbers only)\n";
	cout << "1. Display a specific item\n";
	cout << "2. Alter a specific item\n";
	cout << "3. Add a new item to inventory\n";
	cout << "4. Exit\n";
	cin >> menu;

	if (menu < 1 || menu > 4)
		cout << "Incorrect menu option input. Try again.\n";

	switch (menu)
	{
		case 1:
			display(inven, search);
			break;
		case 2:
			edit(inven, search);
			break;
		case 3:
			add(inven, search);
			break;
		case 4:
			cout << "You have chosen to quit.\n";
			cout << "Quitter.\n";
			cout << "<3\n";
			break;
	}


		cout << "Would you like to perform another search? Enter Y for yes.\n";
		cin >> again;
	} while (toupper(again) == 'Y');
	


	inventry.close();
	cout << "\n";
	system("pause");
	return 0;
}

void display(inventory inven1, string search1)
{
	cout << "You have select to display an item. Please enter the\n";
	cout << "name of the item you wish to search for. They are stored\n";
	cout << "as all capital letters.\n";
	cin >> search1;

	getline(inventry, inven1.descrip, '@');
	
	while (inventry)
	{
		if (inven1.descrip == search1)
		{
			inventry >> inven1.qoh;
			inventry >> inven1.wholecost;
			inventry >> inven1.retailcost;
			getline(inventry, inven1.dateadded);
			cout << "Item: " << inven1.descrip << "\n";
			cout << "Quantity on Hand: " << inven1.qoh << "\n";
			cout << "Wholesale Cost: " << inven1.wholecost << "\n";
			cout << "Retail Cost: " << inven1.retailcost << "\n";
			cout << "Date Added to Inventory: " << inven1.dateadded << "\n";
			cout << "\n";
			getline(inventry, inven1.descrip, '@');
		}
		else
			inventry >> inven1.qoh;
			inventry >> inven1.wholecost;
			inventry >> inven1.retailcost;
			getline(inventry, inven1.dateadded);
			getline(inventry, inven1.descrip, '@');
	}

}

void edit(inventory inven2, string search2)
{
	cout << "You have select to edit an item. Please enter the\n";
	cout << "name of the item you wish to search for. They are stored\n";
	cout << "as all capital letters.\n";
	cin >> search2;

	getline(inventry, inven2.descrip, '@');
	
	while (inventry)
	{
		if (inven2.descrip == search2)
		{
			inventry >> inven2.qoh;
			inventry >> inven2.wholecost;
			inventry >> inven2.retailcost;
			getline(inventry, inven2.dateadded);
			cout << "Item: " << inven2.descrip << "  ";
			cout << "Quantity on Hand: " << inven2.qoh << "  ";
			cout << "Wholesale Cost: " << inven2.wholecost << "\n";
			cout << "Retail Cost: " << inven2.retailcost << "  ";
			cout << "Date Added to Inventory: " << inven2.dateadded << "\n";
			cout << "\n";

			cout << "Is this the data you would like to edit?\n";
			cin >> char truth;

			if (truth == 'Y')
			{
				cout << "Please enter in the name of the item again.\n";
				getline(cin, inven2.descrip);
				do
				{
				cout << "Next, the quantity that you have on hand. Numbers only, no decimals.\n";
				cin >> inven2.qoh;
				} while (inven2.qoh < 0);

				do
				{
					cout << "The wholesale cost of the item:\n";
					cin >> inven2.wholecost;
				} while (inven2.wholecost < 0);

				do
				{
					cout << "The retail cost of the item:\n";
					cin >> inven2.retailcost;
				} while (inven2.retailcost < 0);

				cout << "The date this item was added to inventory:\n";
				getline(cin, inven2.dateadded);

				cout << "Item: " << inven2.descrip << "  ";
				cout << "Quantity on Hand: " << inven2.qoh << "  ";
				cout << "Wholesale Cost: " << inven2.wholecost << "\n";
				cout << "Retail Cost: " << inven2.retailcost << "  ";
				cout << "Date Added to Inventory: " << inven2.dateadded << "\n";
				cout << "Replacing record.\n";
				
				inventry.clear();
				getline(inventry, inven2.descrip, '@');
			}
			getline(inventry, inven2.descrip, '@');
		}
		else
			inventry >> inven2.qoh;
			inventry >> inven2.wholecost;
			inventry >> inven2.retailcost;
			getline(inventry, inven2.dateadded);
			getline(inventry, inven2.descrip, '@');
	}
}

void add(inventory inven3, string search3)
{

}