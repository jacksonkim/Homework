/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 4, Program 2, Ship Manifest - 9/16/12

	Description: Ship class should have the following members:
		-Member for the name of the ship (string)
		-Member for the year that the ship was built (string)
		-Constructor and appropriate accessors and mutators
		-Virtual print function that displays the ship's name and year built

*/

#ifndef SHIP_H
#define SHIP_H

class Ship
{
protected:
	//data members
	std::string name,
		yearBuilt;
	//virtual function to be overwritten


public:
	//constructors
	Ship();
	Ship(std::string);
	Ship(std::string, std::string);

	//mutators
	void setName(std::string);
	void setYearBult(std::string);
	void setAll(std::string, std::string);

	//accessors
	std::string getName();
	std::string getYearBuilt();

	virtual void print() const;

};

#endif //SHIP_H