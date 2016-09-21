/* CIST 2361 - File Encryption Filter
	Kimberly Jackson - 4/17/2012

	Description: Program will read in data from one file, change the value
		of the character, and output it to a different file.
		Maybe later this can be altered so the user can input the file they
		desire ecrypted. Eh?
	*/

#include <iostream>
#include <fstream>
#include <cstdlib> //including this for the random function

using namespace std;

int main()
{
	ifstream charsheet; //program name for file
	ofstream thedungeon; //program name for the encrypted file
	charsheet.open("charactersheet.txt", ios::binary); 
	//file to convert. made it binary to change the value of the binary ascii code
	thedungeon.open("dadungeon.txt", ios::binary);
	//file to hold encrypted data. also, at creation of this program, i hadn't made this file.
	//so this creates the file as well.
	char fileletter; //going to read the file one character at a time

	if (charsheet) //check to see if the file opened
	{
		cout << "File opened successfully. Get ready.\n";
		cout << "\n";
		system("pause");
	}
	else
	{
		cout << "Error opening file.\n";
		cout << "\n";
		system("pause");
	}

	//read the first character
	charsheet.get(fileletter);
	//cout <<fileletter << "\n";
	
	//as long as the eof bit is false, this will run
	while (charsheet)
	{
		/*the value of fileletter is the binary of whatever letter is there
		the rand function produces the same results every time it is 
		run. i set it up without srand-ing the time to ensure that it can 
		be decrypted more easily. i suppose the srand(time) could be applied,
		but it would be impossible - read: pretty hard? - to recover the data, i think.
		therefore, set a limiter on it, with the +1 so as to avoid
		a mod of 0 and we have a semi-difficult ecryption key.
		26 is my age this year and the day of my birth. */
		fileletter += (1 + rand() % 26);
		//cout << fileletter << "\n";
		thedungeon.put(fileletter);
		//write the new binary value of the character to the new file.

		//read again to verify the eof bit.
		charsheet.get(fileletter);
		//cout <<fileletter << "\n";
		//as long as this will read, this loop will repeat.
	}
	
	//DON'T FORGET TO CLOSE THE FILES.
	//Mr. Dink voice: Very Important.
	charsheet.close();
	thedungeon.close();

	//alert the user that file encryption is complete.
	cout << "\n";
	cout << "Ecryption complete. Good luck!\n";

	cout << "\n";
	system("pause");
	return 0;
}