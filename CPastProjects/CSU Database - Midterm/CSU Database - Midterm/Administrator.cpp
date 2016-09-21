/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 7, CSU Database - Midterm - 10/9/12

	Description: Class to hold the login information for the administrators.
		

*/
#include "Administrator.h"

using namespace std;

//constructors
Administrator::Administrator()
{
	username = " ";
	password = " ";
};

Administrator::Administrator(string un, string p)
{
	username = un;
	password = p;
};


//mutators
void Administrator::setUser(string un)
{
	username = un;
};

void Administrator::setPass(string p)
{
	password = p;
};

void Administrator::setAll(string un, string p)
{
	username = un;
	password = p;
};

//accessors
string Administrator::getUser()
{
	return username;
};

string Administrator::getPass()
{
	return password;
};