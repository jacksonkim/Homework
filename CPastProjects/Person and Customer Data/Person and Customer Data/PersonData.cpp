/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	
	Week 4, Program 1, PersonData and CustomerData
		or Mailing List Registration - 9/14/2012


*/

#include <string>
#include "PersonData.h"

using namespace std;

//constructors
PersonData::PersonData()
{
	firstName = "Current";
	lastName = "President";
	address = "1600 Pennsylvania Ave";
	city ="Washington";
	state = "DC";

	zip = 20500;
	phone = "202-456-1111";
};


PersonData::PersonData(std::string fn, std::string ln, std::string a, std::string c, std::string s, int z, std::string p)
{
	firstName = fn;
	lastName = ln;
	address = a;
	city =c;
	state = s;

	zip = z;
	phone =p;
};

//mutators

void PersonData::setFirst(std::string fn)
{
	firstName = fn;
};


void PersonData::setLast(std::string ln)
{
	lastName = ln;
};


void PersonData::setAddress(std::string a)
{
	address = a;
};


void PersonData::setCity(std::string c)
{
	city = c;
};


void PersonData::setState(std::string s)
{
	state = s;
};


void PersonData::setZip(int z)
{
	zip = z;
};


void PersonData::setPhone(std::string p)
{
	phone = p;
};

void PersonData::setAll(std::string fn, std::string ln, std::string a, std::string c, std::string s, int z, std::string p)
{
	firstName = fn;
	lastName = ln;
	address = a;
	city =c;
	state = s;

	zip = z;
	phone =p;

};
	
//accessors

std::string PersonData::getFirst() const
{
	return firstName;
};


std::string PersonData::getLast() const
{
	return lastName;
};


std::string PersonData::getAddress() const
{
	return address;
};


std::string PersonData::getCity() const
{
	return city;
};


std::string PersonData::getState() const
{
	return state;
};


int PersonData::getZip() const
{
	return zip;
};


std::string PersonData::getPhone() const
{
	return phone;
};