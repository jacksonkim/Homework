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
#include "CashRegister.h"
#include <iostream>

using namespace std;
//global constants


//default constructor
CashRegister::CashRegister()
{
	quantity=0;
	retailCost=0.0;
	subtotal=0.0;
	total=0.0;
};


	//mutators

//accepts user input to set quantity
void CashRegister::setQuantity(int q)
{
	quantity=q;
};

//accepts inventoryitem cost and user input quantity to set the subtotal
void CashRegister::setsubtotal(double rcost, int q)
{
	subtotal = subtotal + (rcost*q);
};


void CashRegister::setCost(double rcost, double PROFIT_MARGIN)
{
	retailCost = rcost + (rcost*PROFIT_MARGIN);
};


void CashRegister::resetCostquant()
{
	retailCost = 0.0;
	quantity = 0;
};

void CashRegister::setTotal(double subT, double SALES_TAX)
{
	total =((subT*SALES_TAX)+subT);
};


//accessors


int CashRegister::getQuantity() const
{
	return quantity;
};


double CashRegister::getsubtotal() const
{
	return subtotal;
};


double CashRegister::getCost() const
{
	return retailCost;

};


double CashRegister::getTotal() const
{
	return total;
};