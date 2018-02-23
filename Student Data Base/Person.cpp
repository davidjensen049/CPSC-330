#include "Person.h"

using namespace std;

Person::Person()
{

}
Person::Person(int ID, string name, string level)
{
	this->ID = ID;
	this->name = name;
	this->level = level;

}
Person::~Person()
{

}

int Person::getID()
{
	return ID;
}

string Person::getName()
{
	return name;
}

string Person::getLevel()
{
	return level;
}

void Person::printObject()
{
	cout << "\n ID#: " << ID
		<< "\n Level: " << level 
		<< "\n Name: " << name << endl;

}

string Person::printStringObject()
{
	string id = to_string(ID);
	return name + "," + id + "," + level + ",";
}