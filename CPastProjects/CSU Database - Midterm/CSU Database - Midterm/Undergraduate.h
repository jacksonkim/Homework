/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 7, CSU Database - Midterm - 10/1/12

	Description: The Undergraduate class has at least the following responsibilities:
    -    The student's classification: Freshman, Sophomore, Junior, Senior

	*/
#ifndef UNDERGRADUATE_H
#define UNDERGRADUATE_H

#include <string>
#include "Student.h"

using namespace std;

class Undergraduate : public Student
{
protected:
	string studentClass;

public:
	//constructors
	Undergraduate();
	Undergraduate(string);

	//mutators
	void setClass(string);

	//accessors
	string getClass() const;

	//StudentType studentTest();

};

#endif //UNDERGRADUATE_H