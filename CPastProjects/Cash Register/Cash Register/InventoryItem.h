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
#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <string>
#include "CashRegister.h"

using namespace std;

class InventoryItem
{
private:
	string description; //item description
	double cost; //to hold the item's cost
	int units; //to hold the number of units
	
public:
	//Constructor 1
	InventoryItem();
	//Constructor 2
	InventoryItem(string);
	//Constructor 3
	InventoryItem(string, double, int);
	//mutators
	void setDescription(string);
	void setCost(double);
	void setUnits(int);
	//accessors
	string getDescription() const;
	double getCost() const;
	int getUnits() const;

	void unitChange(int);
};

#endif //INVENTORYITEM_H