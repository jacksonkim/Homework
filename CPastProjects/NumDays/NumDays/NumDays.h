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
#ifndef NUMDAYS_H
#define NUMDAYS_H

using namespace std;

class NumDays
{
private:
	//members
	float hours;
	float days;

	//for setting the days
	void convertToDays();

public:
	//constructors
	NumDays();
	NumDays(float);
	NumDays(float, float);

	//mutators
	void setHours(float);
	void setDays(float);
	
	//accessors
	float getHours();
	float getDays();

	//operator overloading
	NumDays operator+(const NumDays &);
	NumDays operator-(const NumDays &);

	NumDays operator++();
	NumDays operator++(int);

	NumDays operator--();
	NumDays operator--(int);

};

#endif //NUMDAYS_H