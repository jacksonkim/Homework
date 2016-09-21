/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	
	Week 4, Program 1, PersonData and CustomerData
		or Mailing List Registration - 9/14/2012


*/

#include <iostream>
#include "CustomerData.h"

using namespace std;

CustomerData::CustomerData()
{
	customerNumber = 00000;
	mailingList = false;
};

//constructor accepts an integer value to set the value of customerNumber
CustomerData::CustomerData(int cn)
{
	customerNumber = cn;
	mailingList = false;
};

//accepts an integer value to set the value of customerNumber and a boolean
//to set whether or not the customer wishes to be on the mailing list
CustomerData::CustomerData(int cn, bool ml)
{
	customerNumber = cn;
	mailingList = ml;
};


//mutators

//accepts an integer value to set the value of customerNumber
void CustomerData::setNum(int cn)
{
	customerNumber = cn;
};

//accepts a boolean value to set the value of mailingList based on if the
//customer wishes to be on the mailing list
void CustomerData::setList(bool ml)
{
	mailingList = ml;
};


//accessors

//accepts no arguments and returns in value of the current value of customerNumber
int CustomerData::getNum() const
{
	return customerNumber;
};

//accepts no arguments and returns the current value of mainlingList
bool CustomerData::getList() const
{
	return mailingList;
};