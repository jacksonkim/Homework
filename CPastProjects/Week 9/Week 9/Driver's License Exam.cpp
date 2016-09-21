/* CIST 2361 - Driver's License Exam
	Kimberly Jackson - 3/27/12

	Description: Program will be used to grade the written portion of
	the Driver's License Exam. User will enter a test-taker's answers into
	the program and the program will display whether the tester passed or failed.
	To pass, the tester must answer 15 of 20 questions correctly. It will then 
	Display how many questions were answered correctly, how many were
	answered incorrectly, and which answers they were. There will also be
	input validation to ensure that only A, B, C, and D are accepted.

	*/

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

int main()
{

	//going to use 3 arrays at least to store the answerkey, the answers the user enters,
	//and the incorrect answers.
	const int SIZE = 20; //Size of the 2 arrays
	char answerkey[SIZE] = {'B','D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 
			'D', 'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A'}, //preloaded with the correct answers
		testkey[SIZE]; //for the test taker's answers
	int incorrectkey[SIZE], //to hold all the incorrect answers
		numberCorrect = 0, //will increment based on an if statement
		counter, //for any for loops
		numberWrong = 0; //will increment based on an if statement
	bool validate = false;

	//variables will  be added later if needed
	cout << "Welcome back. Let's get this on with, shall we?\n";
	cout << "I imagine you know what to do, but just in case:\n";
	cout << "Please turn on your Caps Lock as this program will\n";
	cout << "accept single letter input to test against the answer\n";
	cout << "key. Only the letter A, B, C, or D. There is a prompt in\n";
	cout << "place should you fail to enter one of those 4 letters.\n";
	cout << "\n";
	cout << "Let us begin. For real this time.\n";
	cout << "\n";

	for (counter = 0; counter <= SIZE-1; counter++)
	{
		cout << "Please enter the letter, in all caps, for question " << counter+1 << ".\n";
		cin >> testkey[counter];
		testkey[counter] = toupper(testkey[counter]);

		//set up a switch statement with a boolean variable to flag a while pretest loop
		//only to perform the test inside the loop as well. I couldn't think of a better
		//way to do this. :/

			switch (testkey[counter])
			{
				case 'A':
					validate = false;
					break;
				case 'B':
					validate = false;
					break;
				case 'C':
					validate = false;
					break;
				case 'D':
					validate = false;
					break;
				default:
					validate = true;
			} //copy paste time
		while (validate == false)
		{
			cout << "Looks like you entered something either not in caps,\n";
			cout << "or not one of the designated letters. Please try number " << counter+1 << " again.\n";
			cin >> testkey[counter];
			testkey[counter] = toupper(testkey[counter]);
			switch (testkey[counter])
			{
				case 'A':
					validate = false;
					break;
				case 'B':
					validate = false;
					break;
				case 'C':
					validate = false;
					break;
				case 'D':
					validate = false;
					break;
				default:
					validate = true;
			} //end switch
		}//end validation loop

		//time to test if the answer is correct
		if (testkey[counter] != answerkey[counter])
		{ //the only things that have to happen for an incorrect number are to
			//count and catalog them.
			numberWrong += 1; //increment
			incorrectkey[numberWrong-1] = counter+1; 
			//the assignment says to hold the number of the incorrect one, not the answer
		}
		else if (testkey[counter] == answerkey[counter])
			numberCorrect += 1; //hooray!
		else
			cout << "Derp?\n";
		//end the if-else if here

	} //for loop ends here

	cout << "\n";
	cout << "Thank you for your time and effort! Let's see if they passed.\n";
	cout << "\n";
	//time to test whether or not the tester has passed

	if (numberCorrect >= 15)
	{ //display the number of correct, incorrect, and what ones were incorrect.
		cout << "Total number of correctly answered questions: " << numberCorrect << ".\n";
		cout << "Total number of wrongly answered questions: " << numberWrong << ".\n";
		cout << "Hooray! Get ready to be able to legally drive! Woo!\n";
		cout << "Go ahead and try our other app to help calculate average annual\n";
		cout << "vehicle costs.\n";
		if (numberWrong > 0)
		{
			cout << "And just so you know, here are the ones you got wrong: \n";
			for (counter = 0; counter <= numberWrong-1; counter++)
				//this for only goes as high as the number of incorrect questions so it won't run 20 times
			cout << incorrectkey[counter] << "\n";
		}
	}
	else if (numberWrong >= 5)
	{ //display the number of correct, incorrect, and what ones were incorrect.
		cout << "Total number of correctly answered questions: " << numberCorrect << ".\n";
		cout << "Total number of wrongly answered questions: " << numberWrong << ".\n";
		cout << "Looks like you didn't make it...\n";
		cout << "I'm so sorry...\n";
		if (numberWrong > 0)
		{
			cout << "And just so you know, here are the ones you got wrong: \n";
			for (counter = 0; counter <= numberWrong-1; counter++)
				//this for only goes as high as the number of incorrect questions so it won't run 20 times
			cout << incorrectkey[counter] << "\n";
		}
	}
	else
		cout << "Something is wrong here. Not sure what.\n";

	cout << "That's it! See you again soon.\n";
	cout << "\n";
	system("pause");
	return 0;

}