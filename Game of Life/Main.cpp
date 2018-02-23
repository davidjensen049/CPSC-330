#include "Grid.h"

int main(int argc, char** argv)
{
	Grid g;
	Grid tempGrid;
	int response;
	bool errorOccured = false;

	do
{

cout << "please enter '1' if you wish to provide a file map or press '2'\n if you desire to generate a random map" <<endl;
cin >> response;
errorOccured = response < 1 || response > 2 || cin.fail();
if(errorOccured)
{
	cout << " Error: Invalid Input: " <<endl;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	errorOccured = true;
}
}while(errorOccured);

g.askUser(response);

return 0;

}
