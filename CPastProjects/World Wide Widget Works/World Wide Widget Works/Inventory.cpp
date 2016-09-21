/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 10, Widget Works Inventory Mgmt - 11/1/12

	Description: Enhance the Widget Works inventory management systems with
		the following:
		-Widgets should also track the name and description of the Widgets
		-The list of widgets should be read from a file when the program starts
		-The list of widgets should be written to a file upon exit
		-Create a menu system to process an order, recieve a shipment, or exit
*/

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include "Inventory.h"
#include "WidgetTester.h"

using namespace std;


//process order
void Inventory::order(Widget wid)
{
	cout << "Received order of widget " << wid << "\n";

	list<Widget>::iterator we_have = find_if(on_hand.begin(), on_hand.end(), WidgetTester(wid));

	if (we_have != on_hand.end())
	{
		cout << "Ship widget " << *we_have << " to fill order\n";
		on_hand.erase(we_have);
	}
	else
	{
		cout << "Add " << wid << " to back order list.\n";
		on_order.push_front(wid);
	}

}; //end order
	
//receive widget
void Inventory::receive(Widget wid)
{
	cout << "Received shipment of widget " << wid << "\n";

	list<Widget>::iterator we_need = find(on_order.begin(), on_order.end(), wid.getID());

	if (we_need != on_order.end())
	{
		cout << "Ship " << wid << " to fill back order.\n";
		on_order.erase(we_need);
	}
	else
	{
		cout << "Adding widget " << wid << " to on hand list.\n";
		on_hand.push_front(wid);
	}
}; //end receive

/*
method: returnhand		accepts: ifstream &handout object

description: accepts output file in order to write the widget objects' data
	into the file in the same manner as extracted previously. the list is traversed via
	an iterator, information from the widget written to a new widget, which is then written
	to the file in pieces.
*/
void Inventory::returnorder(ofstream &orderout)
{
	list<Widget>::iterator counter;
	for(counter = on_order.begin(); counter != on_order.end(); counter++)
	{
		Widget wid = *counter;
		orderout << wid.getID() << " " << wid.getName() << " " << wid.getDesc() << "\n";
	}
}; //end listout for writing to file

/*
method: loadorder		accepts: ifstream &orderin object

description: accepts data from the input file in order to create the widget objects
	and load them into the on_order list.
*/
void Inventory::loadorder(ifstream &orderin)
{
	string name,
		description;
	int id;

	while (!orderin.eof())
	{
		orderin >> id >> name >> description;
		Widget wid(id, name, description);
		on_order.push_front(wid);
	}
}; //end listin for loading the list

/*
method: returnhand		accepts: ifstream &handout object

description: accepts output file in order to write the widget objects' data
	into the file in the same manner as extracted previously. the list is traversed via
	an iterator, information from the widget written to a new widget, which is then written
	to the file in pieces.
*/
void Inventory::returnhand(ofstream &handout)
{
	list<Widget>::iterator counter;
	for(counter = on_hand.begin(); counter != on_hand.end(); counter++)
	{
		Widget wid = *counter;
		handout << wid.getID() << " " << wid.getName() << " " << wid.getDesc() << "\n";
	}
};

/*
method: loadhand		accepts: ifstream &handin object

description: accepts data from the input file in order to create the widget objects
	and load them into the on_hand list.
*/
void Inventory::loadhand(ifstream &handin)
{
	string name,
		description;
	int id;

	while (!handin.eof()) //continue loop until the eof is found
	{
		handin >> id >> name >> description; //read in each line of widget informations
		Widget wid(id, name, description); //create the widget - new widget is created every iteration of the loop
		on_hand.push_front(wid); //write the widget to the list
		
	}
}; //end onhand loading