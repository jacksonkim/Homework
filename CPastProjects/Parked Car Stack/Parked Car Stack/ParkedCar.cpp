/* CIST2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 2, Main Street Parking Meters - 9/10/2012

	Class Description: Parked Car - Responsibilities include:
		-Know the make, model, color, and license number
		-Number of minutes the car has been parked

*/

#include <iostream>
#include <string>
#include "ParkedCar.h"


using namespace std;

ParkedCar::ParkedCar()
{
	minutesBought = 15;
	minutesParked = 0;
};

ParkedCar::ParkedCar(int mb)
{
	minutesBought = mb;
	minutesParked = 5+(rand()%6);
};

//methods
bool ParkedCar::done()
{
	if((minutesParked+5) >= minutesBought)
		return true;
	else
		return false;
};

int ParkedCar::getBought()
{
	return minutesBought;
};

int ParkedCar::getParked()
{
	return minutesParked;
};