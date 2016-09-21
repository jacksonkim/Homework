/*CIST 2361 - Star Search
	Kimberly Jackson - 0332

Description: Read input from a file, test input for validity, perform calculations,
then output results into another file.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
//list prototypes
string contestantName();
float getJudgeData();
float findLowest(float [], int);
float findHighest(float [], int);
float CalcScore(float [], int, float, float);

ifstream starsearch; //internal file name for the input
ofstream results; //internal file name for the output

int main()
{
	starsearch.open("starsearch.dat");
	results.open("results.dat");

	const int SIZE = 5;
	float starscorearray[SIZE], //array to hold the scores of every contestant
		highest, //to hold the highest value
		lowest, //to hold the lowest value
		average; //to calucalate the average
	int conNum;

	string contestant;

	cout << setprecision(3);
	cout << "Welcome to Star Search, this is Ed McMahon!\n";
	cout << "Not really, it's just your computer.\n";
	cout << "This program will read the information you've put into a file\n";
	cout << "and run calculations on it.\n";
	cout << "\n";
	cout << "Let's make sure all of our files opened first.\n";
	cout << "\n";

	system("pause");

	cout << "\n";
	if (!starsearch)
		cout << "The input file didn't open.\n";
	else
		cout << "The input file looks to be open.\n";

	cout << "\n";
	system("pause");

	cout << "\n";
	if (!results)
		cout << "The output file didn't open.\n";
	else
		cout << "The output file looks to be open.\n";

	cout << "\n";
	system("pause");

	cout << "\n";
	starsearch >> conNum; //first line in the file should be the number of contestants
	cout << "Looks like there were " << conNum << " contestants.\n"; //to update the user
	cout << "\n";

	for (int count = 1; count <= conNum; count++)
	{
		contestant = contestantName();
		cout << contestant;
		results << contestant << " "; //to update the user

		for (int counter = 0; counter <= SIZE-1; counter++)
			{
				starscorearray[counter] = getJudgeData();
				cout << " ";
				cout << starscorearray[counter];

			}

		highest = findHighest(starscorearray, SIZE);
		cout << "\n";
		cout << "\n";
		cout << "Highest score to be dropped is " << highest << ".\n"; //to update the user
		lowest = findLowest(starscorearray, SIZE);
		cout << "\n";
		cout << "Lowest score to be dropped is " << lowest << ".\n"; //to update the user
		average = CalcScore(starscorearray, SIZE, highest, lowest);
		average /= 3;
		cout << "\n";
		cout << "Average of the last three scores is " << average << ".\n"; //to update the user
		results << average << "\n";
		cout << "\n";
		system("pause");
		cout << "\n";
	}


	//almost forgot to close the files!
	starsearch.close();
	results.close();

	cout << "\n";
	system("pause");
	return 0;
}

//no parameters here. returns the string containing the name
string contestantName()
{
	//read from the file the from the last read position to the next space
	string name;
	starsearch >> name;
	return name;

}

//no parameters here, just returning each scores as it reads them
float getJudgeData()
{
	//red from the file from space to space
	float score;
	starsearch >> score;
	return score;

}

//score array and size declarator as the arguments here so that it can return the highest score
float findHighest(float starscore[], int size)
{
	float highest;

	//set lowest to the first value in the array
	highest =starscore[0];

	//test from sub 1 to size-1
	for (int counter = 1; counter <= size-1; counter++)
	{
		if (starscore[counter] > highest)
			highest = starscore[counter];
	}

	return highest;

}

//score array and size declarator as the arguments here so that it can return the lowest score
float findLowest(float starscore[], int size)
{
	float lowest;

	//set lowest to the first value in the array
	lowest =starscore[0];

	//test from sub 1 to size-1
	for (int counter = 1; counter <= size-1; counter++)
	{
		if (starscore[counter] < lowest)
			lowest = starscore[counter];
	}

	return lowest;

}

//accepts array, size, highest, and lowest so as to test the value and add it all up and return the total
float CalcScore(float starscore[], int size, float highest, float lowest)
{
	float average=0;

	//almost had an off-by-one error because i copied the for from a previous module. derp.
	for (int counter = 0; counter <= size-1; counter++)
	{
		if (starscore[counter] != lowest && starscore[counter] != highest)
		{
			average += starscore[counter];
		}
	}

	return average;

}