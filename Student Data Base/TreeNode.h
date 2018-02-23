#include <iostream>
#include "Person.h"


template <class A>
class TreeNode

{
	public:
		TreeNode();
		TreeNode(A key);

		virtual ~TreeNode();

		A myObject;
		int key;

		void print();
		string printString();
		
		TreeNode *right;
		TreeNode *left;
	};

template<class A>
	TreeNode<A> :: TreeNode()
	{
		left = NULL;
		right = NULL;
	}
		template<class A>
	TreeNode<A> :: TreeNode(A k)
	{
		left = NULL;
		right = NULL;
		key = k.getID();
		myObject = k;
	}

	template <class A>
	TreeNode<A>::~TreeNode()
	{
		cout << "TreeNode Destroyed" << endl;
	}

	template <class A>
	void TreeNode<A>::print()
	{
		myObject.printObject();
	}

	template <class A>
	string TreeNode<A>::printString()
	{
		return myObject.printStringObject();
	}