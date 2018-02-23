#include <iostream>
#include "TreeNode.h"
#include "Student.h"
#include <fstream>

using namespace std;

template <class A>
class BST

{
private:
	TreeNode<A>* root;
	

public:
	int size;
	A* arr;
	BST();
	virtual ~BST();

	void fileToArray(string fileName);
	void writeToFile(string fileName);
	void printStudents(BST<A>* masterStudent);
	void postOrder(A* n);
	void preOrder(A* n);
	void inOrder(TreeNode<A>* n);
	void insert(A value);
	void changeAdvisor(int key, int newAdvisorID);
	void addIDtoList(int facultyID, int studentID);

	int convertToArray(TreeNode<A>* n, int i);
	int getSize();

	A getValue(int key);
	A* getMin(); //leftmost
	A* getMax();//rightmost
	TreeNode<A>* getSuccessor(TreeNode<A>* d); //helper function dleted mthod
	TreeNode<A>* getRoot();

	bool isEmpty();
	bool deleteNode(int key); //this is our find function
	bool contains(int value);
	};

template <class A>
BST<A> :: BST()
{
	root = NULL;
	size = 0;
}

template <class A>
void BST<A> :: inOrder(TreeNode<A>* n) //prints a-i
{
	if(n != NULL)
	{
		inOrder(n->left);
		n->print();
		inOrder(n->right);
	}
}

template <class A> //delete and iterate
BST<A> :: ~BST()
{

}

template <class A>
void BST<A> :: preOrder(A* n)
{
	if(n != NULL)
	{
		cout << n->key << endl;
	postOrder(n->left);
	postOrder(n->right);
}
}
template <class A>
void BST<A> :: postOrder(A* n) //prints diff order
{
	if(n != NULL)
	{
		postOrder(n->right);
		postOrder(n->left);
		cout << n->key << endl;
	}
}
	template <class A>
bool BST<A>::isEmpty()
{
	if(root == NULL)

		return true;
	else
		return false;
}

template <class A>
A* BST<A> :: getMin()
{
	A current = root;
	if(root == NULL)
	{
		return NULL;
	}
	while(current->left != NULL)
	{
		current = current->right;
	}
	return current;
}
template <class A>
A* BST<A> :: getMax()
{
	A current = root;

	if(root == NULL)
	{
		return NULL;
	}
	while(current->right != NULL)
	{
		current = current->right;
	}
	return current;
}

	template <class A>
void BST<A>::insert(A value) //recursive
	{
		
		TreeNode<A>* node = new TreeNode<A>(value);
		if (root == NULL) //empty tree
		{
			root = node;
		}
		else
		{
			TreeNode<A> *curr = root;
			TreeNode<A> *parent; //start at root

			while(true)
			{
				parent = curr;
			
			if(node->key < curr->key)
			{
				curr = curr->left;//left

				if(curr == NULL)
				{
					parent->left = node;
					break;
				}
			}
		else

		{ //right
			curr = curr->right;

			if(curr == NULL)
			{
				parent->right = node;
				break;
			}
		}
	}
}
++size;
}
template <class A>
void BST<A>::changeAdvisor(int newAdvisorID, int value)
{
	TreeNode<A>* curr = root;
	while(curr->key != value)
	{
		if(value < curr->key)
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}
		if(curr == NULL)
		{
			cout << "what you are looking for is NULL!" <<endl;
		}
	}
	curr->myObject.setAdvisorID(newAdvisorID);
}
//return curr->obejct
template <class A>
bool BST<A> :: contains(int value)
{
	if(root == NULL)
	{
		return false;
		cout << "inside NULL" << endl;
	}
	else
	{

	TreeNode<A> *curr = root;

	while(curr->key != value)
	{
		if(value < curr->key)
		{
			curr = curr->left;

		}
		else
		{
			curr = curr->right;
		}
		if (curr == NULL)
		{
			return false;
		}
	}
	return true;
}
}

