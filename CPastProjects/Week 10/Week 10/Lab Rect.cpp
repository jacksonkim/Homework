#include <iostream>
#include <iomanip>
using namespace std;


// This program uses a structure to hold data about a rectangle 
// PLACE YOUR NAME HERE

// FILL IN CODE TO define a structure or class with public: named rectangle which has 
// members length, width, area, and perimeter all of which are floats

struct rectangle
{
	float length,
		width,
		area,
		perimeter;
};

int main()
{
    // Fill IN CODE to declare a rectangle variable named box
	rectangle box;
    cout << "Enter the length of a rectangle: ";
	
	// FILL IN CODE to read in the length member of box
	cin >> box.length;

	cout << "Enter the width of a rectangle: ";
	
	// FILL IN CODE to read in the width member of box
	cin >> box.width;

	cout << endl << endl;

	// FILL IN CODE to compute the area member of box
	box.area = box.length * box.width;
	// FILL IN CODE to compute the perimeter member of box
	box.perimeter = (box.length*2) + (box.width*2);

	cout << fixed << showpoint << setprecision(2);
	

    // FILL IN CODE to output the area with an appropriate message
	cout << "Area of box: " << box.area << ".\n";
	// FILL IN CODE to output the perimeter with an appropriate message
	cout << "Perimeter of box: " << box.perimeter << ".\n";

	system("pause");
	return 0;
}