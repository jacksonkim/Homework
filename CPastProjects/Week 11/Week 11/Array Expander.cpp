/* CIST 2361 - Kimberly Jackson - 4/9/12

Description: Function that accepts an int array and the size as 
	arguments, then create a new array that is twice the size of 
	the argument array. Function should copy the contents of 
	the argument array into new array and initialize the rest as 0. 
	Function should return a pointer to the new array.

	Notes: Started without main.

		Had to check the book a few times on how to do this.
		It looked simple enough with the way the book had similar
		programs mapped out, but it took me a bit to realize I
		had to get rid of the [] for the array when passing it and
		creating a new one.

		Always forget to change the prototype...
	*/

#include <iostream>

using namespace std;

//function prototype. accepts pointer to array, duplicates the array,
//then returns new array
int *bigmore(const int *, int);

int main()
{
	const int SIZE = 5; // constant for the size of the array
	int nums[SIZE] = { 5, 8, 31, 2, 72 },
		*dupe;

	dupe = bigmore(nums, SIZE);

	cout << "\n";
	cout << dupe << endl;
	system("pause");
	return 0;
} 
//as this wants the function to accept arguments, this will be written
//as a library function. I commented out the main, as it was for testing.
int *bigmore(const int *numbers, int size)
{
	int *numberz;
	//don't forget to double the size of the array
	numberz = new int[size*2];

	//copy the current array into the new array
	for(int counter = 0; counter <= size-1; counter ++)
	{
		numberz[counter] = numbers[counter];
		cout << counter << "  " << numberz[counter] << endl; //to verify the contents of the array
	}

	//double size for the purpose of this next loop
	size *= 2;
	system("pause");

	//set the other half of the array to 0.
	for(int counter = size/2; counter < size; counter++)
	{
		numberz[counter]  = 0;
		cout << counter << "   " << numberz[counter] << endl; //again, for verification
	}

	//return pointer to new array
	return numberz;
}