template <class A>
A BST<A>::getValue(int value)
{
		TreeNode<A> *curr = root;

		while(curr->key != value)
		{
			if(value < curr->key)
			{
				curr = curr->left;
			}
			else
			{
				curr = curr->right;
			}
			if(curr == NULL)
			{
				cout << "in NULL" << endl;
			}
		}
		return curr->myObject;
}
template <class A>
TreeNode<A>* BST<A>::getRoot()
{
	return root;
}
template <class A> 
TreeNode<A>* BST<A>::getSuccessor(TreeNode<A> *d) //node to delete
{
	TreeNode<A>* sp = d; //sucdcesor parents
	TreeNode<A>* successor = d;
	TreeNode<A>* current = d->right;

	while (current != NULL)
	{
		sp = successor;
		successor = current;
		current = current->left;
	}
	if(successor != d->right)
	{
		sp->left = successor->right;
		successor->right = d->right;
	}
	return successor;
}
template <class A>
bool BST<A> :: deleteNode(int key){ //delet4e node
	if (root == NULL){
		return false;
	}
	TreeNode<A>* parent = root;
	TreeNode<A>* current = NULL;//start at root
	bool isLeft = true;

	while (current->key != key){
		parent = current;

		if (key < current->key){
			isLeft = true;
		current = current->left;// go left
	}
	else{
		isLeft = false;
		current = current->right;
	} //right

	if (current == NULL)
	
		return false;
	}


if(current->left == NULL && current->right == NULL) //leaf node no children
{
	if (current == root)
	{
		root = NULL;
	}
	else if (isLeft)
	{
		parent->left = NULL;
	}
	else
	{
		parent->right = NULL;
	}
}
else if (current->right == NULL) //no right chid
{
	cout <<"\tD" << endl;
	if (current == root)
	{
		root = current->left;
	}
	else if(isLeft)
	{
		parent->left = current->left;
	}
	else
	{
		parent->right = current->left;
	}
}
else if (current->left == NULL) //null left child
{
	cout <<"\tE" << endl;
	if (current == root)
	{
		root = current->right;
	}
	else 
	{
		parent->right = current->right;
	}
} //two kids
else
{
	TreeNode<A> *successor = getSuccessor(current);
	cout <<"\tF" << endl;
	if (current == root)
	{
		root = successor;
	}
	else if(isLeft)
	{
		parent->left = successor;
	}
	else
	{
		parent->right = successor;

	}
	successor->left = current->left;
}

--size;
return true; 
}
 template <class A>
void BST<A>::addIDtoList(int facultyID, int studentID)
{
	TreeNode<A>* curr = getRoot();
	while(curr->key != facultyID)
	{
		if(facultyID < curr->key)
			curr = curr->left;
		else
			curr = curr->right;
		if(curr == NULL)
			return;
	}
	curr->myObject.adviseesList.insertBack(studentID);
	cout << "Please insert an advisee" << endl;
	curr->myObject.adviseesList.printList();
}

template<class A>
void BST<A>::fileToArray(string fileName)
{
	string line;
	ifstream myFile(fileName);
	if(myFile.is_open())
	{
		while(getline(myFile, line))
		{
			int startingpoint = 0;
			size_t found = line.find(",");
			string name = line.substr(0,found);
			startingpoint = found;

			cout << "Name: " << name << endl;
			exit(0);
		}
		myFile.close();
	}
	else 
		cout << "Was not able to open the file, sorry" << endl;
}


template <class A>
int BST<A>::convertToArray(TreeNode<A>* n, int i)
{
	if(n == NULL)
		return i;
	arr[i] = n->myObject;
	++i;
	if(n->left != NULL)
		i = convertToArray(n->left, i);
	if(n->right != NULL)
		i = convertToArray(n->right, i);
	return i;
}

template <class A>
void BST<A>::writeToFile(string fileName)
{
	arr = new A[size];
	convertToArray(root, 0);
	ofstream myFile(fileName);
	if(myFile.is_open())
	{
		for(int i=0; i < size; ++i)
		{
			myFile << arr[i].printStringObject() << endl;
		}
		myFile.close();
	}
}









