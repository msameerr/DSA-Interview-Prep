#include<iostream>
#include "arrayfile.h"
#include "linkedlist_File.h"
#include "binaryTree.h"

using namespace std;

int main()
{

	node* root = NULL;
	BuildTree(root);
	printTree(root);
	cout << endl;
	LevelOrderTraversal(root);

}