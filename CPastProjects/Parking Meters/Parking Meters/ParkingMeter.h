/* CIST2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 2, Main Street Parking Meters - 9/10/2012

	Class Description: Parking Meter - Responsibilities include:
		-Know the number of minutes purchased

*/

#ifndef PARKINGMETER_H
#define PARKINGMETER_H

using namespace std;

class ParkingMeter
{
	int minutesBought;

public:
	//constructors
	ParkingMeter();
	ParkingMeter(int);

	//mutators
	void setMinutes(int);

	//accessors
	int getMinutes();

};

#endif //PARKINGMETERS_H