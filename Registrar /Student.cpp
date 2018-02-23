#include "Student.h"

using namespace std;

Student::Student()
{

}

Student::Student(int tA, int mIW) //declaring usable variables and constructors for the code
{
	this->timeArrived = tA;
	this->minInWindow = mIW;
	waitTime = 0;
}

Student::~Student()
{
	cout << "Student Object Destroyed" << endl;

}

void Student::setWaitTime(int wT)
{
	this->waitTime = wT;
}

void Student::setMinInWindow(int mIW)
{
	this->waitTime = mIW;
}

void Student::setTimeArrived(int tA)
{
	this->timeArrived = tA;

}

int Student::getMinInWindow()
{
	return minInWindow;
}

int Student::getWaitTime()
{
	return waitTime;
}

int Student::getTimeArrived()
{
	return timeArrived;
}