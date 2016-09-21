/* CIST 2361
	Chapter 4 - Book Club Points
	
	Author: Kimberly Jackson
	SID: 0332

	Description: Program will prompt user for information regarding the number
	of books purchased over the last month and display the number of points
	awarded depending on the amount of books.
*/

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

//Some global constants to for the level of book purchases. These are global
//constants for ease of raising/changing the ranges in the future and
//altering the program so this information is available somewhere else
//in the program. Looking ahead here.
const int level0book = 0, //For the purchase of 0 books.
	level0points = 0, //Points for level 0.
	level1book = 1, //Purchase of 1 book.
	level1points = 5, //Points for level 1.
	level2book = 2, //Purchase of 2 books.
	level2points = 15, //Points for level 2.
	level3book = 3, //Purchase of 3 books.
	level3points = 30, //Points for level 3.
	level4book = 4, //Purchase of 4 books.
	level4points = 60; //Points awarded at level 4.


//Extra modules for displaying of message and if statement.
void WelcomeMessage();

//Module for the If statement.
void PointTest(int);

//Begin execution of main program.

int main() {

	int numOfBooks; //User's number of books purchased over the last month.

	char valid='n'; //Char used to determine whether or not the above entry is correct.

	//Call the first message module.
	WelcomeMessage();

	//Extra space.
	cout << endl;

	//Begin the While loop for validation.
	while (toupper(valid) !='Y') {
		//Prompt for purchase of books over the last month and instructions.
		cout << "To begin, please enter in the amount of books you have\n";
		cout << "purchased over the last month. Only whole numbers, please.\n";
		cout << "No need for anything extra, just a number like 2 or 5.\n";
		cout << "(I mean, really, we don't sell partial books.\n";
		cout << "At least,I try not to.)" << endl;
		cin >> numOfBooks; //Variable for number of books purchased over the last month.

		//Validate the above input.
		cout << "The amount of books purchased you entered was: " << numOfBooks << "\n";
		cout << "Is this amount correct?\n";
		cout << "If it is, please enter in the letter Y alone. If not, please enter in\n";
		cout << "any other single letter. But only one letter, please!" << endl;
		cin >> valid;
		//End the loop here.
	}
		

		//Send the correct number of books to the If module.
		PointTest(numOfBooks);

		//End of program. All functions should be completed here.
		system("pause");
		return 0;
	}

void WelcomeMessage() {
	
	//Welcome message and explanation of benefits.
	cout << "Welcome to Aspired Creativity's Book Club!\n";
	cout << endl;
	cout << "Each month, book club members are awarded a certain number\n";
	cout << "of points based on the amount of books purchased that month.\n";
	cout << endl;
	cout << "When you accrue enough of these points, you can redeem them\n";
	cout << "for a number of different prizes such as coupons or merchandise.\n";
	cout << "\n";
	cout << "This program will calculate the number of points you will be\n";
	cout << "awarded this month.\n";
	cout << endl;

	system ("pause");
}

	

void PointTest(int numOfBooks1) {

	//Being the If statement to test for the range of numbers.
	if (numOfBooks1 >= level4book) //Start with the highest level to rule out larger numbers.
		{ 
			cout << "You have purchased " << numOfBooks1 << " which awards you " << level4points << "!\n";
			cout << "Congratulations!" << endl;
		}
	else if(numOfBooks1 == level3book) //Work your way lower.
		{
			cout << "You have purchased " << numOfBooks1 << " which awards you " << level3points << "!\n";
			cout << "Congratulations!" << endl;
		}
	else if(numOfBooks1 == level2book) //Down the stairs.
		{
			cout << "You have purchased " << numOfBooks1 << " which awards you " << level2points << "!\n";
			cout << "Congratulations!" << endl;
		}
	else if(numOfBooks1 == level1book) //Almost at the end.
		{
			cout << "You have purchased " << numOfBooks1 << " which awards you " << level1points << "!\n";
			cout << "Congratulations!" << endl;
		}
	else if(numOfBooks1 == level0book) //Last one.
		{
			cout << "You have purchased " << numOfBooks1 << " which awards you " << level0points << "!\n";
			cout << endl;
		}
	else //Ground floor!
	{
			cout << "Invalid number or < " << level0book << " books.";
			cout << endl;
	}

}