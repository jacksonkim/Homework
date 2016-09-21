/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 7, CSU Database - Midterm - 10/1/12

	Description: The Student class provides the basic framework for creating subclasses.
		It will contain the following attributes:
		-    First and Last Name of the student
		-    Student ID (9 digits, starting with the number 900)
		-    Major
		-    Current class schedule
		-    Current enrolled course hours

		Include an attribute to test whether the inherited class is Undergrad or Grad student
		so as to ensure that they are displayed properly.
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

const string DEF_COURSE = "No courses entered";
enum StudentType
{
	UGRAD,
	GRAD,
	STUDENT
};

class Student
{
protected:
	string fname,
		lname,
		studentID,
		major;
	string *schedule;

	int enrollHours,
		numOfCourses;

	void createCourse(int);

public:
	//constructors
	Student();
	Student(string, string, string);
	Student(string, string, string, string);
	Student(string, string, string, string, int, int);
	//copy constructor
	Student(const Student&);

	//destructor
	~Student();

	//mutators
	void setFName(string);
	void setLName(string);
	void setName(string, string);
	void setSID(string);
	void setMajor(string);
	void setSchedule(int, string*);
	void setHours(int);
	void setCourse(int, string);
	void setNumofCourses(int);
	void setAllCourses(string [], int);
	void setAll(string, string, string, string, string [], int, int);

	//accessors
	string getFName()  const;
	string getLName() const;
	string getName() const;
	string getSID() const;
	string getMajor() const;
	string getCourse(int) const;
	int getNumofCourses() const;
	int getHours() const;

	//enum thing
	//virtual StudentType studentTest();

};

#endif //STUDENT_H