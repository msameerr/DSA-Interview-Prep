#include<iostream>
#include<queue>
using namespace std;

// Question 01 : Implement binary tree

class node
{

public:
	int data;
	node* left;
	node* right;

	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

};

node* BuildTree(node*& root)
{
	int data;
	cout << "Enter data : ";
	cin >> data;

	if (data == -1)
		return NULL;

	root = new node(data);

	cout << "Enter root left of " << data << endl;
	root->left = BuildTree(root->left);

	cout << "Enter root right of " << data << endl;
	root->right = BuildTree(root->right);

	return root;

}

void printTree(node* root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";

	printTree(root->left);
	printTree(root->right);

}

// Question 02 : Level Order traversal 
void LevelOrderTraversal(node* root)
{

	queue<node*>q;

	q.push(root);
	q.push(NULL);

	while (!q.empty())
	{

		node* temp = q.front();
		q.pop();

		if (temp == NULL)
		{
			cout << endl;
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout << temp->data << " ";

			if (temp->left != NULL)
			{
				q.push(temp->left);
			}

			if (temp->right != NULL)
			{
				q.push(temp->right);
			}    
		}

	}

}

// Question 03 : Implement PreOrder, PostOrder, InOrder
void PreOrder(node* root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";

	PreOrder(root->left);
	PreOrder(root->right);

}

void PostOrder(node* root)
{
	if (root == NULL)
		return;


	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}

void InOrder(node* root)
{
	if (root == NULL)
		return;


	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);

}

// Question 04 : Build Binary tree from Level Order
	//node* root = NULL;
	//BuildLevelOrder(root);
	//LevelOrderTraversal(root);

void BuildLevelOrder(node* &root)
{

	cout << "Enter root Data : ";
	int data;
	cin >> data;
	root = new node(data);

	queue<node*> q;
	q.push(root);

	while (!q.empty())
	{

		node* temp = q.front();
		q.pop();

		cout << "Enter Left Data of " << temp->data << " : ";
		int leftdata;
		cin >> leftdata;
		if (leftdata != -1)
		{
			temp->left = new node(leftdata);
			q.push(temp->left);
		}

		cout << "Enter Right Data of " << temp->data << " : ";
		int rightdata;
		cin >> rightdata;
		if (rightdata != -1)
		{
			temp->right = new node(rightdata);
			q.push(temp->right);
		}

	}

}

// Question 05 : Count Leaf nodes
//int cnt = 0;
//leafNodes(root, cnt);
//cout << cnt << endl;

void leafNodes(node* root, int &count)
{

	if (root == NULL)
	{
		return;
	}

	if (root->left != NULL)
	{
		leafNodes(root->left,count);
	}

	if (root->right != NULL)
	{
		leafNodes(root->right,count);
	}

	if (root->left == NULL && root->right == NULL)
	{
		count = count + 1;
	}
	
}

// Question 06 : 