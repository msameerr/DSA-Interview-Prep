
#include<iostream>
using namespace std;

class Node
{

	public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}

};


void print(Node* head)
{

	Node* temp = head;

	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL";
	cout << endl;
}

// Question 01 : Insert at head, Tail, Middle and Deletion 

	/*Node* head = NULL;
	insertAtHead(head,2);
	insertAtTail(head, 4);
	insertAtHead(head,1);
	insertAtTail(head, 5);
	insertAtMiddle(head, 3, 3);
	insertAtMiddle(head, 0, 1);
	insertAtMiddle(head, 6, 7);
	Deletion(head, 3);*/

void insertAtHead(Node*& head, int data)
{
	Node* temp = new Node(data);

	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}

}

void insertAtTail(Node*& head, int data)
{

	Node* temp = new Node(data);

	if (head == NULL)
	{
		head = temp;
	}
	else 
	{
		Node* h = head;
		while(h->next != NULL)
		{
			h = h->next;
		}
		h->next = temp;
	}

}

void insertAtMiddle(Node*& head, int data, int loc)
{

	Node* nodeToInsert = new Node(data);

	if (loc == 1)
	{
		nodeToInsert->next = head;
		head = nodeToInsert;
		return;
	}

	int count = 1;
	Node* temp = head;
	while(loc-1 != count)
	{
		temp = temp->next;
		count++;
	}

	if (temp->next == NULL)
	{
		temp->next = nodeToInsert;
		return;
	}

	nodeToInsert->next = temp->next;
	temp->next = nodeToInsert;
}

void Deletion(Node*& head, int loc)
{

	if (loc == 1)
	{
		Node* temp = head->next;
		head = temp;
		return;
	}

	int cnt = 1;
	Node* current = head;
	Node* prvs = NULL;
	while (cnt != loc && current->next != NULL)
	{
		prvs = current;
		current = current->next;
		cnt++;
	}

	if (current->next == NULL)
	{
		prvs->next = NULL;
		return;
	}

	prvs->next = current->next;
	current->next = NULL;

}

// Question 02: Implement Circular Linked List with Deletion function
	/*Node* tail = NULL;
	insertInCircular(tail, 5, 3);
	insertInCircular(tail, 3, 7);
	insertInCircular(tail, 7, 8);
	printCircular(tail);
	deleteInCircular(tail, 7);
	printCircular(tail);*/


void printCircular(Node* tail)
{
	Node* temp = tail;

	do 
	{

		cout << temp->data << " -> ";
		temp = temp->next;

	} while (temp != tail);
	cout << "NULL";
	cout << endl;
}

void insertInCircular(Node*& tail, int element, int data)
{

	if (tail == NULL)
	{
		Node* temp = new Node(data);
		tail = temp;
		temp->next = temp;
	}
	else
	{
		Node* current = tail;

		while (current->data != element)
		{
			current = current->next;
		}

		Node* temp = new Node(data);
		temp->next = current->next;
		current->next = temp;

	}

}

void deleteInCircular(Node*& tail, int element)
{

	if (tail == NULL)
	{
		return;
	}

	Node* curr = tail->next;
	Node* prvs = tail;

	while (curr->data != element)
	{
		prvs = curr;
		curr = curr->next;
	}

	prvs->next = curr->next;

	if (curr == prvs)
	{
		tail = NULL;
	}

	if (tail == curr)
	{
		tail = prvs;
	}

	curr->next = NULL;

}

// Question 03 : Reverse a Linked List
	/*Node* head = NULL;
	insertAtHead(head, 2);
	insertAtTail(head, 4);
	insertAtHead(head, 1);
	insertAtTail(head, 5);
	insertAtMiddle(head, 3, 3);
	print(head);
	Node* temp = reverseLinkedList(head);
	print(temp);*/

Node* reverseLinkedList(Node*& head)
{

	Node* prvs = NULL;
	Node* curr = head;

	while (curr != NULL)
	{

		Node* forward = curr->next;
		curr->next = prvs;
		prvs = curr;
		curr = forward;

	}
	return prvs;
}

// Question 04 : Find Middle of the Linked List
