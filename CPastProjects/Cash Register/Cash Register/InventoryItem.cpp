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
*/

#include "InventoryItem.h"
#include <string>

using namespace std;

//constructor 1
InventoryItem::InventoryItem()
{ //initialize everything at nothing
	description=" ";
	cost = 0.0;
	units = 0;
};

	//Constructor 2
	InventoryItem::InventoryItem(string desc)
	{ //assign a value to description
		description = desc;

		//initialize cost and units at 0
		cost = 0.0;
		units = 0;
	};

	//Constructor 3
	InventoryItem::InventoryItem(string desc, double c, int u)
	{ //assign a value to everything
		description = desc;
		cost = c;
		units = u;	
	};


	//mutators

	//class member function accepts a string value and assigns it to
	//class member data description
	void InventoryItem::setDescription(string desc)
	{ //assign a value to description
		description = desc;
	};

	//class member function accepts a double value and assigns it to
	//class member data cost
	void InventoryItem::setCost(double c)
	{ //assign a value to cost
		cost = c;	
	};

	//class member function accepts a int value and assigns it to
	//class member data units
	void InventoryItem::setUnits(int u)
	{ //assign a value to units
		units = u;	
	};

	//accessors

	//class member function accepts no arguments nad returns the value
	//currently stored in the class member data description
	string InventoryItem::getDescription() const
	{ //returns the description string
		return description;
	};

	//class member function accepts no arguments and returns the value
	//currently stored in the class member data cost
	double InventoryItem::getCost() const
	{ //returns the cost value
		return cost;
	};

	//class member function accepts no arguments and returns the value
	//currently stored in the class member data units
	int InventoryItem::getUnits() const
	{ //returns the number of units
		return units;	
	};

	//accepts the int quantity from CashRegister class to alter the supply on hand
	void InventoryItem::unitChange(int purchased)
	{
		units = units-purchased;
	};