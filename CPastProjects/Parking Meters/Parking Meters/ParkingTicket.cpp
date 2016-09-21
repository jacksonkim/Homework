/* CIST2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 2, Main Street Parking Meters - 9/10/2012

	Class Description: Parking Ticket - Responsibilities include:
		-Report the make, model, color, and license number of the illegally parked car
		-Report the amount of the fine (25$ for first hour, 10 for every additional hour)
		-Report the name and badge number of the police officer issuing the ticket

*/

#include <iostream>
#include <string>
#include "ParkedCar.h"
#include "ParkingTicket.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

using namespace std;

const int BASEFINE = 25,
	ADDFINE = 10;

ParkingTicket::ParkingTicket()
{
	car;
	//copster;
	fine = 0;
};

//ParkingTicket::ParkingTicket(ParkedCar &pcar, PoliceOfficer &pcop)
//{
//	car = pcar;
//	copster = pcop;
//	fine = 0;
//};

//mutators
//void ParkingTicket::setCop1(string n, string bn)
//{
//	copster.setCop(n, bn);
//};

//void ParkingTicket::setCop2(PoliceOfficer &pcop)
//{
//	copster = pcop;
//};

void ParkingTicket::setCar1(string ma, string mo, string c, string lp)
{
	car.setCar(ma, mo, c, lp);
};

//void ParkingTicket::setCar2(ParkedCar &pcar)
//{
//	car = pcar;
//};

void ParkingTicket::setFine(int time)
{
	if(time <= 60)
	{
		fine = BASEFINE;
	}
	else
	{
		fine = BASEFINE + ADDFINE * (time / 60);
	}

};

//accessors
ParkedCar ParkingTicket::getCar()
{
	return car;
};

//PoliceOfficer ParkingTicket::getCop()
//{
//	return copster;
//};

int ParkingTicket::getFine()
{
	return fine;
};