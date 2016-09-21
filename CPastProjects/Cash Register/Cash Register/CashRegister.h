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
#ifndef CASHREGISTER_H
#define CASHREGISTER_H

using namespace std;

class CashRegister
{
private:
	int quantity; //the number of items to be purchased
	double retailCost,
		subtotal,
		total;
	//i think this is all i need. the rest is in the inventoryitem class.

public:
	//constructor 1
	CashRegister();

	//mutators
	void setQuantity(int);
	void setsubtotal(double, int);
	void setCost(double, double);
	void resetCostquant();
	void setTotal(double, double);

	//accessors
	int getQuantity() const;
	double getsubtotal() const;
	double getCost() const;
	double getTotal() const;

};

#endif //CASHREGISTER_H