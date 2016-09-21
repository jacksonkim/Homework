/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 10, Widget Works Inventory Mgmt - 11/1/12

	Description: Enhance the Widget Works inventory management systems with
		the following:
		-Widgets should also track the name and description of the Widgets
		-The list of widgets should be read from a file when the program starts
		-The list of widgets should be written to a file upon exit
		-Create a menu system to process an order, recieve a shipment, or exit
*/

#include "Widget.h"

using namespace std;

class WidgetTester
{
public:
	Widget testid;

	WidgetTester(Widget &widget)
	{
		testid = widget;
	};

	bool operator()(Widget &wid)
	{
		return wid == testid;
	};
};