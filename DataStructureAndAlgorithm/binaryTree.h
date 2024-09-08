#pragma once

#ifndef BINARYTREE_H
#define BINARYTREE_H

class node
{

public:
	int data;
	node* left;
	node* right;

	node(int data);

};

node* BuildTree(node*& root);
void printTree(node* root);

void LevelOrderTraversal(node* root);


#endif