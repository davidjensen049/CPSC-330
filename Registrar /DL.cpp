
class TreeNode 

{
	public:
		TreeNode();
		TreeNode(int key);
		virtual ~TreeNode();


		int key;
		TreeNode *left;
		TreeNode *right;
};

TreeNode::TreeNode()
{
	left = NULL;
	right = NULL;
	//decide what to do with K and D
}

TreeNode::TreeNode(int k)
{
	left = NULL;
	right = NULL;
	key = k;
}

TreeNode::~TreeNode()
{
	//build something
}

class BST
{
public:
	BST();
	virutal ~BST();
	void isnter(int k);
	bool contains(int value);
	bool isempty();
	int getMin();
	int getMax();
	bool deleteNode(int key);
	TreeNode* getSuccessor(TreeNode *d);
	void printTree(TreeNode *node);

private:
	TreeNode *root;

};

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	//iterate and delete
	// more character
}

TreeNode* BST::getMin()
{
	TreeNode *current = root; //start at root

	if(root == NULL)
		return NULL;


	while(current->left != NULL)
	{
		current = current->left;
	}

	return current;
}

TreeNode* BST::getMax()
{
	TreeNode *current = root; //start at root

	if(root == NULL)
		return NULL;


	while(current->right != NULL)
	{
		current = current->right;
	}

	return current;
}

void BST::insert(int value)
{
	TreeNode *newNode = new TreeNode(value);

	if(root == NULL)
	{
		root = newNode;
	}
	else //not and empty tree
	{
		TreeNode *current = rootl
		tree *parent; //empty node

		while(true)
		{
			parent = current;
			if(value < current->key) //go left
			{
				current = current->left;

				if(current == NULL)
				{
					parent->left = newNode;
					break;
				}
			}
			else //go right
			{
				current = current->right;
				if(current == NULL)
				{
					parent->right = newNode;
					break;
				}
			}
		}
	}
}

bool BST::contains(int value_
{
	if(root == NULL)
		return false;
	else
	{
		TreeNode *current = root;
		while(current->key != value)
		{
			if(value < current->key)
				current = current->left;
			else
				current = current->right;

			if(current = NULL)
				return false;
		}
	}

	return true;
}

bool BST::deleteNode(int k)
{
	if(root == NULL)
		return false;

	TreeNode *current = root;
	TreeNode *parent = root;
	bool isLeft = true;

	while(current->key != k)
	{
		parent = current;

		if(k < current-> key)
		{
			isLeft = true;
			current = current->right;
		}
		else
		{
			isLeft = false;
			current = current->right;
		}
		if(current == NULL)
			return false;
		}

		if(current->left == NULL && current-> == NULL) //its leafe node
		{
			if(current  == root)
				root == NULL;
			else if(isLeft)
			{
				parent->left = NULL;
			}
				else parent->right = NULL;
			}
			else if(current->right == NULL)//node has one child, not the right
			{
				if(current == root)
				{
					root = current->left;
				}
				else if(isLeft)
				{
					parent->left = current;

				}
				else
				{
					parent->right = current->left;
				}
			}
			else if(current->left == NULL)
			{
				if(current== root)
				{
					root = current->right;
				}
				else if(isLeft)
				{
					parent->left = current->right;
				}
				else
				{
					parent->right = current->right;
				}
			}
			else //if it has 2 children, we cry
			{

				TreeNode *sucessor = getSuccessor(current);

				if(current == root)
					root = sucessor;
				else if(isLeft)
				{
					parent->left = sucessor;

				}
				else
					parent->right = sucessor;

				sucessor->left = current->left;
			}
			return true;
		}
TreeNode* BST::getSuccessor(TreeNode *d) //represents the node we are going to delete
{
	TreeNode *sp =d;
	TreeNode *sucessor = d;
	TreeNode * current = d-> right;

	while(current !=NULL)
	{
		sp = sucessor;
		sucessor = current;
		current->left;
	}
	if(sucessor != d->right)
	{
		sp->left = sucessor->right;
		successor->right = d->right;
	}

	return successor;
}
		
























