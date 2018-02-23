#include "Student.h"
#include <sstream>
#include <iostream>

using namespace std;

Student :: Student(){};

Student :: Student(int id, string name, string level, string major, double gpa, int advisorID) : Person(id, name, level)
{
	this->advisorID = advisorID;
	this->gpa = gpa;
	this->major = major;
}

Student :: ~Student()
{
	cout << "Student Object destroyed" << endl;
}
//cpmparing ids
     bool operator == (Student temp1, Student temp2)
     {
     return (temp1 == temp2);
 }
	 bool operator != (Student temp1, Student temp2)
	 {
	 	return (temp1 != temp2);
	 }
	 bool operator < (Student temp1, Student temp2)
	 { //comparing students id
	 	return (temp1 < temp2);
	 }
	 bool operator > (Student temp1, Student temp2)
	 {//coparing id
	 	return (temp1 > temp2);
	 }

void Student::setAdvisorID(int advisorID)
{
	this->advisorID = advisorID;
}

int Student :: getAdvisorID()
{
	return advisorID;
}

string Student::printStringObject()
{
	string id = to_string(Person::ID);
	ostringstream strs;
	strs << gpa;
	string str = strs.str();
	string adviseID = to_string(advisorID);
	
	return Person::name + "," + id + "," + Person::level + "," + major + "," + str + "," + adviseID + ",";
	

}

double Student::getGPA()
{
	return gpa;
}
string Student::getMajor()
{
	return major;
}

void Student :: printObject()
{
	cout << "Name: " <<Person::name
	<<"\nAdvisor ID: " <<advisorID 
	<<"\nID #:" <<Person::ID
	<<"\n Grade level: " <<Person::level
	<<"\nMajor: " << major
	<<"\n GPA: " << gpa << endl;
}