/* Title: Lab 5 - CSC 1310
	Author: Tania Perdomo Flores
	Date: 03/02/2023
	Purpose: inventory program that will alow user to enter inventory, take part of inventory, or quit	
*/
#ifndef DYNSTACK_H
#define DYNSTACK_H
#include <iostream>
#include <string>
using namespace std;

// a template class Node for implementing linked list
template <typename T>
class Node {
	public:
		T data;
		Node * next;
        //constructor
		Node (T data) {
			this -> data = data;
		}
};

// the template class
template <typename T>
class DynamicStack {

	private: 
		Node<T> * topOfStack;

	public:
        // constructor for class
		DynamicStack () {
			topOfStack = NULL;
		}
		bool isEmpty () {
			if (topOfStack == NULL) {
				return true;
			}
			return false;
		}
		void push (T item) {
			if (isEmpty ()) {
				topOfStack = new Node<T> (item);
			} else {
				Node<T> * newNode = new Node<T> (item);
				newNode -> next = topOfStack;
				topOfStack = newNode;
			}
		}
		void pop (T &item) {
			item = topOfStack -> data;
			Node <T> * toDelete = topOfStack;
			topOfStack = topOfStack -> next;
			// delete the intended item;
			delete toDelete;
		}
};
#endif
