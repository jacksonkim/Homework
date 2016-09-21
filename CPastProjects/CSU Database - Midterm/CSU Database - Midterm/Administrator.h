/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 7, CSU Database - Midterm - 10/9/12

	Description: Class to hold the login information for the administrators.
		

*/
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>

using namespace std;

class Administrator
{
private:
	string username,
		password;

public:
	//constructors
	Administrator();
	Administrator(string, string);

	//mutators
	void setUser(string);
	void setPass(string);
	void setAll(string, string);

	//accessors
	string getUser();
	string getPass();

};

#endif //ADMINISTRATOR_H