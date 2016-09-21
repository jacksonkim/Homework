/*CIST 2362 - 20786 - Kimberly Jackson - SID: 0332

Week 2, Class 1 - Car Class - 9/1/12

Description: Write a Car class that has int yearModel and speed, string make.
	Constructor should accept model and make, but set 0 as the speed.
	Accessor functions to get the values stored in the object's model, make, and speed.
	accelerate function should increase the speed by 5 every time it is called.
	brake function should decrease the speed by 5 every time it is called.

*/

#include "car.h"
#include <string>
#include <iostream>
//or do they only have to be here. :I
using namespace std;

//he wants me to use more functions.

void accelerate(Car&); //these here are reference variables. the CAR&. the uh... Car is a class I had to create.
void brake(Car&);

int main()
{

	Car car1(2005, "Buick"),
		car2; //car objects

	cout << "\n";
	accelerate(car1);

	cout << "\n";
	brake(car1);

	cout << "\n";
	system("pause");
	return 0;

};

void accelerate(Car &cara)
{
	cout << "You are currently traveling at " << cara.getspeed() << "mph in your " << cara.getmake() << ".\n";

	for (int count=1; count <=5; count++)
	{
		cara.accelerate();
		cout << "Mashing the gas only makes you go this much faster: " << cara.getspeed() << "\n";
	}

}

void brake(Car &carb)
{
	cout << "You are currently traveling at " << carb.getspeed() << "mph in your " << carb.getmake() << ".\n";

	for (int count=1; count <=5; count++)
	{
		carb.brake();
		cout << "Deccelerating. Your current speed is: " << carb.getspeed() << "\n";
	}
};