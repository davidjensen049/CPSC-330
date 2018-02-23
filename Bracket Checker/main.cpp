/*
David Jensen sn: 227-3734
Data Structures - 1
Assignment 3, Stacks 
jense17
10/11/17



*/
#include "GenStack.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	//decalring variables, setting paramaters
	bool again = false; //bool to determine if its going to run again
	char response;
	char frontPar = '(', backPar = ')'; //checks the parinthesis
	char frontBrace = '{', backBrace = '}'; //checks the brackets
	char frontBracket = '[', backBracket = ']'; //checks brackets
	bool firstRun = true; //checks if its the first go
	string line;
	string fileName;

	GenStack<char> g(10); //generating a stack size

	do //supposed to continuously loop till satisfied with outcome
	{
		int row = 0; 
		if(firstRun) //checks if first go
		{
			if(argc > 1) //if it is, go to next command
			{

			fileName = argv[1]; //assigns
			}

		}	
	

	else
	{
		cout << "Enter your file name, please: "; //suppeto prompt file
		cin >> fileName;
	}

	ifstream myFile (fileName); // opening the stream
	if(myFile.is_open())
	{
		while (getline (myFile, line)) //looping through line by line
		{
			++row;
			for(int i = 0; i < line.length(); i++)
			{
				if(line[i] == frontPar || line[i] == frontBrace || line[i] == backBracket)
				{
					g.push(line[i]); //if open, push

				}
				else if(line[i] == backPar || line[i] == backBrace || line[i] == backBracket)
				{
					if(g.isEmpty() == 1) //if open compare
					{
						cout << "Line" << row << ": expected " << g.emptyOpposite(line[i]) <<" and found" << line[i] << endl;
						exit(0); //if theres an errof
					}
					else if(line[i] != g.opposite())
					{
		
						cout << "Line " << row<< ": expected" << g.opposite() << " and found: " << line[i] << endl;
						exit(0); //
					}
					g.pop(); //if not pop 

					}
				}
			}
			myFile.close();
		}
		if(g.getSize() != 0) //if makes it this far, produces out
		{
			for(int i = 0; i < g.getSize(); ++i)
			{
				cout << "Reached end of file: missing " << g.opposite() << endl;
				g.pop();
			}
			exit(0);
			}
		
		cout << "syntax is correct.\n"
		<< "do you want to check out another file? please enter (Y) for Yes, or (N) for No. " << endl;
		cin >> response;
		if(response == 'Y' || response == 'y') //setting all possible responses to rerun.
			again = true;
		else if(response == 'N' || response == 'n')
			again = false;

		firstRun = false;
	}
	while(again == true);
	
	return 0;
}

