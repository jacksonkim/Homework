/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332

Week 1, Program 2 - Exam Grader

	Description: Reads the contents of the CorrectAnswers.txt file into a char array,
		then compares them to another char array of the student's answers. The
		program should determine the percentage of answers that were correct and
		missed and then display the following:

		List of Questions Missed, showing the correct answer and the incorrect answer
			provided by the student.
		Total number of questions missed.
		Percentage of questions answered correctly.
			(Correctly answered/total number of questions)
		If the percentage of correctly answered is > 70, indicate a pass. If not, indicate
			a fail.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main ()
{

	const int SIZE = 20; //size for the arrays
	char answerKey[SIZE],
		testKey[SIZE];
	int numberWrong=0,
		incorrectkey[SIZE];
	float numberCorrect=0, //to avoid integer division this was made a float
		percentgrade;
	ifstream answerkey,
		testkey;

	cout << "You have started up the Exam Grader machine.\n";
	cout << "\n";
	cout << "Please remember that all information used to process the exams\n";
	cout << "are user created files.\n";
	cout << "If you wish to use a different answer key or student answers,\n";
	cout << "please alter the files associated with this program.\n";
	cout << "\n";
	cout << "First, the answer key will be loaded in.\n";
	answerkey.open("CorrectAnswers.txt");
	cout << "Let's make sure that opened properly.\n";

	if (answerkey)
	{
		cout << "\n";
		cout << "It would appear that the answer key opened without issue.\n";
		cout << "Let's load up the answers into the programe.\n";
		for (int count=0; count <SIZE; count++)
		{
			answerkey >> answerKey[count];
		}
	}

	cout << "Now that the answer key has been loaded up, time to open\n";
	cout << "the student's answers.\n";
	cout << "\n";
	testkey.open("StudentAnswers.txt");
	cout << "Let's make sure that opened properly.\n";

	if (testkey)
	{
		cout << "\n";
		cout << "All is well.\n";
		cout << "Time to load the answers in.\n";

		for (int count=0; count < SIZE; count++)
			testkey >> testKey[count];
	}

	cout << "Let's get on with the testing, shall we?\n";

	for (int count=0; count < SIZE; count++)
	{
		if (testKey[count] != answerKey[count])
		{
			numberWrong += 1;
			incorrectkey[numberWrong-1] = count+1;
		}
		else if (testKey[count] == answerKey[count])
		{
			numberCorrect += 1;
		}
		else
			cout << "Hm...\n";
	}

	cout << "Now that that's finally over, let's see how they did.\n";

	percentgrade = (numberCorrect/SIZE)*100;
	cout << "It looks like the grade they got was a " << percentgrade << "%\n";

	if (percentgrade >= 70)
	{
		cout << "Good job! They passed.\n";
		if (numberWrong > 0)
		{
			cout << "Although, they did get " << numberWrong << " questions wrong.\n";
			cout << "The questions they got wrong were:\n";
			cout << setw(10) << "Question" << setw(10) << "Answer" << setw(10) << "Student\n";
			for (int count=0; count < numberWrong; count++)
			{
				int incorrectnumber = incorrectkey[count]-1;
				cout << setw(10) << incorrectkey[count] << setw(10) << answerKey[incorrectnumber] << setw(10) << testKey[incorrectnumber] << "\n";
			} //end correct for loop here
		}//end numberwrong > 0 if here
		else
			cout << "Holy moosh, they got every single one correct!\n";
	} //end passing if here
	else if (percentgrade < 70)
	{
		cout << "Unfortunately, they did not pass.\n";
		if (numberWrong > 0)
		{
			cout << "Although, they did get " << numberWrong << " questions wrong.\n";
			cout << "The questions they got wrong were:\n";
			cout << setw(10) << "Question" << setw(10) << "Answer" << setw(10) << "Student\n";
			for (int count=0; count < numberWrong; count++)
			{				
				int incorrectnumber = incorrectkey[count]-1; //had to do this or it would come up with an error
				cout << setw(10) << incorrectkey[count] << setw(10) << answerKey[incorrectnumber] << setw(10) << testKey[incorrectnumber] << "\n";
			} //end correct for loop here
		}//end numberwrong > 0 if here
	}

	cout << "\n";
	system("pause");
	return 0;
};