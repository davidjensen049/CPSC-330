#include "ListNode.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyList{
	private:
		ListNode<T> *front;
		ListNode<T> *back;
		unsigned int size;

	public:
		DoublyList();
		~DoublyList();
		void insertFront(T data);
		void insertBack(T data);
		void printList();

		int* toPointer();

		T getFront();
		T getRear();

		T removeFirst();
		T removeBack();
		T find(T d);
		void replace(T d);
		T deletePos(T pos);
		void deleteNode(T node);
		bool isEmpty();
		int getSize();
		T peek();
};

template <class T>
DoublyList<T>::DoublyList()
{
	size = 0;
	this->front = NULL;
	this->back = NULL;
}

template <class T>
DoublyList<T>::~DoublyList()
{
	
}

template <class T>
void DoublyList<T>::insertFront(T data)
{
	ListNode<T> *node = new ListNode<T>(data);//going to be making the checks if empty
	
	if(size == 0)
	{
		back = node;
										//only thing in the node so front and back are the same
	}
	else //if it is Not Empty
	{
						//going to enter something to the front 
		front->prev = node;
		node->next = front; //setting pointers equal to each other 
	}
	front = node;
	size++;
}

template <class T>
void DoublyList<T>::insertBack(T data) // we are cheking to see if the lists epty and ->data
{
	ListNode<T> *node = new ListNode<T>(data);
	
	if(size == 0)
	{

		this->front = node;
	}
	else
	{
		this->back->next = node;
		node->prev = this->back;
	}
	this->back = node;
	this->size++;
}

template <class T>
void DoublyList<T>::printList() // we are checking with point to see if the front is keeping track of whats going on
{
	ListNode<T> *curr = this->front;  
	cout << "Size: " << size << endl;
	if (size == 0){
		cout <<"empty"<<endl;

	}
	else{
		
		if(curr->next == NULL)
			cout << "IT's NULL " << endl;
		else
			cout  << "it is NOT!!!!!!! null " << endl;
		while(curr != NULL)
	 	{
			if(curr->data != -1)
			{
				cout << curr->data<< endl;
			}

			curr = curr->next;
		}
		cout << "at the end of print list" << endl;
	}
}

template <class T>
int* DoublyList<T>::toPointer()//this is going to create an array pointer from the list ID's and also keep track whats going on in the front
{
	int* temp = new int(size);
	int count = 0;
	ListNode<T> *curr = front; 
	while(curr != NULL)
	{
		if(curr->data != -1)
		{
			temp[count] = curr->data;
			++count;
		}
		curr = curr->next;
		
	}

	return temp;
	delete temp;
}

template <class T>
T DoublyList<T>::removeFirst()
{	
	ListNode<T> *temp = front; //pointing to front, 
	if(front->next == NULL) 
	{
		back = NULL; 
	}
	else 
	{
		front->next->prev = NULL; //front's pointer coming from next node is set to null
	}
	front = front->next;
	T val = temp->data; 
	delete temp; //deletes the temp list node

	--size; //size of list decreases
	return val; //return the value of the node that was deleted which use to be the first one
}

template <class T>
T DoublyList<T>::removeBack()
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
T DoublyList<T> :: getFront()
{
	return front->data;
}

template <class T>
T DoublyList<T>::find(T d)
{
	int idx = -1; // if you return negative it does not exist 
	ListNode<T> *curr = front;
//	cout << "Curr->data: " << curr->data << endl; 
	if(curr->data == d)//if the list only has one node and that is the node we are looking for
	{
		idx = 1;
	}
//	cout << "after first if statement" << endl;
	while(curr->next != NULL)
	{
		if(curr->data == d) //we found it 
		{
			idx = 1;
			break;
		}
		else//didnt find it, keep moving down the list
		{
//			cout << "Inside Else Curr->data: " << curr->data << endl; 
			curr = curr->next;
		}

	}
//	cout << "Before last if statement Curr->data: " << curr->data << endl; 
	if(curr->data == d) //found it
		idx = 1;
	if(curr == NULL)
		idx = -1;
//	cout << "IDX = " << idx << endl;
	return idx;
}

template <class T>
void DoublyList<T>::replace(T d)
{
	int idx = -1; // if you return negative it does not exist 
	ListNode<T> *curr = front;

	if(curr->data == d)//if the list only has one node and that is the node we are looking for
	{
		curr->data = -1; // decrease 1
		
	}

	while(curr->next != NULL)
	{
		if(curr->data == d) //hopefully we found it 
		{
			curr->data = -1;
			
			break;
		}
		else//if we didnt find it, go and keep moving down the list
		{
			curr = curr->next;
		}
	}
	
}

template <class T>
T DoublyList<T>::deletePos(T pos)
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

template <class T> //this is going to delete a node and see if there is one
void DoublyList<T>::deleteNode(T node)
{
	
	ListNode<T> *curr = front;
	ListNode<T> *prev = front;
	if(curr->data == node && curr->next == NULL)//has one node
	{
		removeFirst();
		
	}

	else if(curr->data == node && curr->next != NULL) // has 2 nodes
	{
		prev->next = curr->next;
		curr->next->prev = prev;
		
		curr->next = NULL;
		curr->prev = NULL;

		delete curr;
		--size;
	}
	else //if it has 3 or more nodes
	{
		while(curr->data != node) //loop until position is found. You are getting your pointers in the right position
		{
	
			prev = curr; //stay back
			curr = curr -> next;
			if(curr->data == node)
				break;
			//++idx; 
		}
	
		prev->next = curr->next;
		curr->next->prev = prev;
		curr->next = NULL;
		curr->prev = NULL;
	
		delete curr;

		--size;
	}
	
}



template <class T>
bool DoublyList<T>::isEmpty()
{
	return size == 0;
}

template <class T>
int DoublyList<T>::getSize()
{
	return size;
}

template <class T>
T DoublyList<T>::peek()
{
	ListNode<T> *curr = front; //have a pointer to the front that is keeping track
	return curr->data; //return data of the current node
}
