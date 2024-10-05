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

void PreOrder(node* root);
void PostOrder(node* root);
void InOrder(node* root);

void BuildLevelOrder(node* &root);

void leafNodes(node* root, int& count);

int height(node* root);

#endif