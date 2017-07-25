#include<iostream>

struct Node
{
	int data;
	Node *left, *right;
};

class binary_tree
{
public:
	void insert(Node *root, int key);
	void inorder(Node *root);
        Node * GetRoot();
private:
	static Node *Root;
};

Node *binary_tree::Root = NULL;

void binary_tree::insert(Node *root, int key)
{
	if(root == NULL)
	{
		Node *node = new Node;
		node->data = key;
		node->left = NULL;
		node->right = NULL;
                if(Root == NULL)
			Root = node;
	}
	else if( root->data > key)
	{
		if(root->left == NULL)
		{
			Node *newnode = new Node;
			newnode->data = key;
			newnode->left = NULL;
			newnode->right = NULL;
			root->left = newnode;
		}
                else
			insert(root->left,key);
	}
	else
		if(root->right == NULL)
		{
			Node *newnode = new Node;
			newnode->data = key;
			newnode->left = NULL;
			newnode->right = NULL;
			root->right = newnode;
		}
                else 
			insert(root->right,key);
}

Node * binary_tree::GetRoot()
{
	return Root;
}

void binary_tree::inorder(Node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		std::cout<<root->data<<std::endl;
		inorder(root->right);
	}
}

int main()
{
	binary_tree bt;
	bt.insert(bt.GetRoot(),50);
	bt.insert(bt.GetRoot(),10);
	bt.insert(bt.GetRoot(),60);
	bt.insert(bt.GetRoot(),20);
	bt.insert(bt.GetRoot(),70);
	bt.inorder(bt.GetRoot());
	return 0;
}
