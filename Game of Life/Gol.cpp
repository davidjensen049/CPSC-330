#include "Gol.h"

Gol::Gol()
{

}

Gol::~Gol()
{
	cout << "Object is being destroyed" << endl;
}

void Gol::displayOption()
{
	cout << "Please enter '1' if you want a brief pause between generations." << endl;
	cout << "Please enter '2' if you to press to display next generation." << endl;
	cout << "Please enter '3' if you wish to output everything to a file." << endl;
}

void Gol::classicMode(char** grid, char** tempGrid, int length, int width)
{

	for(int i = 0; i < length; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			int count = 0; 
			if(i == 0 && j == 0){ //checks upper left corner
				if(grid[i+1][j+1] == 'X') ++count;
				if(grid[i][j+1] == 'X') ++count;
				if(grid[i+i][j] == 'X') ++count;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				continue;
			}
			else if(i == 0 && j == (width-1)) { //checks upper right corner
				if(grid[i+1][j-1] == 'X') ++count;
				if(grid[i][j-2] == 'X') ++count;
				if(grid[i+1][j-2] == 'X') ++count;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				continue;
			}

				else if(i == 0 && j != (width-1)){ // any location except corners
					if(grid[i][j+1] == 'X') ++count;
					if(grid[i][j-1] == 'X') ++count;
					if(grid[i+1][j+1] == 'X') ++count;
					if(grid[i+1][j-1] == 'X') ++count;
					if(grid[i+1][j] == 'X') ++count;
					if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5) tempGrid[i][j] = '-';
				continue;
			}

			else if(j == 0 && i != 0 && i != (length-1)){ //between corners first column
				if(grid[i+1][j] == 'X') ++count;
				if(grid[i-1][j] == 'X') ++count;
				if(grid[i+1][j+1] == 'X') ++count;
				if(grid[i-1][j+1] == 'X') ++count;
				if(grid [i][j+1] == 'X') ++count;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5) tempGrid[i][j] = '-';
				continue;
			}

			else if(j == 0 && i == (length-1)){ //left corner first column
				if(grid[i][j+1] == 'X') ++count;
				if(grid[i-1][j] == 'X') ++count;
				if(grid[i-1][j+1] == 'X') ++count;
				if(grid[i][j+1] == 'X') ++count;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				continue;
			}

			else if(j == (width-1) && i != 0 && i != (length-1)){ // Checks inbetween locations from the corners of the last column
				if(grid[i+1][j+1] == 'X') ++count;
				if(grid[i-1][j] == 'X') ++count;
				if(grid[i+1][j-1] == 'X') ++count;
				if(grid[i][j-1] == 'X') ++count;
				if(grid[i-1][j-1] == 'X') ++count;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5) tempGrid[i][j] = '-';
				continue;
			}

			else if(i == (length-1) && j != 0 && j!= (width-1)){ //checks between coloms of lower row
				if(grid[i][j+1] == 'X') ++count;
				if(grid[i][j-1] == 'X') ++count;
				if(grid[i-1][j+1] == 'X') ++count;
				if(grid[i-1][j] == 'X') ++count;
				if(grid[i-1][j-1] == 'X') ++count;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5) tempGrid[i][j] = '-';
				continue;	
			}

			else if(i == (length-1) && i == (width-1)){ //checks bottom right corner
				if(grid[i-1][j] == 'X') ++count;
				if(grid[i-1][j-1] == 'X') ++count;
				if(grid[i][j-1] == 'X') ++count;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				continue;
			}

			else { //all locations not in border
				if(grid[i][j-1] == 'X') ++count;
				if(grid[i-1][j-1] == 'X') ++count;
				if(grid[i+1][j-1] == 'X') ++count;
				if(grid[i-1][j] == 'X') ++count;
				if(grid[i+1][j] == 'X') ++count;
				if(grid[i-1][j+1] == 'X') ++count;
				if(grid[i+1][j+1] == 'X') ++count;
				if(grid[i][j+1] == 'X') ++count;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;
			}
		}
	}
}
	void Gol::donutMode(char** tempGrid, char** grid, int length, int width)
	{	
		for(int i = 0; i < length; ++i)
		{
			for(int j = 0; j < width; ++j)
			{
				int count = 0;

				if(i == 0 && j == 0)
					{ //checks upper left corner
				if(grid[i+i][j+1] == 'X') ++count;
				if(grid[length-1][j+1] == 'X') ++count;
				if(grid[i][j+1] == 'X') ++count;
				if(grid[i][width-1] == 'X') ++count;
				if(grid[length-1][j] == 'X') ++count;
				if(grid[i+1][width-1] == 'X') ++count;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = tempGrid[i][j];
				if(count == 3) tempGrid[i][j] =  'X';
				if(count == 4 || count == 5 || count == 6 || count == 7) tempGrid[i][j] = '-';
				continue;
			}
			else if (i == 0 && j == (width-1)) //upper right corner
				{
					if(grid[i+i][j-1] == 'X') ++count;
					if(grid[0][0] == 'X') ++count;
					if(grid[i][j-2] == 'X') ++count;
					if(grid[1][0] == 'X') ++count;
					if(grid[width-1][length-2] == 'X') ++count;
					if(grid[width-1][length-1] == 'X') ++count;
					if(count == 0 || count == 1) tempGrid[i][j] = '-';
					if(count == 2) tempGrid[i][j] = tempGrid[i][j];
					if(count == 3) tempGrid[i][j] =  'X';
					if(count == 4 || count == 5 || count == 6 || count == 7) tempGrid[i][j] = '-';
					continue;
				}

				else if( j == 0 && i ==(length-1)) //bottom left
				{
					if(grid[i][j+1] == 'X') ++count;
					if(grid[length-2][width-1] == 'X') ++count;
					if(grid[i-1][j] == 'X') ++count;
					if(grid[length-1][width-1] == 'X') ++count;
					if(grid[0][j+1] == 'X') ++count;
					if(grid[0][j] == 'X') ++count;
					if(count == 0 || count == 1) tempGrid[i][j] = '-';
					if(count == 2) tempGrid[i][j] = tempGrid[i][j];
					if(count == 3) tempGrid[i][j] =  'X';
					if(count == 4 || count == 5 || count == 6 || count == 7) tempGrid[i][j] = '-';
					continue;	
					}

					else if(i == (length-1) && i==(width-1)) //last location bottom right
					{
						if(grid[i-i][j] == 'X') ++count;
						if(grid[length-2][0] == 'X') ++count;
						if(grid[i][j+1] == 'X') ++count;
						if(grid[length-1][0] == 'X') ++count;
						if(grid[0][width-1] == 'X') ++count;
						if(grid[0][width-2] == 'X') ++count;
						if(count == 0 || count == 1) tempGrid[i][j] = '-';
					if(count == 2) tempGrid[i][j] = tempGrid[i][j];
					if(count == 3) tempGrid[i][j] =  'X';
					if(count == 4 || count == 5 || count == 6 || count == 7) tempGrid[i][j] = '-';
					continue;
				}

				else if(i == 0 && j != (width-1)) //any location except corner
				{
					if(grid[i][j+1] == 'X') ++count;
					if(grid[length-1][j-1] == 'X') ++count;
					if(grid[i+1][j+1] == 'X') ++count;
					if(grid[length-1][j] == 'X') ++count;
					if(grid[i+1][j] == 'X') ++count;
					if(grid[length-1][j+1] == 'X') ++count;
					if(grid[i][j-1] == 'X') ++count;
					if(grid[i+1][j-1] == 'X') ++count;
					if(count == 0 || count == 1) tempGrid[i][j] = '-';
					if(count == 2) tempGrid[i][j] = tempGrid[i][j];
					if(count == 3) tempGrid[i][j] =  'X';
					if(count == 4 || count == 5 || count == 6 || count == 7) tempGrid[i][j] = '-';
					continue;
				}

				else if(j == 0 && i != (length-1)) //first colomn between corners
				{
					if(grid[i+1][j+1] == 'X') ++count;
					if(grid[i-1][width-1] == 'X') ++count;
					if(grid[i+1][j+1] == 'X') ++count;
					if(grid[i][width-1] == 'X') ++count;
					if(grid[i][j+1] == 'X') ++count;
					if(grid[i+1][width-1] == 'X') ++count;
					if(grid[i-1][j+1] == 'X') ++count;
					if(grid[i-1][j] == 'X') ++count;
					if(count == 0 || count == 1) tempGrid[i][j] = '-';
					if(count == 2) tempGrid[i][j] = tempGrid[i][j];
					if(count == 3) tempGrid[i][j] =  'X';
					if(count == 4 || count == 5 || count == 6 || count == 7) tempGrid[i][j] = '-';
					continue;
				}
				else if(j == (width-1) && i != (length-1)) //check between corners last column
				{
					if(grid[i+1][j+1] == 'X') ++count;
					if(grid[i-1][0] == 'X') ++count;
					if(grid[i+1][j-1] == 'X') ++count;
					if(grid[i][0] == 'X') ++count;
					if(grid[i][j-1] == 'X') ++count;
					if(grid[i+1][0] == 'X') ++count;
					if(grid[i-1][j-1] =='X') ++count;
					if(grid[i-1][j-1] == 'X') ++count;
					if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;
			}

			else if(i == (length-1) && j != 0 && j!= (width-1)) //between locations of corners bottom
			{
				if(grid[i][j+1] == 'X') ++count;
					if(grid[0][j-1] == 'X') ++count;
					if(grid[i-1][j+1] == 'X') ++count;
					if(grid[0][j] == 'X') ++count;
					if(grid[i-1][j] == 'X') ++count;
					if(grid[i][j-1] == 'X') ++count;
					if(grid[i-1][j-1] =='X') ++count;
					if(grid[0][j+1] == 'X') ++count;
					if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;
				}
				else
				{ //checks locatinos not in border
				if(grid[i][j-1] == 'X') ++count;
				if(grid[i-1][j-1] == 'X') ++count;
				if(grid[i+1][j-1] == 'X') ++count;
				if(grid[i-1][j] == 'X') ++count;
				if(grid[i+1][j] == 'X') ++count;
				if(grid[i-1][j+1] == 'X') ++count;
				if(grid[i+1][j+1] == 'X') ++count;
				if(grid[i][j+1] == 'X') ++count;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;	
				}
				}
				}
				}	


	void Gol::mirrorMode(char** grid, char** tempGrid, int length, int width)
	{

	}		




				
















				