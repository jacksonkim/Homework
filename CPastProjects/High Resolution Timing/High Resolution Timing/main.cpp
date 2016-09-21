#include <iostream>
#include <string>
#include "StopWatch.h"

using namespace std;

const int N = 10;	// maximum size of list

int main()
{
	// Declare variables
	
	// a list of names
	string Name[N] = {"Felicia", "Erin", "CJ", "Marcus", "Brian", 
					  "Erica", "Franklin", "Lamar", "Casey", "Mary"};
	string target;		// the name to search for
	int position = 0;	// the current position in the list
	bool found = false;	// result of search

	// Create Timer Object
	CStopWatch watch;
	
	
	cout << "Enter the name you are looking for: ";
	cin >> target;
	
	// examine the list from the beginning position to the end of 
	// the list until the name is found or the end of the list is
	// reached.
	watch.startTimer();
	while (found == false && position < N) {
		if (Name[position] == target) {  // if name is found
			cout << "Found name at position: " << position << endl;
			found = true;
		}
		position++;	// increment to the next list position
	}
	
	// determine if a name was not found
	if (found == false) {
		cout << "Sorry, the name was not found" << endl;
	}
	watch.stopTimer();

	cout << "Time = " << watch.getElapsedTime() << " ms" << endl;
	cout << "\n";
	system("pause");
    return 0;
}
