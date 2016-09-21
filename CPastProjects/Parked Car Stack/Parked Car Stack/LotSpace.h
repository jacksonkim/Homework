/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 11, Parking Lot Stack - 11/12/12

	Class Description: Class will contain information about a specific parked car and whether or not
		that car is in violation of being parked for too long.

*/

#ifndef LOTSPACE_H
#define LOTSPACE_H

#include "ParkedCar.h"

using namespace std;

class LotSpace
{
protected:
	bool free;
	ParkedCar car;

public:
	//constructors
	LotSpace();

	//methods
	bool isFree();
	
	void addCar(ParkedCar&);

	bool isTowed();
};

#endif //LOTSPACE_H