#include <iostream>
#include <climits>
#include <ctime>
#include <cstdlib>
#include "StopWatch.h"

using namespace std;

const int SIZE = 100;

int numbers[SIZE];

void sortBubble();
void sortSelection();

int main()
{

	cout << "Allright, so let's do this.\n";

	srand((unsigned)time(NULL));

	CStopWatch swatchBubbles,
		swatchSelections;

	for (int count = 0; count < SIZE; count++)
	{
		numbers[count]=rand()%INT_MAX;
	}

	//swatchBubbles.startTimer();
	//sortBubble();
	//swatchBubbles.stopTimer();

	swatchSelections.startTimer();
	sortSelection();
	swatchSelections.stopTimer();

	//cout << "For the Bubble sort we got: " << swatchBubbles.getElapsedTime() << "ms.\n";
	//cout << "\n";
	cout << "For the Selection sort we got: " << swatchSelections.getElapsedTime() << "ms.\n";
	cout << "\n";
	system("pause");
	return 0;

};

//void sortBubble()
//{
//
//	bool swap;
//	int temp;
//
//	do
//	{
//		swap = false;
//
//		for (int count = 0; count < SIZE-1; count++)
//		{
//			if (numbers[count] > numbers[count+1])
//			{
//				temp = numbers[count];
//				numbers[count] = numbers[count+1];
//				numbers[count+1]=temp;
//				swap=true;
//			}; //end if			
//		}; //end for
//	} while (swap); //end do-while
//
//};

void sortSelection()
{

	int startscan,
		minsub,
		minvalue;

	for (startscan = 0; startscan < SIZE-1; startscan++)
		{
			minsub = startscan;
			minvalue = numbers[startscan];

			for (int count = startscan+1; count < SIZE; count ++)
			{
				if (numbers[count] < minvalue)
				{
					minvalue = numbers[count];
					minsub = count;
				} //end if

			} //end inner for

		}; //end outer for

};