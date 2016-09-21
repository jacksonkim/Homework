/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 11, Parking Lot Stack - 11/12/12

	Class Description: Class will contain information about a specific parked car and whether or not
		that car is in violation of being parked for too long.

*/

#include "LotSpace.h"
#include "ParkedCar.h"

using namespace std;

LotSpace::LotSpace()
{
	free = true;
};

//methods
bool LotSpace::isFree()
{
	if(free)
		return true;

	if(car.done())
	{
		free = true;
	}

	return free;
};
	
void LotSpace::addCar(ParkedCar& vehicle)
{
	car = vehicle;
	free = false;
};

bool LotSpace::isTowed()
{
	if(car.getParked() >= 70)
		return true;
	return false;
};