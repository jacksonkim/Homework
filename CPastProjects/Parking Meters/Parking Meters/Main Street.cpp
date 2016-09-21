/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 3, Program 2, Parking Meter Sim - 9/9/2012

Description: Create 10 parked cars and 10 parking meters. Randomly setting 
	parking meters to a paid time ranging from 30 minutes to 5 hours 
	(30 minute increments). 7r44n2
	Display the status of all cars and meters prior to simulation, and during the
	simulation display the tickets. You choose the best output layout. The simulation 
	takes place at a random time ranging from 1 hour to 5 hours (30 minute 
	increments) and the officer issues tickets for each parked car that has an 
	expired meter.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

using namespace std;

void displayAllCars(ParkedCar&);
void step30(ParkedCar car[], ParkingMeter meter[], int size, PoliceOfficer pcop);


int main()
{
	const int SIZE = 10;
	ParkedCar cars[SIZE] = { ParkedCar("Chevy", "Malibu", "Orange", "H8RADE"),
		ParkedCar("Plymouth", "Voyager", "Champagne", "8B4 RQ5"),
		ParkedCar("Kia", "Rio5", "Red", "834 BRT"),
		ParkedCar("Mitsubishi", " ", "Blue", "4HY F92"),
		ParkedCar("Ford", "Taurus", "Black", "9GH 43R"),
		ParkedCar("Honda", "Civic", "Black", "AQR 470"),
		ParkedCar("Dodge", "Charger", "Black w/ Red Stripes", "DUKESB"),
		ParkedCar("Fiat", "400", "Red", "86V Z4L"),
		ParkedCar("Chevy", "Lumina", "Maroon", "CSS EIC"),
		ParkedCar("Hyundai", "Elantra", "Pink", "PINKIE") };
	ParkingMeter meters[SIZE];
	PoliceOfficer copbro;

	for (int counter = 0; counter <=SIZE-1; counter++)
	{
		if (counter/5)
		{			
			cars[counter].setMinutes(300);
			meters[counter].setMinutes(300);
		}				
		else if (counter/3)
		{
			cars[counter].setMinutes(180);
			meters[counter].setMinutes(90);
		}		
		else if (counter/2)
		{
			cars[counter].setMinutes(90);
			meters[counter].setMinutes(30);
		}				
		else
		{
				cars[counter].setMinutes(30);
				meters[counter].setMinutes(90);
		} //end if
	} //end for



	for (int count = 0; count <=SIZE-1; count++)
	{
		displayAllCars(cars[count]);
	}

	step30(cars, meters, SIZE, copbro);

	cout << "\n";
	system("pause");
	return 0;

};

void displayAllCars(ParkedCar &car)
{
	cout << "Make: " << car.getMake() << "\n";
	cout << "Model: " << car.getModel() << "\n";
	cout << "Color: " << car.getColor() << "\n";
	cout << "License Plate: " << car.getLicensePlate() << "\n";
	cout << "Minutes Parked: " << car.getMinutes() << "\n";
	cout << "\n";
};

void step30(ParkedCar car[], ParkingMeter meter[], int size, PoliceOfficer pcop)
{
	/*for (int timecounter = 30; timecounter <= 300; timecounter+30)
	{
		for (int count = 0; count <= size-1; count++)
		{
			pcop.testTicket(car[count], meter[count]);
		}
	}*/
};