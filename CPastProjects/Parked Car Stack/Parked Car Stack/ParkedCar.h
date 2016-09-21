/* CIST2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 2, Main Street Parking Meters - 9/10/2012

	Class Description: Parked Car - Responsibilities include:
		-Know the make, model, color, and license number
		-Number of minutes the car has been parked

	11/13/12 - Edited for Parking lot simulation.

*/

#ifndef PARKEDCAR_H
#define PARKEDCAR_H

using namespace std;

class ParkedCar
{
private:
	int minutesBought,
		minutesParked;

public:
	//constructors
	ParkedCar();
	ParkedCar(int);

	//methods
	bool done();
	int getBought();
	int getParked();

};

#endif //PARKEDCAR_H