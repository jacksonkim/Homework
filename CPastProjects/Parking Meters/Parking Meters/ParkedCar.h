/* CIST2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 2, Main Street Parking Meters - 9/10/2012

	Class Description: Parked Car - Responsibilities include:
		-Know the make, model, color, and license number
		-Number of minutes the car has been parked

*/

#ifndef PARKEDCAR_H
#define PARKEDCAR_H

using namespace std;

class ParkedCar
{
private:
	string make,
		model,
		color,
		licensePlate;
	int minutesParked;

public:
	//constructors
	ParkedCar();
	ParkedCar(string, string, string, string);
	ParkedCar(string, string, string, string, int);

	//mutators
	void setCar(string, string, string, string);
	void setMinutes(int);
	void setAll(string, string, string, string, int);

	//accessors
	string getMake();
	string getModel();
	string getColor();
	string getLicensePlate();
	int getMinutes();

};

#endif //PARKEDCAR_H