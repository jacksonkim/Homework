/*CIST 2361 - Rainfall Statistics
Kimberly Jackson - 0332

Description: Program to accept user input of the rainfall statistics and insert it into an array. This
		information will be totalled, averaged, and the highest and lowest of the statistics will be found.
		Validation of input required to ensure rainfall input is not negative.

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const int SIZE=12; //Size of the doubles array that will be used.

	float doubles[SIZE], //array for the rainfall stats
		total=0, //hold the total
		average, //for the average of all 12 months
		highest=0, //for the highest rainfall
		lowest=999; //for the lowest rainfall
	int counter; //for any for loops

	//Wall of text to introduce the user to the program.
	cout << "Welcome to the Rainfall statistics app!\n";
	cout << "This app will accept your statistics for only 12 months and calculate\n";
	cout << "the total and average for all 12 months. It will also determine the\n";
	cout << "highest and lowest rainfalls out of those 12 months.\n";
	cout << "This app does not use a unit of measure to allow for any input.\n";
	cout << "\n";
	system ("pause");
	cout << "\n";
	cout << "Hopefully you are a meteorologist or have access to the average\n";
	cout << "monthly rainfall that you'd like to calculate.\n";
	cout << "\n";
	cout << "For the purposes of this app, everything is available for you to use\n";
	cout << "decimals in the calculation.\n";
	cout << "Please don't use any negative numbers in the rainfall calculations.\n";
	cout << "If you do, you will be asked to input the number again.\n";
	cout << "\n";
	cout << "Let us begin!\n";
	cout << "\n";
	system ("pause");

	//begin the input/for loop
	for (counter = 0; counter <= SIZE-1; counter++)
	{
			cout << "Please enter the rainfall statistic for month " << counter+1 << ".\n";
			cin >> doubles[counter];
			cout << "\n";

			//validate
			while (doubles[counter] < 0)
			{
				cout << "I already said not to use negative numberrrrssss. Uuuuhhhh.\n";
				cout << "Please reinput the rainfall stats for month " << counter+1 << ".\n";
				cin >> doubles[counter];
			}

		total += doubles[counter]; //add up the total

		if (doubles[counter] > highest) //test to see if the current value in the array is larger than the current value of highest
			highest = doubles[counter]; 

		if (doubles[counter] < lowest)//test to see if the current value in the array is smaller than the current value of lowest
			lowest = doubles[counter];

	}

	average = total/SIZE;

	cout << "The total rainfall of the last 12 months is " << total << ".\n";
	cout << "The average rainfall of the last 12 months is " << average << ".\n";
	cout << "The highest amount of rainfall was " << highest << ".\n";
	cout << "The lowest amount of rainfall was " << lowest << ".\n";

	cout << "\n";
	system ("pause");
	return 0;

}