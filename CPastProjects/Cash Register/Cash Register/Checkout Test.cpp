/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	
	Week 2, Cash Register class program - 9/4/12

	Description: Create a CashRegister class that asks the user for the item
		they are purchasing and the quantity. It should then collect the cost
		of a single item and mark it up 30% to determine the individual retail
		cost of that item. This is of course followed by multiplying the retail
		cost by the number of items being purchased. This is the subtotal.
		Multiply that subtotal by the 6% sales tax and display that, then display
		the total (subtotal+(subtotal*.06)). Then subtract the number of items
		being purchased from the stock.
		Input validation: Do not accept negative numbers for the quantity.
			Error checking: Verify that there are enough items to sell.
	
	Notes: The book says it wants the class to perform
		all the things I felt the program should do, but I don't know
		what is what. I remember CHardnett said that objects shouldn't
		accept input or display output, so I decided to go by that first.
		Because the way I see it, the program wouldn't interact with the object
		if the object has the menu and everything else. But at the same time,
		what if you were in a store with 4 cash registers? That would require 4
		cash register objects. But how would you access them all in a procedural
		program? Have I missed something? Am I not thinking abstractly enough?
		Besides, even if you had them all open and altering data, that would only be
		on that register. If there are 20 items in the store and one cash register sells
		7 throughout the day, that register will only show 13 left. What if the other
		4 sold more than 13 throughout the day? They would have to consolidate all
		the data with a database plugin, right?

			I don't know. I think maybe I'm thinking too hard about it. Too stressed
			or not knowledgeable enough. Whatever. HERE GOES.

*/

#include "InventoryItem.h"
#include "CashRegister.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

const double SALES_TAX = .06, //current sales tax
		PROFIT_MARGIN = .3; //to hold the markup percentage

InventoryItem menuCase(InventoryItem, CashRegister&);
void menu();
void greet();
//end prototypes

int main()
{
	greet();

	menu();

	cout << "\n";
	system("pause");
	return 0;
}; //end main

void greet()
{
	cout << "Thank you so much for coming in to work today.\n";
	cout << "This application is here to assist in all of your cashiering needs.\n";
	cout << "Please remember that the only keys you should be hitting are numbers\n";
	cout << "and letters. If you've worked here long enough, you're probably already\n";
	cout << "ignoring this message, but it is still important.\n";
	cout << "Numbers and letters only folks. Numbers and y or n.\n";
	cout << "\n";
	cout << "Have a super day!\n";
	cout << "\n";
}; //end greeting function

