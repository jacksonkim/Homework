/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 7, CSU Database - Midterm - 10/1/12

	Description: CSU has requested a database program be developed for them to maintain
		information on their student body. All information on the students will be held in files
		external to the program. These files will be read from and written to, but only at the
		beginning of the program and before it is closed. There will also be logins in the files,
		as this database should only be accessible to administrators at the school.

		The program will utilize classes for the students' information. A basic Student object
		will hold the most basic information about the student, like name, student number,
		major, etc. This class is to be inherited by two different classes, Undergraduate and
		Graduate, that add a classification for year then degree type and thesis topic respectively.

		It will be menu driven. Firstly, of course, will be a login barrier to ensure that the person
		altering student information is an administrator. That will open up the menu for actually
		reading student information, altering student information, and editing course information.

		All the information pertaining to logins will be read at the beginning of the program and
		loaded into vectors or arrays. Once the login information is correct, the program will load in
		the student information files into vectors or arrays for the administrator to utilize.

		The menu, once the admin has logged in, will consist of a number of options.

		1. Search for student by first or last name
		2. Show entire university
		3. Show/Edit information
		4. Add courses to student's schedule
		5. Remove courses from student's schedule
		6. Log out

		It is set up this way to avoid students accessing their own information.

		UML diagram will display all classes and their attributes/operations.
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Administrator.h"
#include "Student.h"
#include "Undergraduate.h"
#include "Graduate.h"

using namespace std;

void fileTest(fstream&);
void csuDatabase();
void displayStudent(Student);
//void displayUGrad(Undergraduate);
//void displayGrad(Graduate);
void courseManagement(Student&);
void studentManagement(Student&);
void studentSearch(Student [], int);

int main()
{
	//create variables needed in this function
	fstream admins("Administrators.txt");
	string user,
		usertemp,
		pass,
		passtemp;
	bool login = false;

	//GREETINGS AND SALUTATIONS
	cout << "Welcome to the CSU Student Database.\n";
	cout << "This database is only to be used by administrators of the school.\n";
	cout << "Loading up the administrator logins.\n";

	//made a function for this because i was gonna have to copypasta
	//pass the fstream object into it to check for open errors
	//the function uses exit(0) if the file did not open.
	fileTest(admins);

	//dynamically allocate array depending on number as the first line of the admin file
	int numOfAdmins;	
	admins >> numOfAdmins;
	Administrator *admin = new Administrator[numOfAdmins];

	//for as many logins are in the file, load them all into an array of Administrator objects
	for (int count = 0; count < numOfAdmins; count++)
	{
		admins >> usertemp;
		admin[count].setUser(usertemp);
		//this is important later
		admins >> passtemp;
		admin[count].setPass(passtemp);
	}
	
	cout << "Everything has been set up.\n";

	//loop to process logins
	do
	{
		//a bit of instruction
		cout << "Please remember that usernames and passwords are case-sensitive. \nUsernames are";
		cout << " lowercase only. Passwords are set by the user. \nPlease keep track of your own passwords.\n";
		cout << "Please input your special username: ";
		cin >> user;

		cout << "And your password: ";
		cin >> pass;

		for (int count = 0; count < numOfAdmins; count++)
		{
			//pass through the admin array and check if the username entered matches any
			//of the usernames in the array
			if (user != admin[count].getUser())
			{ //if no usernames match, ensure that the boolean variable that controls the loop is set to false
				login = false;				
			}
			else if (user == admin[count].getUser())
			{ //if the username does match the contents of the array, check the password
				if (pass != admin[count].getPass())
				{ 
					login = false;
				}
				else if (pass == admin[count].getPass())
				{ //username is correct, password is correct, all is in place. display a salutation
					//set the variable to true to allow the loop to exit
					cout << "Everything checks out. Welcome back.\n";
					login = true;
				} //end password if
			} //end username if
		}; //end for

	} while (login != true); //end do-while for login

	csuDatabase(); //the only way to get here is to login properly and exit the loop
		//load up the csu database to edit student information

	//the admin file will not be written to. the only person that should write to that is the
	//IT department head to ensure that noone is added in through any other means

	cout << "Thank you for your work today. Everyone at the school has appreciated your work, and\n";
	cout << "I'm sure the students do as well. Have a good day or night.";
	cout << "\n";
	system("pause");
	return 0;
};

