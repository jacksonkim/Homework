/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 1, Days to Numbers - 9/9/2012
	(Alternate program name: There and Back Again)
	Description: Design a class called NumDays to store a value that represents the
		number of work hours and convert it to a number of days. 
		(8hrs = 1day. 12hrs = 1.5 days)
		Constructor that accepts a number of hours, as well as mutators and accessors.
		Overloaded Operators:
			+ Two NumDay objects are added together, should return the sum of the hours
				members
			- Return the difference of the hours members

			++ Prefix and Postfix increment - Automatically increment the hours member
					This will recalculate the number of days as well.
			-- Prefix and Postfix decrement - Automatically decrement the hours member
				This will recalculate the number of days.

*/

#include <iostream>
#include <iomanip>
#include "NumDays.h"

using namespace std;

void greeting();
void getInput(NumDays&);
void testingPhase1(NumDays, NumDays);
void testingPhase2(NumDays);


int main()
{
	float temp;

	NumDays emp1,
		emp2,
		emp3(16);

	//greeting
	greeting();

	//input
	getInput(emp1);
	getInput(emp2);
	
	testingPhase1(emp1, emp2);
	testingPhase1(emp2, emp3);
	testingPhase1(emp3, emp1);

	cout << "\n";
	cout << "That should be everything. You can finally return home.\n";
	cout << "But that was something on an adventure, wasn't it?\n";
	cout << "\n";
	system("pause");
	return 0;
};

void greeting()
{
	cout << "Welcome to the There and Back Again, a work hour conversion\n";
	cout << "program. You will be asked the number of hours worked and a series\n";
	cout << "of tests will be performed on the numbers. You will be asked for two\n";
	cout << "different work hours, but a third has been loaded for testing.\n";
	cout << "\n";
	cout << "Don't be alarmed. This will be fun! You won't even have to leave the Shire.\n";
	cout << "\n";
};

//function accepts one of the NumDays classes and accepts hours from the user to set up
//the hours and thus the conversion to days that will happen
void getInput(NumDays &empT)
{
	float temp;

	cout << "Please enter the your number: ";
	cin >> temp;

	empT.setHours(temp);

};

//this function accepts two of the NumDays to perform calculations on them to
//demonstrate the functionality of the operater overloading
void testingPhase1(NumDays empT1, NumDays empT2)
{
	NumDays tempT;

	//overloaded +
	tempT = empT1 + empT2;
	cout << "Adding together the two, we get: " << tempT.getHours() 
		<< " hours or "<< tempT.getDays() << " days.\n";

	cout << "\n";

	//overloaded -
	tempT = empT1 - empT2;
	cout << "Subtracting the two, we get: " << tempT.getHours() 
		<< " hours or "<< tempT.getDays() << " days.\n";	

	cout << "\n";
	testingPhase2(empT1);
	cout << "\n";
	testingPhase2(empT2);

	cout << "\n";
	system("pause");
	cout << "\n";
};


//this function accepts one of the NumDays from testingPhase 1 and performs
//all of the increment and decrement steps. this was made because copy and pasting
//code for each one was ridiculous. i'm getting the hang of this function thing, right.
void testingPhase2(NumDays empTa)
{
	//overloaded prefix ++
	++empTa;
	cout << "Prefix incrementing the first one brings us " 
		<< empTa.getHours() << " hours or "<< empTa.getDays() << " days.\n";
	cout << "\n";
	//overloaded postfix ++
	empTa++;
	cout << "Postfix incrementing the first one brings us " 
		<< empTa.getHours() << " hours or "<< empTa.getDays() << " days.\n";
	cout << "\n";
	//overloaded prefix--
	--empTa;
	cout << "Prefix decrementing the first one brings us " 
		<< empTa.getHours() << " hours or "<< empTa.getDays() << " days.\n";
	cout << "\n";
	//overloaded postfix--
	empTa--;
	cout << "Postfix incrementing the first one brings us " 
		<< empTa.getHours() << " hours or "<< empTa.getDays() << " days.\n";
};