/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 4, Program 2, Ship Manifest - 9/16/12

	Description: CargoShip class, derived from Ship class, should have the following members:
		-Member for the cargo capacity in tonnage (int)
		-Constructor and appropriate accessors and mutators
		-print function that overrides Ship's and displays the ship's name and cargo capacity

*/

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

class CargoShip : public Ship
{
private:
	int cargoSpace;

public:
	//constructors
	CargoShip();
	CargoShip(int);
	CargoShip(std::string, std::string, int);

	//mutators
	void setSpace(int);

	//accessors
	int getSpace() const;

	//virtual function overwrite
	void CargoShip::print() const;

};

#endif //CARGOSHIP_H