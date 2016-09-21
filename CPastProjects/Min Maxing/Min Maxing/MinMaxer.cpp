/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	
	Week 6, Min/Max Template Program - 9/30/2012

	Description: Create 2 templates. The minimum template should accept two arguments
		and return the value of the one that is the lesser of the two. As expected, maximum
		should return the higher of the two.

		Design a simple driver program that demonstrates these things happening.

*/

#include <iostream>

using namespace std;

template <class T>
//template accepts two arguments of the same data type and returns the same data type as the arguments
//all it does is test which of the two numbers is the smaller and returns that number
T minimum(T num1, T num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
	//this if statement is set up to return the first number passed into it if it is the smaller
	//and to return the other one if the first one ends up not less than the second number
	//this ensures that the correct number is returned.
};

template <class T>
//template accepts two arguments of the same data type and returns the same data type as the arguments
//all it does is test which of the two numbers is the larger and returns that number
T maximum(T num1, T num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;
	//this if is set up opposite to the minimum one because it is testing which is larger
	//again, if the first number is not larger, then the second number must be the larger
};

void integerMinMax(); //i set up different functions for testing different numbers
void doubleMinMax(); //because input has to match a data type.

int main()
{
	int menuOption; //variable for the menu below

	do //this is a do obviously so it can run at least once
	{
		//it occurred to me that any number that the user put in would have to do into a specific
		//data type, hence this menu asking. i left out strings and floats because floats and doubles
		//are both decimal numbers, so i stuck with doubles. strings are a whole different animal,
		//so i left those out too.
		cout << "This program will determine the lowest or highest number of two numbers.\n";
		cout << "We have provided two different options for you.\n\n";
		cout << "1. Regular whole numbers\n";
		cout << "2. Numbers with decimal points\n";
		cout << "3. Exit";
		cout << "  (Okay maybe three options)\n";
		cout << "Please input a menu option: "; 
		cin >> menuOption;
		//i discovered this in java. don't put a \n and you can have the input following the question. 
		//though i guess it was done in C++ i just didn't pay attention. :I

		//only 3 options, no need for a switch
		if (menuOption == 1)
		{
			cout << "\n"; //for formatting
			integerMinMax(); //call the whole numbers function
		}
		else if (menuOption == 2)
		{
			cout << "\n";
			doubleMinMax(); //decimal points function
		}
		else
			cout << "Thanks for your patronage.\n"; //this is for the exit option
	} while (menuOption != 3);
	
	//this is my standard exit trio. a line for the system pause display, then the return 0 for int main
	cout << "\n";
	system("pause");
	return 0;
};

//function integerMinMax accepts no arguments, returns nothing
//it is set up with a menu to determine the larger or smaller between two different numbers
//all variables are inside the function and are not used anywhere except the templates
void integerMinMax()
{
		int menu, //that's right, another menu
			n1, //these aren't going to be used anywhere else but here and in the template
			n2; //so why make them anywhere else, amirite?
		
		do
		{ 
			//set up a menu because it seems silly, since there are two numbers, to show both numbers
			//again. which one is the smallest. the other one must be the larger of the two, right?
			cout << "Now, time to choose from another option below.\n";
			cout << "Would you like to figure out the\n";
			cout << "1. Minimum\n";
			cout << "2. Maximum\n";
			cout << "3. Or exit?\n";
			cout << "Please enter in an option: ";
			cin >>menu;

			if (menu == 1) //for the minimum
			{
				cout << "Please input the first number: ";
				cin >> n1;
				cout << "\nAnd then the second number: ";
				cin >> n2;
				
				cout << "\nThe smaller of the two numbers is " << minimum(n1, n2) << ".\n";
			}
			else if (menu == 2) //for the maxipad
			{
				cout << "Please input the first number: ";
				cin >> n1;
				cout << "\nAnd then the second number: ";
				cin >> n2;

				cout << "\nThe larger of the two numbers is " << maximum(n1, n2) << ".\n";
			}
			else //for the exit option, or any other number besides 1 and 2. i accidentally put in 264 and it
					//displayed this message and ran the menu again
				cout << "I guess you didn't want to do whole numbers anymore?\n";

		} while (menu != 3); //once they pick 3, it goes back out to the main menu
};

//function doubleMinMax accepts no arguments, returns nothing
//it is set up with a menu to determine the larger or smaller between two different numbers
//all variables are inside the function and are not used anywhere except the templates
void doubleMinMax()
{
		int menu; //that's right, another menu
		double n1, //these aren't going to be used anywhere else but here and in the template
			n2; //so why make them anywhere else, amirite?
		
		do
		{
			cout << "Now, time to choose from another option below.\n";
			cout << "Would you like to figure out the\n";
			cout << "1. Minimum\n";
			cout << "2. Maximum\n";
			cout << "3. Or exit?\n";
			cout << "Please enter in an option: ";
			cin >>menu;

			//set up a menu because it seems silly, since there are two numbers, to show both numbers
			//again. which one is the smallest. the other one must be the larger of the two, right?
			if (menu == 1) //for the minimum
			{
				cout << "Please input the first number: ";
				cin >> n1;
				cout << "\nAnd then the second number: ";
				cin >> n2;

				cout << "\nThe smaller of the two numbers is " << minimum(n1, n2) << ".\n";
			}
			else if (menu == 2) //maxiumum
			{
				cout << "Please input the first number: ";
				cin >> n1;
				cout << "\nAnd then the second number: ";
				cin >> n2;

				cout << "\nThe larger of the two numbers is " << maximum(n1, n2) << ".\n";
			}
			else //anything besides 1 or 2.
				cout << "I guess you didn't want to do whole numbers anymore?\n";

		} while (menu != 3); //once they put in 3, it goes back out to the main menu
};