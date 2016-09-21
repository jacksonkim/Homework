/* CIST 2361 - Kimberly Jackson - 4/9/12

Description: Function that dynamically allocates an array of integers. 
	Function should accept integer argument indicating the number 
	of elements to allocate, then return a pointer to the array.

	Notes: Started without main.
	*/

#include <iostream>

using namespace std;

int *allocation();

int main()
{
	int *ptr;

	ptr = allocation();

	cout << ptr << endl;
	system("pause");
	return 0;
} 
//as this wants the function to accept arguments, this will be written
//as a library function. I commented out the main, as it was for testing.
int *allocation()
{
	int *nums;
	nums = new int[5];
	
	return nums;
}