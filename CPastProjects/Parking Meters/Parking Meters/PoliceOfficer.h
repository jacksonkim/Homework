/* CIST2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 2, Main Street Parking Meters - 9/10/2012

	Class Description: Police Officer/Occifer - Responsibilities include:
		-Know the Officer's name and badge number
		-Examine a ParkedCar aand ParkingMeter object and determine
			whether the car's time is expired
		-Issue a ParkingTicket object is the car's time has expired.

*/

#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

using namespace std;

class PoliceOfficer
{
private:
	string name,
		badgenum;
	ParkingTicket ticket;

public:
	PoliceOfficer();
	PoliceOfficer(string, string);

	//mutators
	void setCop(string, string);

	//accessors
	string getCopName();
	string getCopBadge();

	//misc
	void testTicket(ParkedCar, ParkingMeter);

};

#endif //POLICEOFFICER_H