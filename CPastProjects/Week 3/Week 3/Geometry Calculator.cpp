/* CIST 2361
	Chapter 4 - Geometry Calculator
	
	Author: Kimberly Jackson
	SID: 0332

	Description: Program will prompt user for choice of which area to calculate,
	which numbers to use in the calculation, and display the results. Also,
	verify if the numbers are of the appropriate type for calculation.
*/

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

//Create three separate modules for the three menu choices.
void CircleArea();
void RectArea();
void TriArea();

//Begin the main function.
int main() {

	int menuOption;//Integer for the menu options.
	bool menuTrue = false,
		affirm = false; //Set up for the loop.
	char redo; //This will be to set the bool for the loop after the initial run.

	//Splash message.
	cout << "Welcome to the Geometry Calculator.\n";
	cout << "A simple menu will be displayed below. Please enter in\n";
	cout << "which menu option you would like to use as a whole number.\n";
	cout << "No periods or spaces or letters requires.\n";
	
	//The menu will be enclosed in a loop.
	while (menuTrue != true) {
	cout << "\n";
	cout << "\t1. Calculate the Area of a Circle.\n";
	cout << "\t2. Calculate the Area of a Rectangle.\n";
	cout << "\t3. Calculate the Area of a Triangle.\n";
	cout << "\t4. Quit.\n";
	cout << "\n\tEnter your choice (1-4): ";
	cin >> menuOption;

	//Begin the switch statement.
	switch (menuOption)
	{
	case 1:
		{ //Call the Circle module.
			CircleArea();
			break;
		}
	case 2:
		{ //Call the Rectangle module.
			RectArea();
			break;
		}
	case 3:
		{ //Call the Triangle module.
			TriArea();
			break;
		}
	case 4:
		{ //Quit the program. Set the bool to true.
			cout << "\nYou have chosen to quit. Thank you for coming!\n";
			menuTrue = true;
			break;
		}
	default:
		{ //Outside the 1-4 option.
			cout << "Incorrect option entered. Program will restart.\n";
		}
	}

	//Ask if the user would like to go again. If bool was set to true, this will not be displayed.
	while (affirm != false)
	{
	cout << "\n";
	cout << "Would you like to calculate another area?\n";
	cout << "Please key in either Y or N to run the program again.\n";
	cout << "Only Y or N please, no g or t or something.\n";
	cout << "\n";
	cin >> redo;

	//Reset the bool.
	if (toupper(redo) == 'Y')
		affirm = true;
	else
		affirm = false;
	
	} //This is the end of the outer loop.

	system ("pause");
	return 0;
	}
}

void CircleArea() { 
	//Option 1 is to calcuate the area of a circle.
	//Start the variables.
	const double PI = 3.14159;
	double radius; //For the radius.
	bool affirm = false; //For the loop.
	char truth = 'n';

	//Begin the prompts.
	while (affirm !=true)
	{
	cout << "\n";
	cout << "To find the area of a circle, the calculation is\n";
	cout << "pi times the radius of the circle squared.\n";
	cout << "For the purposes of this program, all you have to\n";
	cout << "enter is the radius. Numbers and decimals only, please.\n";
	cout << "That means no need for spaces or units of measure.\n";
	cin >> radius;

	//Test the number entered.
	if (radius < 0)
	{
		cout << "You have entered a negative number. This program\n";
		cout << "does not work with negative numbers. Please enter again.\n";
		bool affirm = false;
	}
	else
		affirm = true;

	cout << "\n";
	cout << "The number you have entered is: " << radius << endl;
	cout << "Is this number correct?\n";
	cout << "Only Y or N please.\n";
	cin >> truth;

	if (toupper(truth) == 'Y')
		affirm = true;

	cout << fixed << setprecision(2) << endl;
	cout << "\n";
	cout << "The area of the circle with a radius of " << radius << endl;
	cout << PI * (radius * radius) << endl;
	cout << "\n";

	cout << "Would you like to calculate another circle?\n";
	cin >> truth;

	if (toupper(truth) == 'Y')
		affirm = false;
	}
}

