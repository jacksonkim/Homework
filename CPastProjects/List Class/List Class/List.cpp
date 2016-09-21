// Chapter 8, Programming Challenge 11: Using Files-String Selection Sort Modification
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function prototypes
void selectionSort(string [], int);
void displayArray(string [], int);
void readNames(string[], int);

int main()
{
	const int NUM_NAMES = 20;
	string names[NUM_NAMES];

	// Read the names from the file.
	readNames(names, NUM_NAMES);

	// Display the unsorted array.
	cout << "Here are the unsorted names:\n";
	cout << "--------------------------\n";
	displayArray(names, NUM_NAMES);

	// Sort the array.
	selectionSort(names, NUM_NAMES);

	// Display the sorted array.
	cout << "\nHere are the names sorted:\n";
	cout << "--------------------------\n";
	displayArray(names, NUM_NAMES);

	return 0;
}

// ********************************************************
// The selectionSort function performs an ascending order *
// selection sort on an array of strings. The size        *
// parameter is the number of elements in the array.      *
// ********************************************************
void selectionSort(string values[], int size)
{
	int startScan;
	int minIndex;
	string minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = values[minIndex];

		for(int index = startScan + 1; index < size; index++)
		{
			if (values[index] < minValue)
			{
				minValue = values[index];
				minIndex = index;
			}
		}

		values[minIndex] = values[startScan];
		values[startScan] = minValue;
	}
}

// ********************************************************
// The displayArray function displays the contents of     *
// the array.                                             *
// ********************************************************
void displayArray(string values[], int size)
{
	for (int i = 0; i < size; i++)
		cout << values[i] << endl;
}

// ********************************************************
// The readNames function reads the contents of the       *
// "names.dat" file into the array.                       *
// ********************************************************
void readNames(string values[], int size)
{
    int index = 0;	// Array index

    // Open the file.
    ifstream inFile;
    inFile.open("names.dat");

    // Test that the file was opened.
    if (!inFile)
    {
        cout << "Error opening names.dat\n";
        exit(0);
    }

	// Read the names from the file into the array.
    while (index < size)
    {
        // Get a line from the file.
		getline(inFile, values[index]);

        // Increment index.
        index++;
    }

    // Close the file.
    inFile.close();
}