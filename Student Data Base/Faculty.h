#include <iostream>
#include "Person.h"
#include <string>
#include "DoublyList.h"
using namespace std;

class Faculty : public Person

{
	public:
		string department;
		DoublyList<int> adviseesList;

		Faculty();
		Faculty(int ID, string name, string level, string department);
		~Faculty();

		string getDepartment();

		friend bool operator < (Faculty temp1, Faculty temp2);
		friend bool operator > (Faculty temp1, Faculty temp2);
		friend bool operator == (Faculty temp1, Faculty temp2);
		friend bool operator != (Faculty temp1, Faculty temp2);

		void printObject();
		string printStringObject();
};
