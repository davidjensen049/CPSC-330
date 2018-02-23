/*

David Jensen 
SN 227-3734

assignemnt 5

data base assignment. 

data structures section 1,

2017

*/

#include <iostream>
#include "Genstack.h"
#include "Faculty.h"
#include "Student.h"
#include "BST.h"

using namespace std;

void displayMenu();
int getSize();

string facultyFileName = "facultyTable.txt";
int rollBackCount = 0;


BST<Student>* tempStudentTree = new BST<Student>(); //student binary search tree
BST<Faculty>* tempFacultyTree = new BST<Faculty>(); //facutly binary search tree
BST<Faculty>* masterFaculty; //faculty binary search tree
BST<Student>* masterStudent; //student binary search tree

Genstack<BST<Faculty>*> facultyStack(5); //genstack faculty 100
Genstack<BST<Student>*> studentStack(5); //genstacks student 100

int main(int argc, char** argv)
{
	string line;
	ifstream myFile("facultyTable.txt");
	if(myFile.is_open())
	{
		while(getline(myFile,line))
		{
			cout << line << endl;
		}
		myFile.close();
	}
int a, b, c;
bool continued = true;
int input;

while(continued)
{
	displayMenu();
	cin >> input;

	switch(input)
	{
	case 1:
		masterFaculty->inOrder(masterFaculty->getRoot()); //prints all the facutly and their info
		break;
	case 2:
		masterStudent->inOrder(masterStudent->getRoot()); //prints all students and thier info
		break;
	case 3:
		cout << "input the Faculty's ID number, please: ";
		int inputID;
		cin >> inputID;
		if(masterFaculty->contains(inputID))
		{
			masterFaculty->getValue(inputID).printObject();
		}
		break;
	case 4: 
		cout << "Input the Students ID number, please: "; //find and display all student info off id
		int newInput;
		cin >> newInput;
		if(masterStudent->contains(newInput))
		{
			masterStudent->getValue(inputID).printObject();
		}
		break;
	case 5:
		int newID;  //given fac id, print all info
		cout << "Input faculty ID, please: ";
		 cin >> newID;

		 if(masterFaculty->contains(newID))
		 {
		 	Faculty temp = masterFaculty->getValue(newID);

		 	int tempSize = temp.adviseesList.getSize();

		 	int* tempArray = temp.adviseesList.toPointer();

		 	int count = 0;
		 	while(tempArray[count] != NULL)
		 	{
		 		masterStudent->getValue(tempArray[count]).printObject();
		 	++count;
		 }

	}
	else //if not found contine, default
	{
		cout << "sorry, that faculty deosnt exist or contain ant assigned advisees!" << endl;
	}
	break;

	case 6:
	cout << "Input Student's ID Number, please: "; // print name and info of their faculty advises
	int studentID;
	cin >> studentID;
	if(masterStudent->contains(studentID))
	{
		int temp = masterStudent->getValue(studentID).getAdvisorID();
		masterFaculty->getValue(temp).printObject();
	}
	break;
	case 7:
	int tempID; // delete studends id
	cout << "Input the student's ID";
	cin >> tempID;

	tempFacultyTree = masterFaculty;
	tempStudentTree = masterStudent;
	facultyStack.push(tempFacultyTree);
	studentStack.push(tempStudentTree);

	if(masterStudent->contains(tempID))
	{
		masterStudent->deleteNode(tempID);

	}
	else
		cout << "Sorry, there is no faculty memebers contaning that specific ID! " << endl;
	break;

	case 8: // how to add a new student, or studnet into
	{

	int newID;
	int newAdvisorID;
	double newGPA;
	string newMajor;
	string newLevel;
	string newName;

	cout << "Input the new students ID number, please: ";
	cin >> newID;
	cin.ignore();
	cout << "Please, Input your Name: ";
	getline(cin, newName);
	cout << "Please, input your GPA: ";
	cin >> newGPA;
	cout << "Please, input your major: ";
	getline(cin, newMajor);
	cout << "Please, input your grade level(Freshman, Sophmore, Junior, Senior): ";
	getline(cin, newLevel);
	cout << "Finally, Please input your academic Advisors ID: ";
	cin >> newAdvisorID;
	if(masterFaculty->isEmpty())
	{
		cout << "Error; Not able to created the new student" << endl;
		cout << "No faculty memebers created, please first create a faculty member, followed by student!" << endl;

	}
	else if(masterFaculty->contains(newAdvisorID))
	{
		tempFacultyTree = masterFaculty;
		tempStudentTree = masterStudent;
		facultyStack.push(tempFacultyTree);
		studentStack.push(tempStudentTree);
		cout << "before you peek" << endl;
		masterStudent->inOrder(masterStudent->getRoot());

		Student newStudent(newID, newName, newLevel, newMajor, newGPA, newAdvisorID);
		masterStudent->insert(newStudent);
		masterFaculty->addIDtoList(newID, newAdvisorID);

	}
	else //if info nor working, seg default
	{
		cout << "Error, unable to created the new student" << endl;
		cout << "There does not seem to be any faculty associated with that ID number, Sorry" << endl;

	}
	break;
}
case 9:  //add advisee and faculty by id
{
	int adviseeID, newFacultyID;
	cout << "please input the advisees ID:";
	cin >> adviseeID;

	tempFacultyTree = masterFaculty;
	tempStudentTree = masterStudent;
	facultyStack.push(tempFacultyTree);
	studentStack.push(tempStudentTree);

	Student tempStudent = masterStudent->getValue(adviseeID);
	Faculty tempFaculty = masterFaculty->getValue(tempStudent.getAdvisorID());
	
	if(tempFaculty.adviseesList.find(adviseeID) == 1)
	{
		tempFaculty.adviseesList.deleteNode(adviseeID);
	}
	
	cout << "Please, input the current ID # of the new facutly: " << endl;
	cin >> newFacultyID;
	if(masterFaculty->contains(newFacultyID))
	{
		masterFaculty->addIDtoList(newFacultyID, adviseeID);
		masterStudent->changeAdvisor(adviseeID, newFacultyID);
	}
	 break;
}

case 10:
{
	int newFacultyID, tempStudentID; //add new faculty by id and new temp studenty by id
	cout << "Please input the students ID#: " << endl;
	cin >> tempStudentID;
	cout << "please input the new ID# of Faculty: " << endl;
	cin >> newFacultyID;

	tempFacultyTree = masterFaculty;
	tempStudentTree = masterStudent;
	facultyStack.push(tempFacultyTree);
	studentStack.push(tempStudentTree);
	Student tempStudent = masterStudent->getValue(tempStudentID);
	Faculty tempFaculty = masterFaculty->getValue(tempStudent.getAdvisorID());
	
	cout << "heres two" << endl;
	tempFaculty.adviseesList.printList();
	if(tempFaculty.adviseesList.find(tempStudentID) == 1)
	{
		cout << "we are going to deleteNode" << endl;
		tempFaculty.adviseesList.replace(tempStudentID);
		tempFaculty.adviseesList.printList();
		cout << "Here, in if statment" << endl;
		tempFaculty.adviseesList.printList();
	}
	else
	{ //if cant find student looking for, seg fault
		cout << " the students ID you are looking for/inputting does not exist, sorry" << endl;
		tempFaculty.adviseesList.printList();
		break;
	}
	if(masterFaculty->contains(newFacultyID))
	{
		masterFaculty->addIDtoList(tempStudentID, newFacultyID);
		masterStudent->changeAdvisor(newFacultyID, tempStudentID);
	}
	else
	{
		cout << "sorry, but there are now advisors that exist with ID you are using" << endl;

	} //if not found using id, seg fault
	break;
}
case 11:
char choice;
cout << "is this the faculty memeber you wish to delete? (please input Y for YES, or N for NO)" << endl;
cin >> choice;

tempFacultyTree = masterFaculty;
tempStudentTree = masterStudent;
facultyStack.push(tempFacultyTree); // prodcue a chocie on which way to search, y, n
studentStack.push(tempStudentTree);

if(choice == 'Y' || choice == 'y')
{
	int newFacultyID, facultyID;
	cout << "Please input the faculty members ID #: ";
	cin >> facultyID;
	Faculty tempFaculty = masterFaculty->getValue(facultyID);
	if(masterFaculty->contains(facultyID))
	{
		int* tempArray = tempFaculty.adviseesList.toPointer();
		int count = 0;
		while(tempArray[count] != NULL)
		{
			Student tempStudent = masterStudent->getValue(tempArray[count]);
			int tempStudentID = tempStudent.getID();
			++count;

			cout <<"This is what we have for the Student ID# " <<tempStudentID
			<<"\n Please enter a new faculty memebrs ID #: ";
			cin >> newFacultyID;

			masterFaculty->addIDtoList(tempStudentID, newFacultyID);
			masterStudent->changeAdvisor(newFacultyID, tempStudentID);
		}
		masterFaculty->deleteNode(facultyID);
	}
	else 
		cout << "Sorry, I was not able to find any faculty member related to that ID#" << endl;
}
else if(choice == 'N' || choice == 'n') // if the chocie is no, N,n
continue;
break;

case 12:
cout << "Size of fauclty stack before the Rollback: "  << endl; //had trouble with the .getSize function here
cout << "Size of student stack before the Rollback: " << endl;
++rollBackCount;
if(rollBackCount < 5)
{
	cout << studentStack.peek() << endl;
	tempFacultyTree = facultyStack.pop();
	tempStudentTree = studentStack.pop();

	cout << "after" << studentStack.peek() << endl;

	masterFaculty = tempFacultyTree;
	masterStudent = tempStudentTree;
}

else if(rollBackCount >= 5)
cout << "sorry, you have exceed the amout of rollback trieds which is 5. " << endl;

cout << "\n size of the faculty stack after the Rollback is: " << endl;
cout << "\n the size of the student stack after the Rollback is: " << endl; //had trouvle with the.getsize function as well here

break;

case 13:
{
	int newID; //adding new info bassed on department, id and name, facutlyu member
	string newDepartment;
	string newLevel;
	string newName;

	cout << "Plese enter the new ID #: ";
	cin >> newID;
	cin.ignore();
	cout << "please input your department: ";
	getline(cin, newDepartment);
	cout << "Please enter your name: ";
	getline(cin, newName);
	cout << "Please enter your current level(associate prof, assistant prof, lectureer, etc): ";
	getline(cin, newLevel);

	tempFacultyTree = masterFaculty;
	tempStudentTree = masterStudent;
	facultyStack.push(tempFacultyTree);
	studentStack.push(tempStudentTree);

	Faculty newFaculty(newID, newName, newLevel, newDepartment);
	masterFaculty->insert(newFaculty);
	break;

}

case 14:

masterFaculty->writeToFile("facultyTable.txt");
masterStudent->writeToFile("studentTable.txt");

exit(0);

default:

continued = false;
}
}
	return 0;
}

void displayMenu() //display menue and welcoming function/windows
{
	cout <<"\n Welcome to the Student & Faculty Records Database\n"
	"\n Please chose an option from the menu below\n-----------------\n" << endl;
	cout <<"\n1. Print all Studernts and their personal informatin" << endl;
	cout <<" 2. Print all Faculty and their personal information" << endl;
	cout << "3. Find and display student information from the students ID" << endl;
	cout << "4. Find and display faculty information from faculty ID" << endl;
	cout << "5. Given a students ID, print name and info of their faculty advisor" << endl;
	cout << "6. Given a faculty ID, print ALL the names and into of his/her advisees" << endl;
	cout << "7. Add a new student" << endl;
	cout << "8. Delete a student given the ID" << endl; 
	cout << "9. Add a new faculty member" << endl;
	cout <<"10. Delete a faculty member given the ID" << endl;
	cout << "11. Change a student's .advisor given the student and new faculty ID" << endl;
	cout << "12. Remove an advisee from a faculty member given the ID" <<endl;
	cout << "13. Rollback" << endl;
	cout << "14. Exit" <<endl;


}
















