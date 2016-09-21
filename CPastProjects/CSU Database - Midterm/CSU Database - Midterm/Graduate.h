/* CIST 2362 - 20786 - Kimberly Jackson - SID: 0332
	Week 7, CSU Database - Midterm - 10/1/12

	Description: The Graduate class has at least the following responsibilities:
    -    The Degree type: Specialist, Master, Doctorate
    -    Thesis Topic

	*/

#ifndef GRADUATE_H
#define GRADUATE_H

#include <string>
#include "Student.h"

using namespace std;

class Graduate : public Student
{
protected:
	string studentDegree,
		thesisTopic;

public:
	//constructors
	Graduate();
	Graduate(string);
	Graduate(string, string);

	//mutators
	void setDegree(string);
	void setThesis(string);
	void setBoth(string, string);

	//accessors
	string getDegree() const;
	string getThesis() const;

	//StudentType studentTest();

};

#endif //GRADUATE_H