/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 7, CSU Database - Midterm - 10/1/12

	Description: The Graduate class has at least the following responsibilities:
    -    The Degree type: Specialist, Master, Doctorate
    -    Thesis Topic

	*/

#include "Graduate.h"

//constructors
Graduate::Graduate()
{
	studentDegree = "Degree Type not chosen";
	thesisTopic = "Thesis not stated";
};

Graduate::Graduate(string d)
{
	studentDegree = d;
	thesisTopic = "Thesis not stated";
};

Graduate::Graduate(string d, string tt)
{
	studentDegree = d;
	thesisTopic = tt;
};


//mutators
void Graduate::setDegree(string d)
{
	studentDegree = d;
};

void Graduate::setThesis(string tt)
{
	thesisTopic = tt;
};

void Graduate::setBoth(string d, string tt)
{
	studentDegree = d;
	thesisTopic = tt;
};


//accessors
string Graduate::getDegree() const
{
	return studentDegree;
};

string Graduate::getThesis() const
{
	return thesisTopic;
};

//StudentType Graduate::studentTest()
//{
//	return GRAD;
//};