/* CIST2362 - 20786 - Kimberly Jackson - SID: 0332
Week 3, Program 2, Main Street Parking Meters - 9/10/2012

	Class Description: Police Officer/Occifer - Responsibilities include:
		-Know the Officer's name and badge number
		-Examine a ParkedCar aand ParkingMeter object and determine
			whether the car's time is expired
		-Issue a ParkingTicket object is the car's time has expired.

*/

#include <iostream>
#include <string>
#include "ParkedCar.h"
#include "ParkingTicket.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

using namespace std;

PoliceOfficer::PoliceOfficer()
{
	name = "Oswald Wilson";
	badgenum = "OW3652";
};

PoliceOfficer::PoliceOfficer(string n, string bn)
{
	name = n;
	badgenum = bn;
};

//mutators
void PoliceOfficer::setCop(string n, string bn)
{
	name = n;
	badgenum = bn;
};

//accessors
string PoliceOfficer::getCopName()
{
	return name;
};

string PoliceOfficer::getCopBadge()
{
	return badgenum;
};

//misc
void PoliceOfficer::testTicket(ParkedCar car, ParkingMeter meter)
{
	ParkingTicket ticket;
	if (car.getMinutes() > meter.getMinutes())
	{
		ticket.setFine(car.getMinutes() - meter.getMinutes());
	}
};