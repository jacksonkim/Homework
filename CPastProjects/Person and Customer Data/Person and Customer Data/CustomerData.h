/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	
	Week 4, Program 1, PersonData and CustomerData
		or Mailing List Registration - 9/14/2012

	Description: Design a class that inherits

*/

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"

class CustomerData : public PersonData
{
private:
	int customerNumber;
	bool mailingList;

public:
	//constructors
	CustomerData();
	CustomerData(int);
	CustomerData(int, bool);

	//mutators
	void setNum(int);
	void setList(bool);

	//accessors
	int getNum() const;
	bool getList() const;

};

#endif //CUSTOMERDATA_H