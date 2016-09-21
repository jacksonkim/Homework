/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 4, Program 2, Ship Manifest - 9/16/12

	Description: CargoShip class, derived from Ship class, should have the following members:
		-Member for the cargo capacity in tonnage (int)
		-Constructor and appropriate accessors and mutators
		-print function that overrides Ship's and displays the ship's name and cargo capacity

*/

#include <iostream>
#include <string>
#include "Ship.h"
#include "CargoShip.h"

using namespace std;

CargoShip::CargoShip()
{
	cargoSpace = 0;
};


CargoShip::CargoShip(int cs)
{
	cargoSpace = cs;
};

CargoShip::CargoShip(std::string n, std::string yb, int cs) : Ship(n, yb)
{
	cargoSpace = cs;
};

//mutators
void CargoShip::setSpace(int cs)
{
	cargoSpace = cs;
};


//accessors
int CargoShip::getSpace() const
{
	return cargoSpace;
};

void CargoShip::print() const
{
	cout << "\n";
	cout << "Ship's callsign: " << Ship::name << "\n";
	cout << "The maximum tonnage of cargo this ship can safely haul is: " << cargoSpace << ".\n";
	cout << "\n";

};