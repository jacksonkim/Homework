/* CIST 2361 - Charge Account Validation
	Kimberly Jackson - 3/27/12

	Description: Program will accept input from a user of a charge account number,
		then will validate if that charge account number is valid or not depending on
		whether or not it can be found in an array. A message will be displayed either
		approving or disapproving of the account number.

	*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{ //this will be a simple linear search
	//variables, away!
	const int SIZE = 18; //array size
	int validaccounts[SIZE] = { 5658845, 8080152, 1005231, 4520125, 4562555, 6545231,
		7895122, 5552012, 3852085, 8777541, 5050552, 7576651, 8451277, 7825877,
		7881200, 1302850, 1250255, 4581002 }, //preloaded array
		accountNumber, //input variable to test
		index = 0; //for the search loop
	bool found = false; //for the search loop

	cout << "Thank you for accessing this branch.\n";
	cout << "Please input your account number.\n";
	cin >> accountNumber;

	while (index < SIZE && !found)
	{

		if (validaccounts[index] == accountNumber)
		{
			found = true;
		}
		index++;
	}

	//with the search done...

	if (found == true)
		cout << "Account number found. Welcome back.\n";
	else
		cout << "Account number not found. Goodbye!\n";

	cout << "\n";

	cout << "That's it! See you again soon.\n";
	cout << "\n";
	system("pause");
	return 0;
}