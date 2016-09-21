/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 7, CSU Database - Midterm - 10/1/12

	Description: The Undergraduate class has at least the following responsibilities:
    -    The student's classification: Freshman, Sophomore, Junior, Senior

	*/

#include "Undergraduate.h"

//constructors
Undergraduate::Undergraduate()
{
	studentClass = "Classification not set";
};

Undergraduate::Undergraduate(string sc)
{
	studentClass = sc;
};


//mutators
void Undergraduate::setClass(string sc)
{
	studentClass = sc;
};


//accessors
string Undergraduate::getClass() const
{
	return studentClass;
};

//StudentType Undergraduate::studentTest()
//{
//	return UGRAD;
//};