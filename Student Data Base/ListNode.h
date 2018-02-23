#include <iostream>

using namespace std;

template <class T>
class ListNode
{

	public:
		T data;
		ListNode *prev;
		ListNode *next;

		ListNode();
		ListNode(T d);
		~ListNode();
	};
	template <class T>
	ListNode<T>::ListNode()
	{

	}
template <class T>
	ListNode<T>::ListNode(T d)
	{
		
			data = d;
			prev = NULL;
			next = NULL;
		}

	template <class T>
		ListNode<T>::~ListNode()
		{
			if(next != NULL)
			{

			next = NULL;
			prev = NULL;

			delete next;
			delete prev;

		}
		cout << "Object Destroyed" <<endl;
	}
