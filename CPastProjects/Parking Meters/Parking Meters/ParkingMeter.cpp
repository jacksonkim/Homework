/* CIST2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 2, Main Street Parking Meters - 9/10/2012

	Class Description: Parking Meter - Responsibilities include:
		-Know the number of minutes purchased

*/

#include <iostream>
#include <string>
#include "ParkedCar.h"
#include "ParkingTicket.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

using namespace std;

ParkingMeter::ParkingMeter()
{
		minutesBought = 0;
};

ParkingMeter::ParkingMeter(int mb)
{
		minutesBought = mb;
};

//mutators
void ParkingMeter::setMinutes(int mb)
{
		minutesBought = mb;
};

//accessors
int ParkingMeter::getMinutes()
{
		return minutesBought;
};