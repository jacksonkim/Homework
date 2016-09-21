/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	
	Week 4, Program 1, PersonData and CustomerData
		or Mailing List Registration - 9/14/2012

	Description: Base Class designed to hold the data for a person, including name,
		address, phone number. This data should be accessed by the other classes.

*/

#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <string>

class PersonData
{
protected:
	std::string lastName,
		firstName,
		address,
		city,
		state, //almost made state a char array of like 2. maybe later.
		phone; 

	int zip; //these two are ints because they don't need to be strings.
					//it would be harder to compare them as strings. this forces them to always be
					//one length and setup. none of that (000)-000-0000 crap. 0000000000

public:
	//constructors
	PersonData();
	PersonData(std::string, std::string, std::string, std::string, std::string, int, std::string);

	//mutators
	void setFirst(std::string);
	void setLast(std::string);
	void setAddress(std::string);
	void setCity(std::string);
	void setState(std::string);
	void setPhone(std::string);

	void setZip(int);
	
	void setAll(std::string, std::string, std::string, std::string, std::string, int, std::string);
	
	//accessors
	std::string getFirst() const;
	std::string getLast() const;
	std::string getAddress() const;
	std::string getCity() const;
	std::string getState() const;
	std::string getPhone() const;

	int getZip() const;
	
};

#endif //PERSONDATA_H