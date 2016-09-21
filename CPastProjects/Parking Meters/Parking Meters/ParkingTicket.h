/* CIST2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 2, Main Street Parking Meters - 9/10/2012

	Class Description: Parking Ticket - Responsibilities include:
		-Report the make, model, color, and license number of the illegally parked car
		-Report the amount of the fine (25$ for first hour, 10 for every additional hour)
		-Report the name and badge number of the police officer issuing the ticket

*/

#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

using namespace std;

class ParkingTicket
{
private:
	ParkedCar car;
	//PoliceOfficer copster;
	int fine; //HAHA LIKE TIM SCHAFER'S COMPANY. herp

public:
	//constructors
	ParkingTicket();
	//ParkingTicket(ParkedCar&, PoliceOfficer&);

	//mutators
	void setCop1(string, string);
	//void setCop2(PoliceOfficer&);
	void setCar1(string, string, string, string);
	//void setCar2(ParkedCar&);
	void setFine(int);

	//accessors
	ParkedCar getCar();
	//PoliceOfficer getCop();
	int getFine();

};

#endif //PARKINGTICKET_H