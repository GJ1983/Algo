#include<iostream>
#include<atomic>

struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
private:
	static Node *Head;
public:
	void InsertAtBeg(int data);
	void InsertAtLast(int data);
	void TraverseList();
        void ReverseList();

};

struct BNode
{
	int data;
	BNode *left, *right;
};

class binary_tree
{
public:
	void insert(BNode *root, int key);
	void inorder(BNode *root);
        BNode * GetRoot();
private:
	static BNode *Root;
};

int main()
{
        LinkedList ll;
        ll.InsertAtLast(10);
        ll.InsertAtLast(20);
        ll.InsertAtLast(30);
        ll.InsertAtLast(40);
        ll.InsertAtLast(50);
        ll.InsertAtBeg(98);
        ll.TraverseList();
        ll.ReverseList();
        std::cout<<" Linked list after reversing is : "<<std::endl;
        ll.TraverseList();

	std::cout<< " Binary tree starts now: "<<std::endl;
	std::cout<<"  ======================: "<<std::endl;
	std::cout<<"  ======================: "<<std::endl;
	std::cout<<"  ======================: "<<std::endl;
	std::cout<<"  ======================: "<<std::endl;

	//Binary Tree
	binary_tree bt;
	bt.insert(bt.GetRoot(),50);
	bt.insert(bt.GetRoot(),10);
	bt.insert(bt.GetRoot(),60);
	bt.insert(bt.GetRoot(),20);
	bt.insert(bt.GetRoot(),70);
	bt.inorder(bt.GetRoot());

	return 0;
}

// Hash Table
const int TABLE_SIZE = 128;

class HashEntry
{
private:
	int key;
	int value;
public:
	HashEntry(int key, int value)
	{
		this->key = key;
		this->value = value;
	}
	int getKey()
	{
		return key;
	}

	int getValue()
	{
		return value;
	}
};

class HashMap
{
private:
	HashEntry **table;
public:
	HashMap()
	{
		table = new HashEntry*[TABLE_SIZE];
		for(int i = 0 ; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	int get(int key)
	{
		int hash = key%TABLE_SIZE ;
		while(table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash+1) % TABLE_SIZE ;

		if(table[hash] == NULL)
			return -1;
		else
			return table[hash]->getValue();
	}
};


//Linked list implementation

Node *LinkedList::Head = NULL;

void LinkedList::InsertAtBeg(int data)
{
	Node *newnode = new Node;
	newnode->data = data;
	newnode->next = Head;
	Head = newnode;
}

void LinkedList::InsertAtLast(int data)
{
        if(Head == NULL)
        {
		InsertAtBeg(data);
		return; 
        }
	Node *temp = Head ;
	while(temp->next != NULL)
		temp = temp->next;

	Node *newnode = new Node;
	newnode->data = data;
	newnode->next = NULL;
	temp->next = newnode;
}

void LinkedList::TraverseList()
{
	Node *temp = Head;
	while(temp != NULL)
	{
		std::cout<<temp->data<<std::endl;
		temp = temp->next;
	}
}

void LinkedList::ReverseList()
{
	Node *prev = NULL;
	Node *curr = Head;
	Node *nex = NULL;
	while(curr != NULL)
	{
		nex = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nex;
	}
	Head = prev;
}

BNode *binary_tree::Root = NULL;

void binary_tree::insert(BNode *root, int key)
{
	if(root == NULL)
	{
		BNode *node = new BNode;
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
			BNode *newnode = new BNode;
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
			BNode *newnode = new BNode;
			newnode->data = key;
			newnode->left = NULL;
			newnode->right = NULL;
			root->right = newnode;
		}
                else 
			insert(root->right,key);
}

BNode * binary_tree::GetRoot()
{
	return Root;
}

void binary_tree::inorder(BNode *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		std::cout<<root->data<<std::endl;
		inorder(root->right);
	}
}
