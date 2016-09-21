#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	
	/*int x = 25;
	int *ptr;

	ptr = &x;

	cout << "The value of x is " << x << ".\n";
	cout << "The value of ptr is " << ptr << ".\n";
	cout << "The value of x is " << *ptr << ".\n";
	cout << "\n"; 

	int vals[] = { 26, 58, 22, 56 };

	cout << "The address of the array name is " << vals << ".\n";
	cout << "The value of the second location is " << vals[1] << ".\n";
	cout << "\n";

	ptr = vals;

	cout << "The address of the ptr name is " << ptr << ".\n";
	cout << "The value of the second location is " << vals[1] << ".\n";
	cout << "\n";

	cout << "ptr+0 = " << ptr+0 << " and *(ptr+0) = " << *(ptr+0) << ".\n";
	cout << "ptr+1 = " << ptr+1 << " and *(ptr+1) = " << *(ptr+1) << ".\n";
	cout << "ptr+2 = " << ptr+2 << " and *(ptr+2) = " << *(ptr+2) << ".\n";
	cout << "ptr+3 = " << ptr+3 << " and *(ptr+3) = " << *(ptr+3) << ".\n";
	cout << "ptr+5 = " << ptr+5 << " and *(ptr+5) = " << *(ptr+5) << ".\n"; */

	cout << "********* Dynamic Arrays **********\n";

	int *myarray;
	int size = 0;

	cout << "How many values do you have to input?\n";
	cin >> size;

	myarray = new int[size];

	for (int counter = 0; counter < size; counter++)
	{
		cout << "Input value number " << counter+1 << ".\n";
		cin >> myarray[counter];
	}

	for (int counter = 0; counter < size; counter++)
	{
		cout << "Content of location " << counter+1 << " is " << myarray[counter] << ".\n";
	}

	delete [] myarray;

	/*for ( ; ; ) THIS IS EVIL. NEVER DO THIS. ANYBODY. >:(
	{
		myarray= new int;
		delete myarray;
	}*/

	cout << "\n";
	system("pause");
	return 0;
}