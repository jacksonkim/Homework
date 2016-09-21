/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 4, Program 2, Ship Manifest - 9/16/12

	Description: Ship class should have the following members:
		-Member for the name of the ship (string)
		-Member for the year that the ship was built (string)
		-Constructor and appropriate accessors and mutators
		-Virtual print function that displays the ship's name and year built

*/

#include <iostream>
#include <string>
#include "Ship.h"

using namespace std;

Ship::Ship()
{
	name = "McButt";
	yearBuilt = "2012";
};


Ship::Ship(std::string yb)
{
	name = "McButt";
	yearBuilt = yb;
};


Ship::Ship(std::string n, std::string yb)
{
	name = n;
	yearBuilt = yb;
};


//mutators
void Ship::setName(std::string n)
{
	name = n;
};


void Ship::setYearBult(std::string yb)
{
	yearBuilt = yb;
};



//accessors
std::string Ship::getName()
{
	return name;
};

std::string Ship::getYearBuilt()
{
	return yearBuilt;
};

void Ship::print() const
{
	cout << "\n";
	cout << "Ship's callsign: " << Ship::name << "\n";
	cout << "The year this ship was built is: " << Ship::yearBuilt << ".\n";
	cout << "\n";
};
