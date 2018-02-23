#include <iostream>
#include "Person.h"
#ifndef STUDENT_H
#define STUDENT_H


using namespace std;

class Student : public Person

{
public:
	double gpa;
	string major;
	int advisorID;

	Student();
	Student(int id, string name, string level, string ajor, double gpa, int idAdv);
	~Student();

	friend bool operator == (Student temp1, Student temp2);
	friend bool operator != (Student temp1, Student temp2);
	friend bool operator < (Student temp1, Student temp2);
	friend bool operator > (Student temp1, Student temp2);

	void setAdvisorID(int advisorID);

	string printStringObject();
	void printObject();

	double getGPA();
	string getMajor();
	int getAdvisorID();
};

#endif