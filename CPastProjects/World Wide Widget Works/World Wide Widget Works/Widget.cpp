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
#include <string>
#include "Widget.h"

using namespace std;


Widget::Widget()
{
	idNumber = 00000;
	name = " ";
	descrip = " ";
};

Widget::Widget(int id)
{
	idNumber = id;
	name = " ";
	descrip = " ";
};

Widget::Widget(int id, string n)
{
	idNumber = id;
	name = n;
	descrip = " ";
};

Widget::Widget(int id, string n, string d)
{
	idNumber = id;
	name = n;
	descrip = d;
};


//copy constructor?

//destructor?

//accessors
int Widget::getID()
{
	return idNumber;
};

string Widget::getName()
{
	return name;
};

string Widget::getDesc()
{
	return descrip;
};


//mutators
void Widget::setID(int id)
{
	idNumber = id;
};

void Widget::setName(string n)
{
	name = n;
};

void Widget::setDesc(string d)
{
	descrip = d;
};

void Widget::setAll(int id, string n, string d)
{
	idNumber = id;
	name = n;
	descrip = d;
};


//operator overloads
void Widget::operator=(Widget &right)
{
	idNumber = right.idNumber;
	name = right.name;
	descrip = right.descrip;
};

bool Widget::operator==(const Widget &right)
{
	Widget temp = right;

	if (idNumber == temp.idNumber)
		return true;
	else
		return false;
};

bool Widget::operator<(Widget &right)
{
	return idNumber < right.idNumber;
};

ostream &operator<<(ostream &strm, const Widget &right)
{
	strm << "Id Number: " << right.idNumber << "\nName: " << right.name << "\nDescription: " << right.descrip;
	return strm;
};