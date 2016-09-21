/* CIST 2361 - Falling Distance
	Kimberly Jackson - 0332

	Description: Program will display the result of the falling distance formula
	for the numbers 1-10 plugged into the seconds part of the equation.
*/

#include <iostream>

using namespace std;

int fallingDistance(int);

int main()
{
	int counter; //the loop later to accept the values 1-10 will be held by this counter

	//message
	cout << "\n";
	cout << "Welcome to the Falling Distance Calculator!\n";
	cout << "This version is free and thus is a demonstration of what\n";
	cout << "you will expect in the full version. The numbers 1 through 10\n";
	cout << "will be plugged into the falling distance formula - d = 1/2gt^2\n";
	cout << "\n";
	cout << "In the full version, you will be allowed to plug in the number for t\n";
	cout << "which is the number of seconds the object took to fall from point\n";
	cout << "of release to the ground. Results will be in meters per second.\n";
	cout << "\n";
	cout << "Let us begin!\n";

	//for loop is just a display
	for (counter =1; counter <11; counter++)
	{
		cout << "For an object falling "<< counter << "second(s), it would travel\n";
		cout <<"\tabout " << fallingDistance(counter) << "meters per second.\n";
	}
	
	//outro message
	cout << "\n";
	cout << "I hope that made you want to purchase the app itself!\n";
	cout << "You'll be a hit in your physics class, if nothing else.\n";

	cout << "\n";
	system("pause");
	return 0;

}

int fallingDistance(int seconds)
{
	double distance; //to hold the value of the calculations, of course

	distance = 0.5*9.8*(seconds*seconds);

	return distance;
}