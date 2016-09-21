/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 7, CSU Database - Midterm - 10/1/12

	Description: The Student class provides the basic framework for creating subclasses.
		It will contain the following attributes:
		-    First and Last Name of the student
		-    Student ID (9 digits, starting with the number 900)
		-    Major
		-    Current class schedule
		-    Current enrolled course hours

		string fname,
		lname,
		studentID,
		major;
	string *schedule;
	bool isUndergrad,
		isGrad;

	int enrollHours,
		numOfCourses;
*/

#include "Student.h"
#include "Undergraduate.h"
#include "Graduate.h"

using namespace std;

//constructors
Student::Student()
{
	fname = "First name required";
	lname = "Last name required";
	studentID = "900000000";
	major = "No Major Entered";
	enrollHours = 0;
};

Student::Student(string fn, string ln, string sid)
{
	fname = fn;
	lname = ln;
	studentID = sid;
	major = "No Major Entered";
	enrollHours = 0;
};

Student::Student(string fn, string ln, string sid, string m)
{
	fname = fn;
	lname = ln;
	studentID = sid;
	major = m;
	enrollHours = 0;
};

Student::Student(string fn, string ln, string sid, string m, int size, int eh)
{
	fname = fn;
	lname = ln;
	studentID = sid;
	major = m;
	enrollHours = eh;

	createCourse(size);
};

//copy constructor
Student::Student(const Student &obj)
{
	fname = obj.fname;
	lname = obj.lname;
	studentID = obj.studentID;
	major = obj.major;
	enrollHours = obj.enrollHours;

	schedule = new string[numOfCourses];
	for (int count = 0; count < numOfCourses; count++)
	{
		schedule[count] = obj.schedule[count];
	}
};


//destructor
Student::~Student()
{
	delete [] schedule;
};

//mutators
void Student::setFName(string fn)
{
	fname = fn;
};

void Student::setLName(string ln)
{
	lname = ln;
};

void Student::setName(string fn, string ln)
{
	fname = fn;
	lname = ln;
};

void Student::setSID(string sid)
{
	studentID = sid;
};

void Student::setMajor(string m)
{
	major = m;
};

void Student::setSchedule(int size, string *sch)
{
	createCourse(size);
};

void Student::setHours(int eh)
{
	enrollHours = eh;
};

void Student::setCourse(int sub, string c)
{
	schedule[sub] = c;
};

void Student::setNumofCourses(int noc)
{
	numOfCourses = noc;
};

void Student::setAllCourses(string c[], int size)
{
	schedule = c;	
};

void Student::setAll(string fn, string ln, string sid, string m, string c[], int size, int eh)
{
	fname = fn;
	lname = ln;
	studentID = sid;
	major = m;
	enrollHours = eh;

	numOfCourses = size;
	schedule = new string[size];
	schedule = c;
};

void Student::createCourse(int size)
{
	numOfCourses = size;
	schedule = new string[size];
	for (int count = 0; count < size; count++)
	{
		schedule[count] = DEF_COURSE;
	}
};


//accessors
string Student::getFName()  const
{
	return fname;
};

string Student::getLName() const
{
	return lname;
};

string Student::getName() const
{
	string wholename = fname;
	wholename.append(" ");
	wholename.append(lname);

	return wholename;
};

string Student::getSID() const
{
	return studentID;
};

string Student::getMajor() const
{
	return major;
};

string Student::getCourse(int sub) const
{
	return schedule[sub];
};

int Student::getNumofCourses() const
{
	return numOfCourses;
};

int Student::getHours() const
{
	return enrollHours;
};

//enum thing
	//StudentType studentTest()
	//{
	//	return STUDENT;
	//};