/*CIST 2361

Kimberly Jackson - 0332

Description: Accept user input of an integer number and determine whether or not that number is prime.

*/

#include <iostream>

using namespace std;

bool isPrime(int);

int main()
{
	int primeNum; //user input variable to test if a number is prime

	cout << "Welcome to the Prime Number Test app!\n";
	cout << "Here, you will be requested for a positive number.\n";
	cout << "This number will then be tested for whether or not it is prime.\n";
	cout << "No decimals or negative numbers, just whole ones.\n";
	cout << "\n";
	cout << "Please enter the number you would like to test.\n";
	cin >> primeNum;

	//Send the user number to the tester function
	if (isPrime(primeNum))
	{
		cout << "\n";
		cout << "Looks like the number you entered, " << primeNum << ", is actually a prime number!\n";
	}
	else
	{
		cout << "\n";
		cout << "Looks like the number you entered, " << primeNum << ", is not a prime number!\n";
	}

	cout << "\n";
	system("pause");
	return 0;
}

bool isPrime(int num1)
{
	bool primeTest; //variable to return true or false boolean value
	int counter, //run the for loop and test for remainders
		remainder; //to run the prime number test

	for (counter = 2; counter <= num1; counter++)
	{
		if (num1%counter == 0)
			primeTest = false;
		else
			primeTest = true;
	}

	return primeTest;
}