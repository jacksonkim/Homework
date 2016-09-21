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
#include <string>
#include <iomanip>
#include <list>
#include "Widget.h"
#include "Inventory.h"

using namespace std;

//prototypes maybe
void fileinput();
void fileoutput(Inventory);
void menusystem(Inventory&);
void processorder(Inventory&);
void receiveships(Inventory&);

int main()
{
	fileinput();

	cout << "\nThank you for all your efforts!\n";
	system("pause");
	return 0;
};

void fileinput()
{
	ifstream inorders("Order List.txt");
	ifstream inhand("On Hand.txt");

	Inventory stock1;

	if (inorders.fail())
	{
		cout << "Error opening the order list.\n";
	}

	if (inhand.fail())
	{
		cout << "Error opening the on hand list.\n";
	}

	if (inorders.fail() && inhand.fail())
	{
		cout << "Neither file opened. Something must be wrong.\nProgram will exit.\n";
		system("pause");
		exit(0);
	}
	
	/*string name,
		description;
	int id;

	while (!inorders.eof())
	{
		inorders >> id >> name >> description;
		Widget wid(id, name, description);
		stock1.order(wid);
	}

	name = " ";
	description = " ";
	id = 00000;

	while (!inhand.eof())
	{
		inhand >> id >> name >> description;
		Widget wid(id, name, description);
		stock1.receive(wid);
	}*/

	stock1.loadorder(inorders);
	stock1.loadhand(inhand);

	inorders.close();
	inhand.close();

	menusystem(stock1);

}; //end fileinput

void menusystem(Inventory &invm)
{

	cout << "Welcome back to the World Wide Widget Works Inventory Management System.\n";
	cout << "Please choose from an option below:\n";

	int menu;

	do
	{
		cout << "1. Process an order request\n";
		cout << "2. Receive a shipment\n";
		cout << "3. Exit\n";
		cout << "Please enter in the number of your choice: ";
		cin >> menu;

		if (menu == 1)
		{
			processorder(invm);
		}
		else if (menu == 2)
		{
			receiveships(invm);
		}
		else if (menu == 3)
			break;
		else
		{
			cout << "Which number did you put in? It wasn't one of the options above. Silly.\n";
			cout << "Should try that again.\n";
		}

	} while (menu != 3);

	fileoutput(invm);

}; //end menusystem

void receiveships(Inventory &invr)
{
	cout << "\nShipment Processing\n";
	cout << "Widgets will be looked up by number.\n";

	string name,
		desc;
	int idnum;
	cout << "Please enter the number of the Widget you would like to receive: ";
	cin >> idnum;
	cout << "\nAnd the single word name: ";
	cin >> name;
	cout << "\nAnd a single word description: ";
	cin >> desc;

	Widget widge(idnum, name, desc);
	invr.receive(widge);

	cout << "Shipment processed. Returning to main menu.\n\n";

}; //end rships

void processorder(Inventory &invo)
{
	cout << "\nOrder Processing\n";
	cout << "Widgets will be looked up by number.\n";

	string name,
		desc;
	int idnum;

	cout << "Please enter the number of the Widget you would like to order: ";
	cin >> idnum;
	cout << "\nAnd the single word name: ";
	cin >> name;
	cout << "\nAnd a single word description: ";
	cin >> desc;

	Widget widge(idnum, name, desc);
	invo.order(widge);

	cout << "Order processed. Returning to main menu.\n\n";

}; //end porder

void fileoutput(Inventory invf) 
{
	//this replaces the current txt files with the new lists generated throughout
	//the running of the program
	ofstream outorder("Out Orders.txt");
	ofstream outhand("Out Hands.txt");

	invf.returnorder(outorder);

	char oldordername[] = "Out Orders.txt";
	char newordername[] = "Order List.txt";

	outorder.close();
	remove("Order List.txt");
	rename(oldordername, newordername);

	char oldname[] = "Out Hands.txt";
	char newname[] = "On Hand.txt";

	invf.returnhand(outhand);

	outhand.close();
	remove("On Hand.txt");
	rename(oldname, newname);

}; //end file output