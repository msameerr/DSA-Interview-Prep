#pragma once
#ifndef LINKEDLIST_FILE_H
#define LINKEDLIST_FILE_H

class Node
{
public:
    int data;
    Node* next;

    Node(int data);
};


void insertAtHead(Node*& head, int data);
void insertAtTail(Node*& head, int data);
void insertAtMiddle(Node*& head, int data, int loc);
void Deletion(Node*& head, int loc);
void print(Node* head);


void insertInCircular(Node*& tail, int element, int data);
void deleteInCircular(Node*& tail, int element);
void printCircular(Node* tail);


Node*reverseLinkedList(Node*& head);

#endif