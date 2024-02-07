/*
	Title:  List.cpp - Program2
	Author:  Tania Flores
	Course: CSC 1310 - 001
    Partner: Adrian Gonzalez
	Date:  3/15/2023
	Purpose: header file for a doubly-linked list
*/
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>       // doubly-linked list as template class
class List
{
    public:
        List();    //constructor
        ~List();   //destructor
        void print();    //prints the value of every element in the list
        void append(T*);   //creates a new node and adds that node as the last element of the list
        void mergesort();    //public function to begin sorting the list in descending order

    private:
        struct ListNode // list node structure
        {
            T* value;
            struct ListNode* next;
            struct ListNode* prev;
        };
        ListNode *head;
        ListNode *tail;
        void print (ListNode*);     //prints every value in the list after the parameter node
        ListNode *mergesort(ListNode *, ListNode*);     //manages the recursive calls that mergesort needs to make
        ListNode *merge(ListNode *, ListNode *);       //merges two list partitions together
        ListNode *split(ListNode *, ListNode *);     // subdivides a list partition into two more partitions
};

template <typename T>    //constructor
List<T>::List()
{
    head = NULL;
    tail = NULL;
}

template <typename T>     //destructor
List<T>::~List()
{
    ListNode *nodePtr;
    ListNode *nextNode;

    nodePtr = head;

    while (nodePtr != NULL)
    {
        nextNode = nodePtr -> next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template <typename T>       //prints the value of every element in the list
void List<T> :: print()
{
    print(head);
}

template <typename T>      //creates a new node and adds that node as the last element of the list
void List<T>:: append(T* newValue)
{
    ListNode *newNode;
    newNode = new ListNode;
    newNode->value = newValue;
    newNode->next = NULL;
    newNode->prev = NULL;
   
    if(!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev =tail;
        tail = newNode;
    }
}

template <typename T>     //public function to begin sorting the list in descending order
void List<T> :: mergesort()
{
    ListNode* nodePtr;

    head = mergesort(head, tail);
    nodePtr = head;

    while(!nodePtr->next)
    {
        nodePtr = nodePtr-> next;      
        tail -> next = NULL;
    }
    tail = nodePtr;
}

template <typename T>
void List<T>::print (ListNode* nodePtr)     //prints every value in the list after the parameter node
{
    if(head != NULL)
    {
        nodePtr = head;
        while(nodePtr)
        {
            cout << *(nodePtr->value) << endl;
            nodePtr = nodePtr->next;
        }
    }
}

template <typename T> 
typename List<T>::ListNode* List<T>::mergesort(ListNode *head, ListNode *tail)    //manages the recursive calls that mergesort needs to make
{
    if(!head || !head->next){
        return head;
    }
    
    ListNode *first = head;
    ListNode *second = split(head,tail);

    first = mergesort(first, second->prev);
    second = mergesort(second, tail);

    return merge(first, second);
}

template <typename T>
typename List<T>::ListNode* List<T>:: merge(ListNode *nodeOne, ListNode *nodeTwo)    //merges two list partitions together
{
   if(!nodeOne)
    {
        return nodeTwo;
    }
    if(!nodeTwo)
    {
        return nodeOne;
    }
    if(*(nodeOne->value)>*(nodeTwo->value))
    {
        nodeOne->next = merge(nodeOne->next, nodeTwo);
        nodeOne->next->prev = nodeOne;
        nodeOne->prev = NULL;

        return nodeOne;
    }
    else
    {
        nodeTwo->next = merge(nodeOne,nodeTwo->next);
        nodeTwo->next->prev = nodeTwo;
        nodeTwo->prev = NULL;
        return nodeTwo;
    }
}

template <typename T>
typename List<T>::ListNode* List<T>::split(ListNode *front, ListNode *last)    // subdivides a list partition into two more partitions
{
    ListNode *first = front;
    ListNode *second = last;
    ListNode *middle;
    
    while((first!=second) && (first->next!= second))
    {
        first = first->next;
        second = second->prev;
    }

    if(first != second)
    {
        middle = second;
        first->next = NULL;
        return middle;
    }

    else
    {
        middle = first->next;
        second->next = NULL;
        return middle;
    }
}

#endif