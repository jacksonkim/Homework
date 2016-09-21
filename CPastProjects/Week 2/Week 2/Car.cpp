/*CIST 2362 - 20786 - Kimberly Jackson - SID: 0332

Week 2, Class 1 - Car Class - 9/1/12

Description: Write a Car class that has int yearModel and speed, string make.
	Constructor should accept model and make, but set 0 as the speed.
	Accessor functions to get the values stored in the object's model, make, and speed.
	accelerate function should increase the speed by 5 every time it is called.
	brake function should decrease the speed by 5 every time it is called.

*/

#include "car.h"
#include <string> //or here?

using namespace std; //or this? i don't even know.

Car::Car()
{
	yearModel = 2012;
	speed = 0;
	make = "Butts";
};

Car::Car(int yM, string m)
{
	yearModel = yM;
	make = m;
	speed = 0;
};

void Car::setyearModel(int yM)
{
	yearModel=yM;
};

int Car::getyearModel() const
{
	return yearModel;
};

void Car::setspeed(int sp)
{
	speed=sp;
};

int Car::getspeed() const
{
	return speed;	
};

void Car::setmake(string m)
{
	make=m;
};

string Car::getmake()
{
	return make;
};

int Car::accelerate()
{
	speed=speed+5;
	return speed;
};

int Car::brake()
{
	speed=speed-5;
	return speed;
};