/* function name: fileTest
	accepts one fstream argument - tests for file open errors.
	if there is a file open error, exit the application - exit(0)
	If there is no file open error, nothing happens
*/
void fileTest(fstream &tester)
{
	if (tester.fail())
	{
		cout << "Oh no, it looks like the file didn't open properly. Please ensure that all files\n";
		cout << "are in the correct places in relation to this program.\n";
		cout << "Program will now exit.\n";
		cout << "\n";
		system("pause");
		exit(0);
	}
};

/* function name: csuDatabase
	no arguments are passed into it. only way to access is by logging in properly
	in the main function

	function performs all the student editing through various functions
*/
void csuDatabase()
{
	//create variables
	fstream undergrads("UnderGrads.txt");
	fstream grads("Grads.txt");

	int menuOption,
		numOfUndergrads, //undergrads and grads are in separate files
		numOfGrads, //their individual values are held here
		numOfStudents; //the values of undergrads and grads will be added to
						//supply the contents of this variable

	string fname,
		lname,
		studentID,
		major,
		studentClass,
		degreeType,
		thesisTopic;
	string *schedule;

	int enrollHours,
		numOfCourses;

	//check for file open errors
	fileTest(undergrads);
	fileTest(grads);

	Student *students;
	Undergraduate *understudents;
	Graduate *gradstudents;
	undergrads >> numOfUndergrads;
	grads >> numOfGrads;
	numOfStudents = numOfGrads + numOfUndergrads;

	understudents = new Undergraduate[numOfUndergrads];
	for (int count = 0; count < numOfUndergrads; count++)
	{
		undergrads >> fname;
		undergrads >> lname;
		undergrads >>studentID;
		undergrads >> major;
		undergrads >> numOfCourses;		
		schedule = new string[numOfCourses];
		for (int count2 = 0; count2 < numOfCourses; count2++)
		{
			undergrads >> schedule[count2];
		}
		undergrads >> enrollHours;
		undergrads >> studentClass;

		understudents[count].setAll(fname, lname, studentID, major, schedule, numOfCourses, enrollHours);
		understudents[count].setClass(studentClass);		
	}

	//grad students now
	gradstudents = new Graduate[numOfGrads];
	for (int count = 0; count < numOfGrads; count++)
	{
		grads >> fname;
		grads >> lname;
		grads >>studentID;
		grads >> major;
		grads >> numOfCourses;		
		schedule = new string[numOfCourses];
		for (int count2 = 0; count2 < numOfCourses; count2++)
		{
			grads >> schedule[count2];
		}
		grads >> enrollHours;
		grads >> degreeType;
		grads >> thesisTopic;

		gradstudents[count].setAll(fname, lname, studentID, major, schedule, numOfCourses, enrollHours);
		gradstudents[count].setBoth(degreeType, thesisTopic);
	}

	//combine the arrays into one
	students = new Student[numOfStudents];
	for (int count = 0; count < numOfUndergrads; count++)
	{
		students[count] = understudents[count];
	}

	for (int count = numOfUndergrads; count < numOfStudents; count++)
	{
		students[count] = gradstudents[count];
	}

	do
	{
		cout << setw(25) << "Main Menu\n";
		cout << "1. Display the entire university\n";
		cout << "2. Search for student by name or student number\n";		
		cout << "3. Show/Edit student information\n";
		cout << "4. Edit/Remove courses from student's schedule\n";
		cout << "5. Log out\n";
		cin >> menuOption;

		switch (menuOption)
		{
		case 1: //for showing the entire university
			for (int count = 0; count < numOfStudents; count++)
					displayStudent(students[count]);
			break;
		case 2: //for searching for a student
			studentSearch(students, numOfStudents);
			break;
		case 3: //for show/edit information
			studentSearch(students, numOfStudents);
			break;
		case 4: //course management
			studentSearch(students, numOfStudents);
			break;
		case 5: //log out
			continue;
			break;
		default:
			break;
		}
	} while (menuOption != 5);

	undergrads << numOfUndergrads;
	for (int count = 0; count < numOfUndergrads; count++)
	{
		undergrads << students[count].getFName() << " " << students[count].getLName() << " " << students[count].getSID()
			<< " " << students[count].getMajor() << " " << students[count].getHours() << " " << students[count].getNumofCourses()
			<< " ";
		for (int count2 = 0; count2 < students[count].getNumofCourses(); count2++)
			undergrads << students[count].getCourse(count2);
	}

	grads << numOfUndergrads;
	for (int count = 0; count < numOfUndergrads; count++)
	{
		grads << students[count].getFName() << " " << students[count].getLName() << " " << students[count].getSID()
			<< " " << students[count].getMajor() << " " << students[count].getHours() << " " << students[count].getNumofCourses()
			<< " ";
		for (int count2 = 0; count2 < students[count].getNumofCourses(); count2++)
			grads << students[count].getCourse(count2);
	}
};

