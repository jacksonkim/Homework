#include <iostream>
#include <climits>
#include <ctime>
#include <cstdlib>
#include "StopWatch.h"

using namespace std;

const unsigned int N = 100000000;
int numbers[N];

int main()
{
	int largest;

	srand((unsigned)time(NULL));

	CStopWatch swatch;

	for (int count = 0; count < N; count++)
	{
		numbers[count]=rand()%INT_MAX;
	}

	swatch.startTimer();

	largest = numbers[0];
	for (int count = 1; count < N; count++)
	{
		if (numbers[count] > largest)
		{
			largest = numbers[count];
		}
	}
	swatch.stopTimer();

	cout << "The largest value is " << largest << "\n";
	cout << "Found in " << swatch.getElapsedTime() << "ms.\n";
	cout << "\n";
	system("pause");
	return 0;
};