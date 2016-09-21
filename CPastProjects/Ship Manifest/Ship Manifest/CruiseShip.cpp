/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 4, Program 2, Ship Manifest - 9/16/12

	Description: CruiseShip class, derived from Ship class, should have the following members:
		-Member for the maximum number of passengers (int)
		-Constructor and appropriate accessors and mutators
		-print function that overrides Ship's and displays the ship's name and max passengers

*/

#include <iostream>
#include <string>
#include "Ship.h"
#include "CruiseShip.h"

using namespace std;

CruiseShip::CruiseShip()
{
	maxPassenger = 2200;
};


CruiseShip::CruiseShip(int p)
{
	maxPassenger = p;
};

CruiseShip::CruiseShip(std::string n, std::string yb, int p) : Ship(n, yb)
{
	maxPassenger = p;
};


//mutators
void CruiseShip::setPass(int p)
{
	maxPassenger = p;
};



//accessors
int CruiseShip::getPass() const
{
	return maxPassenger;
};

void CruiseShip::print() const
{
	cout << "\n";
	cout << "Ship's callsign: " << Ship::name << "\n";
	cout << "The maximum number of passengers allowed is: " << maxPassenger << ".\n";
	cout << "\n";
};