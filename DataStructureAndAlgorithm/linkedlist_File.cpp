
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


void printLinkedlist(Node* head)
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
	//Node* head = NULL;
	//insertAtHead(head, 2);
	//insertAtTail(head, 4);
	//insertAtHead(head, 1);
	//insertAtTail(head, 5);
	//insertAtMiddle(head, 3, 3);
	//insertAtTail(head, 6);
	//insertAtTail(head, 7);
	//print(head);
	//MiddleLinkedList(head);

void MiddleLinkedList(Node*& head)
{

	Node* fast = head->next;
	Node* slow = head;

	while (fast != NULL)
	{

		slow = slow->next;

		fast = fast->next;
		if (fast != NULL)
		{
			fast = fast->next;
		}

	}

	cout << "Middle - " << slow->data << endl;

}


// Question 05 : Reverse LinkedList in K-Groups

Node* reverse_Kgroups(Node*& head, int k)
{

	if (head == NULL)
		return NULL;

	Node* current = head;
	Node* prvs = NULL;
	Node* forward = NULL;
	int count = 0;

	while (count < k && current != NULL)
	{
		forward = current->next;
		current->next = prvs;
		prvs = current;
		current = forward;
		count++;
	}

	if (forward != NULL)
	{
		head->next = reverse_Kgroups(forward, k);
	}

	return prvs;
}


// Question 06 : Merging two Linked List by k-groups
// head1 : 1 -> 2 -> 3 -> 4
// head2 : 5 -> 6 -> 7 -> 8
// Output : 1 -> 2 -> 5 -> 6 -> 3 -> 4 -> 7 -> 8

/*Node* head1 = NULL;
	insertAtTail(head1, 1);
	insertAtTail(head1, 2);
	insertAtTail(head1, 3);
	insertAtTail(head1, 4);

	Node* head2 = NULL;
	insertAtTail(head2, 5);
	insertAtTail(head2, 6);
	insertAtTail(head2, 7);
	insertAtTail(head2, 8);*/


void mergeLinkedList(Node* head1, Node* head2, int k)
{
	int turn = 0;

	Node* curr1 = NULL;
	Node* for1 = head1;

	Node* curr2 = NULL;
	Node* for2 = head2;

	while (for1 != NULL && for2 != NULL)
	{

		if (turn % 2 == 0)
		{
			int count = 0;
			while (count < k)
			{
				curr1 = for1;
				for1 = for1->next;
				count++;
			}
			curr1->next = for2;
			turn++;
		}
		else
		{
			int count = 0;
			while (count < k)
			{
				curr2 = for2;
				for2 = for2->next;
				count++;
			}
			curr2->next = for1;
			turn++;
		}

	}
	cout << "output : " << endl;

	printLinkedlist(head1);

}

// Question 07 : Loop Detection in Circularly linkedlist
// we use Floyd's cycle detection method

void create_loop(Node*& head, int element)
{

	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	Node* findElement = head;
	while (findElement->data != element)
	{
		findElement = findElement->next;
	}

	temp->next = findElement;
	//print(head);
}

Node* FloydDetection(Node* head)
{

	if (head == NULL)
	{
		return NULL;
	}

	Node* slow = head;
	Node* fast = head;
	while (slow != NULL && fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			fast = fast->next;
		}
		slow = slow->next;


		if (slow == fast)
		{
			return fast;
		}
	}
	return NULL;

}

// Question 08 : Find start/Begining node of loop and remove loop in linked list
	//Node* head = NULL;
	//insertAtHead(head, 2);
	//insertAtTail(head, 4);
	//insertAtHead(head, 1);
	//insertAtTail(head, 5);
	//insertAtMiddle(head, 3, 3);
	//insertAtTail(head, 6);
	//insertAtTail(head, 7);
	//print(head);
	//create_loop(head, 4);

	//Node* temp = FloydDetection(head);
	//cout << temp->data << endl;


