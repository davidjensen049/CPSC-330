#include <iostream>
#include <string>
#include <fstream>
#include "GenQueue.h"
#include "Student.cpp"
#include "Registrar.cpp"

using namespace std;

int mian(int argc, char** argv)
{
	GenQueue<Student> students;
	//regisrar pointer window

	int timer = 0;
	string fileName;
	string line;
	int lineCount = 0;
	int minutesToWait;

	if(argc > 1)
	{
		fileName = argv[1];
	}

	ifstream myFile(fileName);
	if(myFile.is_open())
	{
		while(getline (myFile, line))
		{
			++lineCount;
			if(lineCount == 1)
				cout <<"Hello sir" << endl;
			else
			{
				minutesToWait = stoi(line);
				getline(myFile, line);
				for(int i = o; i < stoi(line); ++i)
				{

				}
			}
		}
	}
	return 0;
}