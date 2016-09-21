/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 6, Phone Book Vector - 9/30/2012
		(Extra Credit)

	Description: Create a named PhoneBookEntry that has members for a
		person's name and phone number. Write a program that creates at least
		5 PhoneBookEntry objects and stores them in a vector. After they are stored
		in the vector, use a loop to display the contents of each object.

*/

#ifndef PHONEBOOKENTRY_H
#define PHONEBOOKENTRY_H

using namespace std; //i have to put this everywhere i guess or it doesn't know

class PhoneBookEntry
{
private:
	string fname,
		lname, //i feel that separating the first and last name is important
		number; //i would use an int for this, but ints can't hold phone numbers. they are toooo big

public:
	//constructors
	PhoneBookEntry();
	//accept three arguments to set all attributes of class
	PhoneBookEntry(string, string, string);

	//mutators
	void setFName(string);
	void setLName(string);
	void setNumber(string);
	//accepts two arguments to set the first and last name at one time
	void setName(string, string);
	//accepts three arguments to set all of the attributes at one time
	void setAll(string, string, string);

	//accessors
	string getFName();
	string getLName();
	string getNumber();
	string getName();

};

#endif //PHONEBOOKENTRY_H