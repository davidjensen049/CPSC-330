#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Grid
{
private:
	string fileName, line;
	int choice, printChoice;
	int width, length;
	int generation;
	float density;
	char** grid1;
	char** grid2;
	bool halt;

public:
	Grid();
	~Grid();

	int getWidth();
	int getLength();
	void settingLength(int length);
	void settingWidth(int width);

	bool steadyGrid(char** gridA, char** gridB);
	bool emptyGrid(char** grid, int length, int width);
	void readFiles(char* fileName);
	void askUser(int response);
	void duplicateGrid(char** gridA, char** gridB);
	void printGrid(char** grid);
	void populationGrid(char** grid, float density);

};
	