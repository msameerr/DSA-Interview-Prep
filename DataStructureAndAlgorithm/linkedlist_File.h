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
void printLinkedlist(Node* head);


void insertInCircular(Node*& tail, int element, int data);
void deleteInCircular(Node*& tail, int element);
void printCircular(Node* tail);


Node*reverseLinkedList(Node*& head);

void MiddleLinkedList(Node*& head);

Node* reverse_Kgroups(Node*& head, int k);

void mergeLinkedList(Node* head1, Node* head2, int k);

void create_loop(Node*& head, int element);
Node* FloydDetection(Node* head);

#endif