void RectArea() {
	double length,
		width;
	bool affirm = false; //For the loop.
	char truth = 'n';

	//Begin the prompts.
	while (affirm !=true)
	{
	cout << "\n";
	cout << "To find the area of a rectangle, the calculation is\n";
	cout << "length times width. Simple, huh?\n";
	cout << "For the purposes of this program, all you have to\n";
	cout << "enter is the length and the width.\n";
	cout << "Numbers and decimals only, please.\n";
	cout << "That means no need for spaces or units of measure.\n";
	cout << "But first, the length.\n";
	cin >> length;

	//Test the number entered.
	if (length < 0)
	{
		cout << "You have entered a negative number. This program\n";
		cout << "does not work with negative numbers. Please enter again.\n";
		bool affirm = false;
	}
	else
		affirm = true;

	cout << "\n";
	cout << "The number you have entered is: " << length << endl;
	cout << "Is this number correct?\n";
	cout << "Only Y or N please.\n";
	cin >> truth;

	if (toupper(truth) == 'Y')
		affirm = true;

	cout << "And now, the width.\n";
	cin >> width;

	if (width < 0)
	{
		cout << "You have entered a negative number. This program\n";
		cout << "does not work with negative numbers. Please enter again.\n";
		bool affirm = false;
	}
	else
		affirm = true;

	cout << "\n";
	cout << "The number you have entered is: " << width << endl;
	cout << "Is this number correct?\n";
	cout << "Only Y or N please.\n";
	cin >> truth;

	if (toupper(truth) == 'Y')
		affirm = true;

	cout << fixed << setprecision(2) << endl;
	cout << "\n";
	cout << "The area of the rectangle with a length of " << length << endl;
	cout << "and a width of "<< width << endl;
	cout << length * width << endl;
	cout << "\n";

	cout << "Would you like to calculate another rectangle?\n";
	cin >> truth;

	if (toupper(truth) == 'Y')
		affirm = false;
	}
}

void TriArea() {
	double base,
		height;
	bool affirm = false; //For the loop.
	char truth = 'n';

	//Begin the prompts.
	while (affirm !=true)
	{
	cout << "\n";
	cout << "To find the area of a triangle, the calculation is\n";
	cout << "base times height times .5\n";
	cout << "For the purposes of this program, all you have to\n";
	cout << "enter is the base and the height.\n";
	cout << "Numbers and decimals only, please.\n";
	cout << "That means no need for spaces or units of measure.\n";
	cout << "But first, the base.\n";
	cin >> base;

	//Test the number entered.
	if (base < 0)
	{
		cout << "You have entered a negative number. This program\n";
		cout << "does not work with negative numbers. Please enter again.\n";
		bool affirm = false;
	}
	else
		affirm = true;

	cout << "\n";
	cout << "The number you have entered is: " << base << endl;
	cout << "Is this number correct?\n";
	cout << "Only Y or N please.\n";
	cin >> truth;

	if (toupper(truth) == 'Y')
		affirm = true;

	cout << "And now, the height.\n";
	cin >> height;

	if (height < 0)
	{
		cout << "You have entered a negative number. This program\n";
		cout << "does not work with negative numbers. Please enter again.\n";
		bool affirm = false;
	}
	else
		affirm = true;

	cout << "\n";
	cout << "The number you have entered is: " << height << endl;
	cout << "Is this number correct?\n";
	cout << "Only Y or N please.\n";
	cin >> truth;

	if (toupper(truth) == 'Y')
		affirm = true;

	cout << fixed << setprecision(2) << endl;
	cout << "\n";
	cout << "The area of the triangle with a length of " << base << endl;
	cout << "and a height of "<< height << endl;
	cout << base * height * .5 << endl;
	cout << "\n";

	cout << "Would you like to calculate another rectangle?\n";
	cin >> truth;

	if (toupper(truth) == 'Y')
		affirm = false;
	}
}