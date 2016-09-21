/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 10, Widget Works Inventory Mgmt - 11/1/12

	Description: Enhance the Widget Works inventory management systems with
		the following:
		-Widgets should also track the name and description of the Widgets
		-The list of widgets should be read from a file when the program starts
		-The list of widgets should be written to a file upon exit
		-Create a menu system to process an order, recieve a shipment, or exit
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <list>
#include "Widget.h"

using namespace std;

class Inventory
{
protected:
	list <Widget> on_hand;
	list <Widget> on_order;

public:

	//process order
	void order(Widget);
	
	//receive widget
	void receive(Widget);

	//i'm not sure if this was allowed, but it was the easiest way to
	//accomplish the way i wanted to do this

	//returnorder accepts the output fstream object in order to write the list to the file
	void returnorder(ofstream&);
	//loadorder accepts the input fstream object in order to load the list with the data from the file
	void loadorder(ifstream&);

	//same deal as above:
	//returnhand accepts the ofstream in order to write the list to the on hand file
	void returnhand(ofstream&);
	//loadhand accepts the ifstream object in order to load the list with file data
	void loadhand(ifstream&);
};

#endif //INVENTORY_H