void displayStudent(Student display)
{
	cout << "Last Name: " << display.getLName() << setw(15) << "First Name: " << display.getFName() << "\n";
	cout << "Student ID: " << display.getSID() << setw(15) << "Major: " <<display.getMajor() <<"\n";
};

//void displayUGrad(Undergraduate display)
//{
//	cout << "Last Name: " << display.getLName() << setw(15) << "First Name: " << display.getFName() << "\n";
//	cout << "Classification: " << display.getClass() << "\n";
//	cout << "Student ID: " << display.getSID() << setw(15) << "Major: " <<display.getMajor() <<"\n";
//
//};
//
//void displayGrad(Graduate display)
//{
//	cout << "Last Name: " << display.getLName() << setw(15) << "First Name: " << display.getFName() << "\n";
//	cout << "Student ID: " << display.getSID() << setw(15) << "Major: " <<display.getMajor() <<"\n";
//	cout << "Degree Type: " << display.getDegree() << "Thesis Topic: " << display.getThesis() << "\n";
//};

void courseManagement(Student &courseEditor)
{
	int menuOption,
		count;
	char correct;
	string temp;

	do
	{
		cout << "Which course would you like to edit?\n";
		for (count = 0; count < courseEditor.getNumofCourses(); count++)
		{
			cout << count+1 << ". Edit course " << courseEditor.getCourse(count) << "\n";
		}
		cout << ++count << ". Delete course\n";
		cout << ++count << ". Exit\n";
		cout << "Please choose which bit of information you would like to alter: ";
		cin >> menuOption;

		while (menuOption != count || menuOption != count-1)
		{
			do
			{
			cout << "And what would you like to change it to?\n";
			cout << "All caps please: ";
			getline(cin, temp);
			
			cout << "Is this " << temp << " correct?\n";
			cout << "Please enter Y for correct: ";
			cin >> correct;
			} while (toupper(correct) !='Y');
		} //end while

		if (menuOption == count-1)
		{
			cout << "Which one would you like to delete?\n";
			cout << "Please choose from an option above: ";
			cin >> menuOption;
			if (menuOption != count)
			{
				courseEditor.setCourse(count-1, " ");
			}
		}
		courseEditor.setCourse(menuOption-1, temp);
	}while (menuOption !=count);
};