void menu()
{
	int menuOption;
	char moreItems='Y';
	const int SIZE=8;
	InventoryItem items[SIZE]={ InventoryItem("Loki Earrings", 8.95, 2),
			InventoryItem("Cpt. America Pendant", 4.95, 8),
			InventoryItem("Iron Man Gloves", 8.95, 6),
			InventoryItem("Black Widow Earrings", 12.95, 5),
			InventoryItem("Thor Earrings - Mjolnir", 12.95, 9),
			InventoryItem("Hulk/Banner Earrings", 16.95, 7),
			InventoryItem("Hawkeye Pendant", 7.95, 20),
			InventoryItem("Loki Helmet Charm", 6.95, 12) };
	CashRegister reg1;

	while (moreItems='Y')
	{
		cout << "\n";
		cout << "Items for Sale\n";
	
		cout << "\n";
		cout << left << setw(5) << "Menu" << setw(30) << "Description" << setw(7) << "Units" << setw(10) << "Cost" << "\n";

		for (int count=1; count <=52; count++)
			cout << "-";

		cout << "\n";
		cout << left << setw(5) << "0" << setw(30) << "Quitting Time" << setw(7) << " " << setw(10) << " " << "\n";
	
		for (int count=0; count <= SIZE-1; count++)
		{
			cout << setw(5) << count+1 << setw(30) << items[count].getDescription() << setw(7) << items[count].getUnits() 
					<< setw(10) << items[count].getCost() << "\n";
		}

		cout << "\n";
		cout << "Please choose an option between 1 and " << SIZE << ".\n";
		cout << "Please enter the item to be purchased: ";
		cin >> menuOption;

		while (menuOption < 0)
		{
			cout << "\n";
			cout << "No negative numbers please.\n";
			cout << "Please choose an option between 1 and " << SIZE << ".\n";
			cout << "Please enter the item to be purchased: ";
			cin >> menuOption;
		}
	
		while (menuOption > SIZE)
		{
			cout << "\n";
			cout << "Please choose an option between 1 and " << SIZE << ".\n";
			cout << "Please enter the item to be purchased: ";
			cin >> menuOption;
		}

		switch (menuOption)
		{
		case 1:
			items[menuOption-1]=menuCase(items[menuOption-1], reg1);
			break;
		case 2:
			items[menuOption-1]=menuCase(items[menuOption-1], reg1);
			break;
		case 3:
			items[menuOption-1]=menuCase(items[menuOption-1], reg1);
			break;
		case 4:
			items[menuOption-1]=menuCase(items[menuOption-1], reg1);
			break;
		case 5:
			items[menuOption-1]=menuCase(items[menuOption-1], reg1);
			break;
		case 6:
			items[menuOption-1]=menuCase(items[menuOption-1], reg1);
			break;
		case 7:
			items[menuOption-1]=menuCase(items[menuOption-1], reg1);
			break;
		case 8:
			items[menuOption-1]=menuCase(items[menuOption-1], reg1);
			break;
		default:
			break;
		} //end switch

		if (menuOption == 0)
		{
			cout << "\n";
			cout << "Have a good day/night!\n";
			exit(0);
		}
		else
		{
			cout << "\n";
			cout << "Does the customer have more items to purchase?\n";
			cout << "Please enter y for yes, or n for no.\n";
			cin >> moreItems;
			moreItems = toupper(moreItems);
		}
	} //end moreItems while
}; //end menu function

InventoryItem menuCase(InventoryItem inventitem, CashRegister &rega)
{
	int quantity;

	cout << "\n";
	cout << setw(30) << inventitem.getDescription() << setw(7) << inventitem.getUnits() 
					<< setw(10) << inventitem.getCost() << "\n";
	cout << "How many is the customer buying: ";
	cin >>quantity;

	while (quantity < 0)
	{
		cout << "Only positive numbers please.\n";
		cout << "If you chose this item by mistake, please type in 0 to escape.\n";
		cin >>quantity;
	}
	
	while (quantity > inventitem.getUnits())
	{
		cout << "It would appear that the number of items to purchase is more\n";
		cout << "than we have in stock.\n";
		cout << "If you chose this item by mistake, please type in 0 to escape.\n";
		cin >>quantity;
	}

	if (quantity > 0)
	{
		if (quantity <= inventitem.getUnits())
		{
			cout << "\n";
			rega.setQuantity(quantity);
			rega.setCost(inventitem.getCost(), PROFIT_MARGIN);
			rega.setsubtotal(rega.getCost(), rega.getQuantity());
			rega.setTotal(rega.getsubtotal(), SALES_TAX);
			cout << setprecision(2) << fixed;
			cout << "The total before taxes is: $" << rega.getsubtotal() << ".\n";
			cout << "The sales tax rate that will be applied is " << SALES_TAX*100 << "%.\n";
			cout << "That will result in a sales tax of: $" << rega.getsubtotal()*SALES_TAX << ".\n";
			cout << "All told, your purchase today will be: $" << rega.getTotal() << ".\n";
			inventitem.unitChange(quantity);
			rega.resetCostquant();
		} //end cashregister calculations
	} //end if quantity >0
	else
	{ //for if the quantity is 0
		cout << "\n";
		cout << "Did you choose this one by mistake?\n";
	} // end if

	return inventitem;
};