/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 10, Widget Works Inventory Mgmt - 11/1/12

	Description: Enhance the Widget Works inventory management systems with
		the following:
		-Widgets should also track the name and description of the Widgets
		-The list of widgets should be read from a file when the program starts
		-The list of widgets should be written to a file upon exit
		-Create a menu system to process an order, recieve a shipment, or exit
*/

#ifndef WIDGET_H
#define WIDGET_H

#include <string>

using namespace std;

class Widget
{
protected:
	int idNumber;
	string name,
		descrip;

public:
	//constructors
	Widget();
	Widget(int);
	Widget(int, string); //idNumber and name
	Widget(int, string, string);

	//copy constructor?

	//destructor? i don't dynamically allocate anything

	//accessors
	int getID();
	string getName();
	string getDesc();

	//mutators
	void setID(int);
	void setName(string);
	void setDesc(string);
	void setAll(int, string, string);

	//operator overloads
	void operator=(Widget &);
	//below are based solely on id number as they are unique
	//name and description are flavour text
	bool operator==(const Widget &);
	bool operator<(Widget &);

	//overloaded out chevron
	friend ostream &operator<<(ostream &, const Widget &);	

};

#endif //WIDGET_H