#include "Grid.h"
#include "Gol.h"
#include <stdio.h>


Grid::Grid()
{
	generation =0;
	halt = false;
}

Grid::~Grid()
{
	for(int i=0; i < length; ++i)
	{
		delete [] grid1[i];
		delete [] grid2[i];

	}
	delete [] grid1;
	delete [] grid2;
	cout<< "Object Terminated" << endl;

}
void Grid::settingWidth(int width)
{
	this->width = width;
}

int Grid::getWidth()
{
	return width;
}

void Grid::settingLength(int length)
{
	this->length = length;
}

int Grid::getLength()
{
	return length;
}


void Grid::duplicateGrid(char** gridA, char** gridB)
{
	for (int i = 0; i< length; ++i)
	{
		for(int j=0; j< width; ++j)
		{

			gridA[i][j] = gridB[i][j];
		}
	}
}

void Grid::printGrid(char** grid)
{
	for(int i=0; i< length; ++i)
	{
		for(int j =0; j< width; ++j)
		{
			cout << grid[i][j];
		}
			cout << endl;
		}
	}

	void Grid::populationGrid(char** grid, float density)
	{
		float newDensity = density * 100;
		int count = 0;
		double populated;

		for(int i=0; i< length; ++i)
		{
			for(int j=0; j< width; ++j)
			{
				populated = rand() % 100 +1;

				if(populated <= newDensity && count < newDensity)
				{ 
					grid[i][j] = 'X';
					count++;
				}
				else
					grid[i][j] = '-';
			}
		}
	}

	bool Grid::emptyGrid(char** grid, int length, int width)
	{
		bool isEmpty = true;
		for(int i= 0; i< length; ++i)
		{
			for (int j= 0; j < width; ++j)
			{
				if(grid[i][j] !='-') 
					isEmpty = false;
			}
		}

		return isEmpty;
	}

	bool Grid::steadyGrid(char** gridA, char** gridB)
	{
		bool isStable = true;
		for(int i = 0; i< length; ++i)
		{
			for (int j = 0; j< width; ++j)
			{
				if(gridA[i][j] !=gridB[i][j]) 
					isStable = false;
			
			}
		}	return isStable;

	}

	void Grid::askUser(int response)
	{
		Gol firstGol;
		if(response == 1)
		{
			cout<<" please tell me the map name:" <<endl;
			cin>> fileName;
			ifstream file (fileName);
			int lineCount = 0;
			if(file.is_open())
			{
				while(getline(file, line))
				{
					if(lineCount ==0)
					{
						length = atoi(line.c_str());
				lineCount++;
			continue;
		}
		if(lineCount == 1)
		{
			width = atoi(line.c_str());
			lineCount++;
			break;
		}
	}

	cout<< "length:" <<  length << endl;
	cout << "width :" << width << endl;

	grid1 = new char*[length];
	grid2 = new char*[length];
	for(int i=0; i < length; ++i)
	{
		grid1[i] = new char[width];
		grid2[i] = new char[width];

	}

	int rowNum = 0;
	while(getline(file, line))
	{
		cout << "line =" << line << endl;
		if(lineCount == 2)
		{
			for(int i = 0; i< width; ++i)
			{
				grid1[rowNum][i] = char(line[i]);
			}
			++rowNum;
		}
	}
}
}



else if(response == 2)
{
	cout << "please enter the number of desired number of rows (length), coloms (width) & desnity" << endl;
	cin >> width >> length >> density;

	grid1 = new char*[length];
	grid2 = new char*[length];
	for(int i= 0; i < length; ++i)
	{
		grid1[i] = new char[width];
		grid2[i] = new char[width];
	}
	populationGrid(grid1, density);
}

cout << "Please enter the desired mode to run simulation in: Please enter 1 for Class mode, 2 for Donut mode or 3 for Mirror mode" << endl;
cin >> choice;

switch(choice)
{
	case 1: //classic mode
	cout << "Lets begin Classic Mode" << endl;
	firstGol.displayOption();
	cin >> printChoice;
	if(printChoice ==1)
	{
		do
		{
			firstGol.classicMode(grid1, grid2, length, width);
			cout << "Generation : #" << generation << endl;
			++generation;
			printGrid(grid1);
			cout<<"****\n";
			if(emptyGrid(grid2, length, width) == true)
			{
				cout<< "worlds empty" <<endl;
				printGrid(grid2);
				cout<<"\n please press the enter button to exit the simulation." << endl;
				getchar();
				cin.get();
				halt = true;

			}

			if(steadyGrid(grid1, grid2) == true)
			{
				cout << "now stabalizing" << endl;
				printGrid(grid2);
				cout << "\n press enter to exit" << endl;
				getchar();
				cin.get();
				halt = true;
			}
			
			duplicateGrid(grid1, grid2);
		}
		while(emptyGrid(grid2, width, length)== false);
		break;
	}
	case 2:
cout << "now in doughbut mode!" << endl;
firstGol.displayOption();
cin >> printChoice;

	
	if(printChoice == 2)
	{
		do
		{
			firstGol.classicMode(grid1, grid2, length, width);
			cout << "generation: #" << generation << endl;
			++generation;
			printGrid(grid1);
			cout <<"*************\n";
			cout << " Please press enter to display the next generation" << endl;
			getchar();
			if(emptyGrid(grid2, length, width) == true)
			{
				cout << " This world is now empty!" << endl;
				printGrid(grid2);
				getchar();
				halt = true;
			}
			if(steadyGrid(grid1, grid2) == true)
			{
				cout << "Program now stabalized" << endl;
				printGrid(grid2);
				cout << "\n Please press enter to exit the program";
				getchar();
				halt = true;
			}
			duplicateGrid(grid1, grid2);
		}while (halt == false);
		break;
	}
	case 3:
cout <<"now in mirror mode!" << endl;
firstGol.displayOption();
cin >> printChoice;
	if(printChoice == 3)

		{
		string outputFile;

		cout << "Please enter the name of the file: " <<endl;
		cin >> outputFile;

		const char* fileOutput = outputFile.c_str();

		ofstream output (fileOutput, ios::out | ios::binary);
		if(output.is_open())
		{
			do
		{
		
			firstGol.classicMode(grid1, grid2, length, width);
			output<< "generation #" <<generation << endl;
			++generation;

			for(int i = 0; i < length; i++)
			{
				for(int j = 0; j < width; ++j)
				{
					output << grid1[i][j];
				}
				output << endl;
			}

				if(emptyGrid(grid2, length, width) == true)
				{
					output << "World now empty!" << endl;
					for(int i =0; i < length; ++i)
					{
					for(int j = 0; j < width; ++j)
					{
						output << grid2[i][j];
					}
					output << endl;
				}
				halt = true;
			}

			if(steadyGrid(grid1, grid2) == true)
			{
				output << " now stabalizing. " << endl;
				for (int i = 0; i < length; ++i)
				{ 
					for(int j = 0; j < width; ++j)
					{
						output << grid2[i][j];
					}
					output << endl;
				}
				halt = true;
			}
			
			duplicateGrid(grid1, grid2);
		}while(halt == false);
	



break;

}

}
}
}

				
