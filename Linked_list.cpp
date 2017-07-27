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

	return 0;
}
