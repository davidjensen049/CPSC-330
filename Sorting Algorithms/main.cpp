/*

David Jensen 227-3734 


Data Strucutres Section 1

12-15-2017

Assignment 6 - Sorting 


*/
#include <time.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

template <class T>
void print(T *myArray, int length);

void quickSort(double *arr, int low, int high);
int partition(double *arr, int low, int high);
void swap(double* a, double* b);

void mergeSort(double *a, int l, int r);
void merge(double *a, int l, int m, int r);

double fRand(double fMin, double fMax);
void insertionSort(double* arr);

string fileName, line;
clock_t sTime;
double seconds;
int size;
double *myArray;
time_t after;
time_t now;
long lineCount = 0, arrayCount = -1;

int main(int argc, char** argv)
{
	if(argc > 1)
	{
		fileName = argv[1];
	}

	ofstream bigFile("bigFile.txt"); // this is going to generate 100000 numbers for a sample file to see the run time of the code
	if(bigFile.is_open())
	{
		bigFile << "100000" << endl;
		for(int i = 0; i < 100000; i++)
		{
			double temp = fRand(1,100);
			bigFile << temp << endl;
		}
		bigFile.close();
	}
	ifstream myFile(fileName);

	if(myFile.is_open())
	{
		while(getline(myFile, line))
		{
			++lineCount;
			if(lineCount == 1)
			{
				size =stoi(line);
				myArray = new double[size];
				cout << "Size: " << size << endl;
			}
			else
			{
				++arrayCount;
				double num = stod(line);
				myArray[arrayCount] = num;
			}
		}
		myFile.close();
	} //these are going to cop rhe array for the 3 copys we need
	double *myThirdArray = myArray;
	double *mySecondArray = myArray;


cout << "InsertionSort" << endl;
sTime = clock();
cout << "This is the time that the sorting was started: " << sTime << endl;
insertionSort(myArray);
clock_t eTime = clock();
cout << "This is the time that the sorting has ended: " << eTime << endl;
double total = difftime(eTime, sTime);
cout << "The total combined time that was used for both functions was: " << total << endl << endl;

cout << "QuickSort" << endl;
clock_t startingTime = clock();
cout << "This is the time the sorting started: " << startingTime << endl;
quickSort(mySecondArray, 0, size-1);
clock_t endingTime = clock();
cout << "The time that the sorting ended is: " << endingTime << endl;
double overall = difftime(endingTime, startingTime);
cout << "The total time that was used to run both these functions was: " << overall << endl << endl;

cout << "MergeSort" << endl;
clock_t startTime = clock();
cout << "Time the sorting has started is: " << startTime << endl;
mergeSort(myThirdArray, 0, size -1);
clock_t endTime = clock();
cout << "The time the sorting finished was : " << endTime << endl;
double totalTime = difftime(endTime, startTime);
cout << "The total time used to run both of these funcitons is :" << totalTime << endl << endl;

return 0;
}


// each of the previous commands is what outputs us what we need and determines the runtimes. 
//I'm guessing my segfault im getting is with in the second function here above


void swap(double* a, double* b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(double* arr)
{
	for(int j = 1; j < 10; ++j)
	{
		double temp = arr[j];
		int k = j;
		while(k > 0 && arr[k-1] >= temp)
		{
			arr[k] = arr[k-1];
			--k;
		}
		arr[k] = temp;
	}
}

template <class T>
void print(T *myArray, int length)
{
	int count = 0;
	for(int i = 0; i < length; ++i)
	{
		cout <<setw(5) << myArray[i] << " ";
		++count;
		if(count % 10 == 0)
			cout << endl;
	}
}


int partition(double *arr, int low, int high)
{
	int pivot = arr[high];
	int i = (low -1);

	for (int j = low; j <= high -1; ++j)
	{
		if (arr[j] <= pivot)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
			swap(&arr[i], &arr[high]);
			return (i + 1);
		}
	
	void quickSort(double *arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, pi+1, high);
		quickSort(arr, low, pi -1);
	}
}

void mergeSort(double *a, int l, int r) 
{
	if ( l < r)
	{
		int m = l+(r-l)/2;
		mergeSort(a, m+1, r);
		mergeSort(a, l, m);

		merge(a, l, m, r);
	}
}

void merge(double *a, int l, int m, int r) //this is going to merge the 2 subarras as well as first and second
{
	int i, j, k;
	int n1 = m -l +1;
	int n2 = r - m;

double L[n1], R[n2]; // this is going to create a temp arra

for(i = 0; i < n1; ++i) //this is going to copy the data
L[i] = a[l + i];
for(j = 0; j < n2; ++j)
R[j] = a[m +1 + j];

k =l;
j = 0;//thse functions are going to inital the index of all 3 arras
i = 0;
while (i < n1 && j < n2)
{
	if (L[i] <= R[j])
	{
		a[k] = L[i]; 
		++i;
	}
	else
	{
		a[k] = R[j];
		++i;
	}
	++k;
}

while (i < n1) //coping the remainder
{
	a[k] = L[i];
	++i;
	++k;
}

}



	double fRand(double fMin, double fMax)
	{
		double f = (double)rand() / RAND_MAX;
		return fMin + f * (fMax - fMin);
	}
