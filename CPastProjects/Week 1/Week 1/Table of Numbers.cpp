/*CIST 2362 - 20786 - Kimberly Jackson - SID: 0332

Week 1, Program 1 - Table of Numbers - 8/25/12

Description: Write a program that will output a table of 3 columns:
	n, , and  for the values from n = 0 to 100. The columns of the 
	table should be 10 characters in width with the headings 
	n, n-squared, and n-cubed.

*/

#include <iostream> //obvious reasons
#include <iomanip> //for the setw columns
#include <cmath> //for the pow function to make it easier on everyone

using namespace std;

int main ()
{
	//just a simple greeting. i like to be genial
	cout << "Thank you for loading up this number generator. What you will see\n";
	cout << "printed following this message is the numbers 0 through 100.\n";
	cout << "Each number will be displayed, then the square of that number\n";
	cout << "and the cube of that number.\n";

	//including a pause so they can read the message
	cout << "\n";
	system("pause");
	cout << "\n";
	
	cout << setw(10) << "Number" << setw(10) << "N-Squared" << setw(10) << "N-Cubed\n";

	for (int count=0; count <=100; count++)
	{

		cout <<  setw(10) << count << setw(10) << pow(count, 2.0) << setw(10) << pow(count, 3.0) << "\n";
		

		//adding in a pause so that it won't just go through all 100
		bool pausebutton=false;
		int remainder = count%10;
		
		if (remainder == 0)
			pausebutton = true;

		if (pausebutton == true && count != 0)
		{
			cout << "\n";
			system("pause");
			cout << "\n";
			cout << setw(10) << "Number" << setw(10) << "N-Squared" << setw(10) << "N-Cubed\n";
		} //end of the pause if

	} //end of the for loop

	cout << "\nOh, I guess I got overzealous.\n";
	cout << "\n";
	system("pause");
	return 0;
};