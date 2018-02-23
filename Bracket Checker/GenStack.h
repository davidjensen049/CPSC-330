#include <iostream>

using namespace std;

template <class T>//class template
class GenStack
{
	public: //variables
		
		GenStack(int maxSize);
		~GenStack();
		
		void push(T data);
		T pop();
		T peek();
		T opposite();
		T emptyOpposite(T data);
		bool isValidInput(char& input, string prompt, string errorMesasge);
		
		int isFull();
		int isEmpty();
		int getSize();

		
		int top;
		int max;
		int size;
		T *myArray;
};


template <class T>
GenStack<T>::GenStack(int maxSize)
{
	myArray = new char[maxSize]; //allocating new array
	top = -1;
}

template <class T>
GenStack<T>::~GenStack()
{
	cout << "Object Destroyed" << endl;
	delete[] myArray; //deleting object
}

template <class T>
void GenStack<T>::push(T data) 
{
	// IF FULL, DOUBLE SIZE
	if (isFull() == 1) //if full, make larger array
	{
		T* tempArray = new T[max];
		memcpy(tempArray, myArray, max * sizeof(int));
		max *= 2;

		delete [] myArray; //deallocate memory
		myArray = tempArray;
	}
	else
		myArray[++top] = data;
}

template <class T>
T GenStack<T>::pop()
{
	try{
	if (isEmpty() ==1) //throws the exception
		throw 0;
	else
		return myArray[top--];
	}
	catch(int e)
	{
		cout << "Excpetion has been thrown: Size of the stack currently is:" << e << endl;
		exit(0);
}
}


template <class T>
T GenStack<T>::peek()
{
	if(getSize() == 0)
	{
		cout << "The stack is now empty, nothing to use the peek fuction for"  << endl;
		exit(0);
	}
	return myArray[top];
}

template <class T>
T GenStack<T>::opposite() //returns opposite
{
	T temp = peek();
	T result;
	if(temp == '(')
		result = ')';
	else if(temp == ')')
		result = '(';
	else if(temp == '[')
		result = ']';
	else if(temp == ']')
		result = '[';
	else if(temp == '{')
		result = '}';
	else if(temp == '}')
		result = '{';
	return result;
}
template <class T>
T GenStack<T>::emptyOpposite(T data) //if no initial or open, return the correct
{
	T expected;
	if(data == ']')
		expected = '[';
	else if(data == '}')
		expected = '{';
	else if(data == ')')
		expected = '(';
	return expected;
}

template <class T>
int GenStack<T>::getSize()
{
	return top + 1;
}

template <class T>
int GenStack<T>::isFull()
{
	return (top == max-1);
}

template <class T>
int GenStack<T>::isEmpty()
{
	return (top == -1);

}
