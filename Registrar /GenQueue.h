#include "NaiveList.h"
#include <iostream>

using namespace std;

template <class T>
class GenQueue
{
	private :
		NaiveList<T> doublyList;
	public: 
		GenQueue();
		~GenQueue();

		void insert(T data); //enqueue
		T remove(); //dequeue
		T peek();

		int getSize();
		//int isFull();
		bool isEmpty();
	};

template <class T>
GenQueue<T>::GenQueue()
{

}

template <class T>
GenQueue<T>::~GenQueue()
{
	cout << "Object Destroyed" << endl;
}

template <class T> //setting the constructors and variables, adding peek possibilities
void GenQueue<T>::insert(T data)
{
	doublyList.insertBack(data);
}

template <class T>
T GenQueue<T>::remove()
{
	return doublyList.removeFirst();
}

template <class T>
T GenQueue<T>::peek()
{
	return doublyList.peek();
}

template <class T>
bool GenQueue<T>::isEmpty()
{
	return doublyList.isEmpty();
}

template <class T>
int GenQueue<T>::getSize()
{
	return doublyList.getSize();
}