void studentManagement(Student &editor)
{
	int menuOption;
	char correct;
	string temp;

	do
	{
		cout << "Which field would you like to edit?\n";
		cout << "1. FIRST NAME\n";
		cout << "2. LAST NAME\n";
		cout << "3. MAJOR\n";
		cout << "4. Courses - Will open in another menu\n";
		cout << "5. No edits\n";
		cout << "Student numbers cannot be altered in this system.\n";
		cout << "Please choose which bit of information you would like to alter: ";
		std::cin >> menuOption;

		switch (menuOption)
		{
		case 1: //for first names
			cout << "Please enter in the new FIRST name: ";
			cin >> temp;

			do
			{
				cout << "Is this correct: " << temp << "\n";
				cout << "Please enter Y for yes: ";
				cin >> correct;
			} while (toupper(correct) != 'Y');

			editor.setFName(temp);

			break;
		case 2: //for last name
			cout << "Please enter in the new LAST name: ";
			cin >> temp;

			do
			{
				cout << "Is this correct: " << temp << "\n";
				cout << "Please enter Y for yes: ";
				cin >> correct;
			} while (toupper(correct) != 'Y');

			editor.setLName(temp);
			break;
		case 3: //for majors
			cout << "Please enter in the new MAJOR: ";
			cin >> temp;

			do
			{
				cout << "Is this correct: " << temp << "\n";
				cout << "Please enter Y for yes: ";
				cin >> correct;
			} while (toupper(correct) != 'Y');

			editor.setMajor(temp);
			break;
		case 4:
			courseManagement(editor);
			break;
		case 5:
			continue;
		}

	} while (menuOption != 5);

};

void studentSearch(Student search[], int size)
{
	int menuOption;
	char correctStudent,
		edit;
	string searchparam;

	do
	{
		cout << "You'd like to search? Remember all information is in all caps.\n";
		cout << "Please choose an option below:\n";
		cout << "1. Search by last name\n";
		cout << "2. Search by first name\n";
		cout << "3. Search by student number\n";
		cout << "4. Exit\n";
		cin >> menuOption;

		switch (menuOption)
		{
		case 1:
			cout << "Please enter in the LAST NAME: ";
			cin >> searchparam;
			for (int count = 0; count < size; count++)
			{
				if ( searchparam == search[count].getLName())
				{
					cout << "Were you looking for this student?\n";
					displayStudent(search[count]);
					cout << "If this is the student you're looking for, please press Y: ";
					cin >> correctStudent;
					if (toupper(correctStudent) == 'Y')
					{
						cout << "Would you like to edit this student's information?\n";
						cout << "Please enter Y to edit: ";
						cin >> edit;
						if (toupper(edit) == 'Y')
						{
							studentManagement(search[count]);
						}//end yes to edit
					}//end correctstudent
					else
					{
						cout << "No editting today?\n";
					}
				}//end if
				else
				{
					cout << "Looks like the last name was not found. Are you sure you typed it in correctly?\n";
				}
			}; //end for
			break;
		case 2:
			cout << "Please enter in the FIRST NAME: ";
			cin >> searchparam;
			for (int count = 0; count < size; count++)
			{
				if ( searchparam == search[count].getFName())
				{
					cout << "Were you looking for this student?\n";
					displayStudent(search[count]);
					cout << "If this is the student you're looking for, please press Y: ";
					cin >> correctStudent;
					if (toupper(correctStudent) == 'Y')
					{
						cout << "Would you like to edit this student's information?\n";
						cout << "Please enter Y to edit: ";
						cin >> edit;
						if (toupper(edit) == 'Y')
						{
							studentManagement(search[count]);
						}//end yes to edit
					}//end correctstudent
					else
					{
						cout << "No editting today?\n";
					}
				}//end if
				else
				{
					cout << "Looks like the first name was not found. Are you sure you typed it in correctly?\n";
				}
			}; //end for
			break;
		case 3:
			cout << "Please enter in the student number: ";
			cin >> searchparam;
			for (int count = 0; count < size; count++)
			{
				if ( searchparam == search[count].getSID())
				{
					cout << "Were you looking for this student?\n";
					displayStudent(search[count]);
					cout << "If this is the student you're looking for, please press Y: ";
					cin >> correctStudent;
					if (toupper(correctStudent) == 'Y')
					{
						cout << "Would you like to edit this student's information?\n";
						cout << "Please enter Y to edit: ";
						cin >> edit;
						if (toupper(edit) == 'Y')
						{
							studentManagement(search[count]);
						}//end yes to edit
					}//end correctstudent
					else
					{
						cout << "No editting today?\n";
					}
				}//end if
				else
				{
					cout << "Looks like the student number was not found. Are you sure you typed it in correctly?\n";
				}
			}; //end for
			break;
		case 4:
			continue;
		}
	} while (menuOption !=4);
};
