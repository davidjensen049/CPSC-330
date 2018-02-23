#include <iostream>

using namespace std;

class Gol
{
	private:


public:

	Gol();
	~Gol();


	void mirrorMode(char** tempGrid, char** grid, int width, int length);
	void donutMode(char** tempGrid, char** grid, int width, int length);
	void classicMode(char** tempGrid, char** grid, int width, int lenght);
	void displayOption();

};

