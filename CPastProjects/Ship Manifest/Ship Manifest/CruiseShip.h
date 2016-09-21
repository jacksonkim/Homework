/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 4, Program 2, Ship Manifest - 9/16/12

	Description: CruiseShip class, derived from Ship class, should have the following members:
		-Member for the maximum number of passengers (int)
		-Constructor and appropriate accessors and mutators
		-print function that overrides Ship's and displays the ship's name and max passengers

*/

#ifndef CRUISESHIP_H
#define CRUISESHIP_H

class CruiseShip : public Ship
{
private:
	int maxPassenger;

public:
	//constructors
	CruiseShip();
	CruiseShip(int);
	CruiseShip(std::string, std::string, int);

	//mutators
	void setPass(int);

	//accessors
	int getPass() const;

	//virtual function overwrite
	void print() const;

};

#endif //CRUISESHIP_H