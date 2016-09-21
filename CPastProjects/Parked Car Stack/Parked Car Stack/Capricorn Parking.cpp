/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 11, Parking Lot Stack - 11/12/12

	Description: Create a parking lot simulation that has 20 spaces available for parking. The user
		will input the number of minutes they would like the simulation to run. The simulation will run
		in 5minute increments, a police officer will patrol every ~10minutes to check if cars are in violation
		of remaining in the lot for over an hour. If cars are found in violation, they are removed from the lot.
		Cars may purchase 15-60minutes of parking time. If the lot is full when another car shows up, they
		must be turned away.

		At the end of the sim, the display should show only the following:
		•Number of cars that were found in violation of the hour limit
		•Number of cars that parked total
		•Number of cars that were turned away because the lot was full
		•The average # of full spaces

		note: okay, so i couldn't get it to do the police check for some reason. it kept saying  the 
			vector subscript was out of range. i tried to add in a bunch of different things to remedy that,
			but all i got was heartache and pain. so i have since abandoned it. i tried checking if it was
			empty, don't do the police check, but it still cropped up.

			and then i tried to add in constraints to empty the line-
			okay i got it to not give me errors, but i don't know if its removing people from the line. it sure
			doesn't look like it is.

			i can't deal with this anymore. its 5:00am. miscalculation of time on my part. WHAT'RE YA
			GONNA DO, RIGHT. (obvious answer: not suck so much. :I )
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include "ParkedCar.h"
#include "LotSpace.h"

using namespace std;

int main()
{
	int simMinutes = 0,
		lotSize = 20,
		carsTowed = 0,
		carsRejected = 0,
		numofCars = 0;

	//srand(time(NULL));

	vector<LotSpace> parkingLot(lotSize);
	queue<ParkedCar, list<ParkedCar> > line;

	cout << "Welcome to Capricorn Parking Lot Simulation.\n";
	cout << "Please enter in the number of minutes you would like this simulation run: ";
	cin >> simMinutes;

	cout << "\nRunning simulation...\n";

	for(int time=0; time <= simMinutes; (time = time+5))
	{
		if ((rand()%10) < 9)
		{
			if (time/15)
			{
				ParkedCar car(time);
				line.push(car);
				cout << "Car added to line.\n";
			}
			else
			{
				ParkedCar car(30);
				line.push(car);
				cout << "Car added to line.\n";
			} //end if/else car creation
			
		}//end if interval

		for(int count = 1; count < lotSize; count++)
		{
			if(parkingLot[count-1].isFree() & !line.empty())
			{
				ParkedCar vehicle = line.front();
				numofCars++;
				parkingLot[count].addCar(vehicle);
				line.pop();
				cout << "Car removed from line.\n";
			}
			else if(!parkingLot[count-1].isFree() && !line.empty())
			{
				line.pop();
				carsRejected++;
			}
		} //end lot loading

		//vector<LotSpace>::iterator lotspace = parkingLot.begin();
		//while(lotspace != parkingLot.end())
		//{
		//	int count=0;
		//	if(!parkingLot[count].isFree())
		//		parkingLot.erase(lotspace);
		//	count++;
		//	++lotspace;
		//	carsTowed++;
		//}//end police if

		//if(time/10)
		//{
		//	if(!parkingLot.empty())
		//	{
		//		for(vector<LotSpace>::iterator counter = parkingLot.begin(); counter != parkingLot.end(); counter++)
		//		{
		//			int peek=1;
		//			if(!parkingLot[peek-1].isTowed())
		//				counter = parkingLot.erase(counter);
		//			peek++;
		//			carsTowed++;
		//		}//end vector search
		//	} //end check if lot is empty
		//}//end police check
		cout << time << "\n";
	};

	double density = (lotSize/(1.0*numofCars))*100;

	cout << "Cars rejected: " << carsRejected << "\n";
	cout << "Cars Towed: " << carsTowed << "\n";
	cout << "Cars parked total: " << numofCars << "\n";
	cout << "Average lot density: " << density << "%\n";

	cout << "\n";
	system("pause");
	return 0;
};