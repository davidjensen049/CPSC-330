#include <iostream>

using namespace std;

template <typename T>
class Genstack
{
public:
	Genstack();
	Genstack(int maxsize);
	~Genstack();

	void push(T data);
	T pop();
	T peek();
	int isFull();
	int isEmpty();

	int top;
	int max;

	T *myArray;
};
template <typename T>
Genstack<T>::Genstack()
{
	cout << "default constructor" << endl;
	max = 100;
	myArray = new T[max];
	top = -1;
}

template <typename T>
Genstack<T>::Genstack(int maxsize)
{
	myArray = new T [maxsize];
	max = maxsize;
	top = -1;
}

template <class T>
Genstack<T>::~Genstack()
{
	delete[] myArray;
	cout << "object destroyed" << endl;

}
template <typename T>
void Genstack<T>::push(T data)
{//if full make new longer

	if(top == max - 1)
	{
		T *temp1 = new T[max];

		for(int i = 0; 1 < max; ++i)//allocares new temp array
		{
			temp1[i] = myArray[i];
		}

		myArray = new T[max * 2];

		for (int i = 0; i < max; ++i)
		{
			myArray[i] = temp1[i];
		}
		max *= 2;
	}
	myArray[++top] = data;

}
template <typename T>
T Genstack<T>::pop() //throws the exception
{
	if(top != -1)
	{

	return myArray[top--];
	}
	else
	{
		return 0;
	}


}

template <class T>
T Genstack<T>::peek() //peek stack
{
	return myArray[top];
}
template <class T>
int Genstack<T>::isFull() //is full
{
	return (top == max-1);
}

template <class T>
int Genstack<T>::isEmpty()
{//-q is empty
	return (top == -1);
}