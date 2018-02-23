#include <iostream>
#include <string>

#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person
{

public:

	int ID;
	string name;
	string level;

	Person();
	Person(int ID, string name, string level);
	virtual ~Person();

	int getID();
	 virtual void printObject();
	 virtual string printStringObject();

	string getName();
	string getLevel();

};
#endif