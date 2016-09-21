/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 6, Phone Book Vector - 9/30/2012
		(Extra Credit)

	Description: Create a named PhoneBookEntry that has members for a
		person's name and phone number. Write a program that creates at least
		5 PhoneBookEntry objects and stores them in a vector. After they are stored
		in the vector, use a loop to display the contents of each object.

*/

#include <iostream>
#include <vector>
#include <string>
#include "PhoneBookEntry.h"

using namespace std;

void displayVector(PhoneBookEntry);

int main()
{
	vector<PhoneBookEntry> littleblackbook(5);

	//loading the current 5 slots in the vector with crap
	littleblackbook[0].setAll("Drew", "Sapundjieff", "469-644-8475");
	littleblackbook[1].setName("John", "Dawdy");
	littleblackbook[2].setFName("Jason");
	littleblackbook[3].setAll("Mike", "Jackson", "770-655-5242");
	littleblackbook[4].setLName("Stasiette");

	//little heads-up message
	cout << "This little vector program will step through the vector and display the contents.\n";

	//this is set up to run as long as the vector is by using the vector's size method
	for (int count = 0; count < littleblackbook.size(); count++)
	{
		displayVector(littleblackbook[count]);
	} //end for

	cout << "Thanks for visiting.\n";
	cout << "\n";
	system("pause");
	return 0;
};

//function displayVector accepts one PhoneBookEntry object
//nothing is altered in the contents of the PBE object, simply displays the
//attributes of the PBE object
void displayVector(PhoneBookEntry boy)
{
	cout << "Name: "<< boy.getName() << "\n";
	cout << "Number: " << boy.getNumber() << "\n";
	cout << "\n";
};