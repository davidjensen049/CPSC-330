#include <iostream>

class Student
{
	private:
		int minInWindow;
		int waitTime;
		int timeArrived;

	public:
		Student();
		Student(int tA, int mIW);
		~Student();

		void setMinInWindow(int mIW);
		void setWaitTime(int wT);
		void setTimeArrived(int tA);
	

		int getMinInWindow();
		int getWaitTime();
		int getTimeArrived();
	};


