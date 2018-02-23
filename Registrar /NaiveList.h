#include "ListNode.h"
#include <iostream>


using namespace std;

template <class T>
class NaiveList
{
	private:

	ListNode<T> *front;
	ListNode<T> *back;
	unsigned int size;

	public:
		NaiveList();
		~NaiveList();
		void insertFront(T data);
		void insertBack(T data);
		void printList();

		T getFront();
		T getRear();

		T removeFirst();
		T removeBack();
		T find(T d);
		T deletePos(T pos);
		bool isEmpty();
		T peek();

};

template <class T>
NaiveList<T>::NaiveList()
{
	size = 0;
	front = NULL;
	back = NULL;
}

template <class T>
void NaiveList<T>::insertFront<T>(data)
{
	ListNode<T> *node = new ListNode<T>(data)

	if(size == 0)
	{
		back = node;
	}
	else
	{
		front->prev = node;
		node->next = front;
	}
	front = node;
	++size;
}
template <class T>
void NaiveList<T>::insertBack(T data)
{
	++size;
	ListNode<T> *node = new ListNode<T>(data)

	if(size == 0)
	{
		front = node;
	}
	else
	{
		back->next = node;
		node->prev = back;
	}
	back = node;
}
template <class T>
void NaiveList<T>::printList()
{
	ListNode<T> *curr = front; //have a pointer to the front that is keeping track 
	while(curr->next != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}

template <class T>
T NaiveList<T>::removeFirst()
{	
	ListNode<T> *temp = front; //pointing to front
	if(front->next == NULL) 
	{
		back = NULL; //empty list
	}
	else 
	{
		front->next->prev = NULL; //front's pointer coming from next node is set to null
	}
	front = front->next;//the next node becomes the first one
	T val = temp->data; //data is stored in a variable
	delete temp; //deletes the temp list node

	--size; //size of list decreases
	return val; //return the value of the node that was deleted which use to be the first one
}

template <class T>
T NaiveList<T>::removeBack()
{
	ListNode<T> *temp = back; //pointing to the back
	if(front->next == NULL)
	{
		back = NULL;
	}
	else
	{
		back->prev->next = NULL;
	}
	back = back->prev;
	T val = temp->data;
	delete temp;

	--size;
	return val;
}

template <class T>
T NaiveList<T>::find(T d)
{
	int idx = -1; // if you return negative it does not exist 
	ListNode<T> *curr = front;

	while(curr->next != NULL)
	{
		if(curr->data == d) //we found it 
		{
			idx = 1;
			break;
		}
		else//didnt find it, keep moving down the list
		{
			curr = curr->next;
		}
	}
	if(curr == NULL)
		idx = -1;
	return idx;
}

template <class T>
T NaiveList<T>::deletePos(T pos)
{
	int idx = 0;
	ListNode<T> *curr = front;
	ListNode<T> *prev = front;

	while(idx != pos) //loop until position is found. You are getting your pointers in the right position
	{
		prev = curr; //stay back
		curr = curr -> next;
		++idx; 
	}

	//found position, pointers are now in the correct location 
	prev->next = curr->next;
	curr->next->prev = prev;
	curr->next = NULL;
	curr->prev = NULL;
	T d = curr->data;
	delete curr;

	--size;
	return d;
}

template <class T>
bool NaiveList<T>::isEmpty()
{
	return size == 0;
}

template <class T>
int NaiveList<T>::getSize()
{
	return size;
}

template <class T>
T NaiveList<T>::peek()
{
	ListNode<T> *curr = front; //have a pointer to the front that is keeping track
	return curr->data; //return data of the current node
}




























