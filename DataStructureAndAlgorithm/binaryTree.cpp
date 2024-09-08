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