/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 6, Phone Book Vector - 9/30/2012
		(Extra Credit)

	Description: Create a named PhoneBookEntry that has members for a
		person's name and phone number. Write a program that creates at least
		5 PhoneBookEntry objects and stores them in a vector. After they are stored
		in the vector, use a loop to display the contents of each object.

*/

#include <string>
#include "PhoneBookEntry.h"

using namespace std;

//default constructor
PhoneBookEntry::PhoneBookEntry()
{
	fname = " ";
	lname = " ";
	number = " ";
};

//constructor 2 accepts three strings to set all three attributes to user input
PhoneBookEntry::PhoneBookEntry(string fn, string ln, string pn)
{
	fname = fn;
	lname = ln;
	number = pn;
};

//mutators

//function setFname accepts one argument
//that one argument is set to the first name attribute
void PhoneBookEntry::setFName(string fn)
{
	fname = fn;
};

//function setLName accepts one argument
//that one argument is set to the last name attribute
void PhoneBookEntry::setLName(string ln)
{
	lname = ln;
};

//function setNumber accepts one argument
//that argument is set to the number attribute
void PhoneBookEntry::setNumber(string pn)
{
	number = pn;
};

//function setName accepts two string arguments
//first argument is the first name attribute
//second argument is the last name attribute
void PhoneBookEntry::setName(string fn, string ln)
{
	fname = fn;
	lname = ln;
};

//function setAll accepts three string arguments
//sets the first argument to the first name attribute
//sets the second argument to the last name attribute
//sets the third argument to the number attribute
void PhoneBookEntry::setAll(string fn, string ln, string pn)
{
	fname = fn;
	lname = ln;
	number = pn;
};

//accessors

//function getFname returns the first name attribute
//accepts no arguments
string PhoneBookEntry::getFName()
{
	return fname;
};

//function getLName returns the last name attribute
//accepts no arguments
string PhoneBookEntry::getLName()
{
	return lname;
};

//function getNumber returns the phone number attribute
//accepts no arguments
string PhoneBookEntry::getNumber()
{
	return number;
};

//function getName accepts no arguments
//returns an appended string that combines the first and last name attributes
//with a space.
string PhoneBookEntry::getName()
{
	string wholename = fname;
	wholename.append(" ");
	wholename.append(lname);

	return wholename;	
};