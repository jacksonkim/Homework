/* CIST2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 2, Main Street Parking Meters - 9/10/2012

	Class Description: Parked Car - Responsibilities include:
		-Know the make, model, color, and license number
		-Number of minutes the car has been parked

*/

#include <iostream>
#include <string>
#include "ParkedCar.h"
#include "ParkingTicket.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

using namespace std;

ParkedCar::ParkedCar()
{
	make = " ";
	model = " ";
	color = "White";
	licensePlate = " ";
	minutesParked = 0;
};

ParkedCar::ParkedCar(string ma, string mo, string c, string lp)
{
	make = ma;
	model = mo;
	color = c;
	licensePlate = lp;
	minutesParked = 0;
};

ParkedCar::ParkedCar(string ma, string mo, string c, string lp, int mp)
{
	make = ma;
	model = mo;
	color = c;
	licensePlate = lp;
	minutesParked = mp;
};

//mutators
void ParkedCar::setCar(string ma, string mo, string c, string lp)
{
	make = ma;
	model = mo;
	color = c;
	licensePlate = lp;
};

void ParkedCar::setMinutes(int mp)
{
	minutesParked = mp;
};

void ParkedCar::setAll(string ma, string mo, string c, string lp, int mp)
{
	make = ma;
	model = mo;
	color = c;
	licensePlate = lp;
	minutesParked = mp;
};

//accessors
string ParkedCar::getMake()
{
	return make;
};

string ParkedCar::getModel()
{
	return model;
};

string ParkedCar::getColor()
{
	return color;
};

string ParkedCar::getLicensePlate()
{
	return licensePlate;
};

int ParkedCar::getMinutes()
{
	return minutesParked;
};