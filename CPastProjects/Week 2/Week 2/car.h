/*CIST 2362 - 20786 - Kimberly Jackson - SID: 0332

Week 2, Class 1 - Car Class - 9/1/12

Description: Write a Car class that has int yearModel and speed, string make.
	Constructor should accept model and make, but set 0 as the speed.
	Accessor functions to get the values stored in the object's model, make, and speed.
	accelerate function should increase the speed by 5 every time it is called.
	brake function should decrease the speed by 5 every time it is called.

*/

#ifndef CAR_H
#define CAR_H
#include <string> //was this even necessary here? i can't remember
//hooray for pre-parsing errors
using namespace std;

class Car
{
private:
	int yearModel,
		speed;
	string make;

public:
	Car();
	Car(int, string);
	void setyearModel(int);
	int getyearModel() const;
	void setspeed(int);
	int getspeed() const;
	void setmake(string);
	string getmake();
	int accelerate();
	int brake();
};

#endif //CAR_H