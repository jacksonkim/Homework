/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 4, Program 2, Ship Manifest - 9/16/12

	Description: Program that displays all classes should use an array of Ship pointers.
		Array elements should be initialized with addresses of dynamically allocated Ship,
		CargoShip, and CruiseShip objects. Program should step through the array and
		use each object's print function.

*/

#include <iostream>
#include "Ship.h"
#include "CargoShip.h"
#include "CruiseShip.h"


using namespace std;

void displayAll(Ship*);

int main()
{
	const int SIZE = 5;

	Ship *shiptr[SIZE] = { new CargoShip("Stalin's Fury", "1984", 300),
		new CruiseShip("Oberon's Fancy", "2007", 1700),
		new Ship("Queen Mary", "1795"),
		new CargoShip("Your Mother", "1998", 600),
		new CruiseShip("Henry's Honor", "1645", 200) };

	cout << "The current Ship manifest is as follows: \n";

	for (int count = 0; count <= SIZE - 1; count++)
	{
		displayAll(shiptr[count]);
	};

	cout << "\n";
	system("pause");
	return 0;

};

void displayAll(Ship *ship)
{
	ship->print();
};