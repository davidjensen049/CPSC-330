#include "Faculty.h"

Faculty::Faculty()
{

}

Faculty::Faculty(int ID, string name, string level, string department) : Person(ID, name, level)
{
	this->adviseesList = DoublyList<int>();
	this->department = department;
}

Faculty::~Faculty()
{
	cout << "Faculty Object Destroyed" << endl;
}

string Faculty::getDepartment()
{
	return department;
}
 
     bool operator == (Faculty temp1, Faculty temp2)
     {
     return (temp1 == temp2);
 }
	 bool operator != (Faculty temp1, Faculty temp2)
	 {
	 	return (temp1 != temp2);
	 }
	 bool operator < (Faculty temp1, Faculty temp2)
	 {
	 	return (temp1 < temp2);
	 }
	 bool operator > (Faculty temp1, Faculty temp2)
	 {
	 	return (temp1 > temp2);
	 }

	 void Faculty::printObject()
	 {
	 	cout << "Name: " << name
	 	<< "\nLevel: " << level
	 	<< "\nID #: " << ID
	 	<< "\n Department: " << department << endl;
	 }

	 string Faculty::printStringObject()
	 {
	 	string id = to_string(ID);
	 	return name + "," + id + "," + level + "," + department + ",";
	 }