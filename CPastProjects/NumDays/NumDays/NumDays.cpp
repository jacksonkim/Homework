/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 1, Days to Numbers - 9/9/2012
	(Alternate program name: There and Back Again)
	Description: Design a class called NumDays to store a value that represents the
		number of work hours and convert it to a number of days. 
		(8hrs = 1day. 12hrs = 1.5 days)
		Constructor that accepts a number of hours, as well as mutators and accessors.
		Overloaded Operators:
			+ Two NumDay objects are added together, should return the sum of the hours
				members
			- Return the difference of the hours members

			++ Prefix and Postfix increment - Automatically increment the hours member
					This will recalculate the number of days as well.
			-- Prefix and Postfix decrement - Automatically decrement the hours member
				This will recalculate the number of days.

*/
#include <iostream>
#include "NumDays.h"

using namespace std;

const int WORKHOURS= 8;

//default constructor
NumDays::NumDays()
{
	hours = 0;
	days = 0;
};

//constructor 2
NumDays::NumDays(float h)
{
	hours = h;
	convertToDays();
};

//constructor 3
NumDays::NumDays(float h, float d)
{
	hours = h;
	days = d;
};

//mutators

//accepts an int to set the number of hours
void NumDays::setHours(float h)
{
	hours = h;
	convertToDays();
};

//accepts a float to set the number of days
void NumDays::setDays(float d)
{
	days = d;
};

//for converting hours into days
void NumDays::convertToDays()
{
	days = hours/WORKHOURS;
};

//accessors

//returns the current value of hours
float NumDays::getHours()
{
	return hours;
};

//returns the current value of days
float NumDays::getDays()
{
	return days;
};

//operator overloading
NumDays NumDays::operator+(const NumDays &right)
{
	NumDays temp;

	temp.hours = hours + right.hours;
	temp.days = days + right.days;
	temp.convertToDays();
	return temp;

};


NumDays NumDays::operator-(const NumDays &right)
{
	NumDays temp;

	temp.hours = hours - right.hours;
	temp.days = days - right.days;
	temp.convertToDays();
	return temp;
};


NumDays NumDays::operator++()
{
	++hours;
	convertToDays();
	return *this;
};

NumDays NumDays::operator++(int)
{
	NumDays temp(hours, days);
	hours++;
	convertToDays();
	return temp;
};


NumDays NumDays::operator--()
{
	--hours;
	convertToDays();
	return *this;
};


NumDays NumDays::operator--(int)
{
	NumDays temp(hours, days);
	hours--;
	convertToDays();
	return temp;
};