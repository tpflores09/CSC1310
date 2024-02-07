#ifndef LIST_H 
#define LIST_H
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class LinkedList{
    public:
	void appendNode(string);      //functions
    void insertNode(string);
    void deleteNode(string);
    void displayList() const;
	
	LinkedList();   // constructor
    ~LinkedList();   //destructor

	private:
    struct ListNode{
        string node;  
        struct ListNode* next;
    };
    ListNode *head;
	ListNode *tail;
};
LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
}
void LinkedList::appendNode(string string){
	ListNode *newNode;
	newNode = new ListNode();
	newNode->node = string;
	newNode->next = NULL;
	if (head ==NULL){
		head = newNode;
		tail = newNode;
	} else {
		tail ->next = newNode;
		tail=newNode;
	}
}
void LinkedList::insertNode(string string){
	ListNode *newNode;

	newNode = new ListNode;
	newNode->node=string;
	newNode->next= head;
	head=newNode;
}
void LinkedList::deleteNode(string string){
	if (head == NULL){
		return;
	}
	if (head->node==string){
		ListNode *nodePtr=head;
		head=head->next;
		delete head;
	}
	ListNode *currNode=head;
	ListNode *prevNode=head;
	while (currNode!=tail){
		if(currNode->node==string){
			break;
		}
		prevNode=currNode;
		currNode=currNode->next;
	}
	prevNode->next=currNode-> next;
}
  //displayList function
void LinkedList::displayList()const{
	ListNode *node=head;
	while (node){
		cout << node->node << endl;
		node = node->next;
	}
}
//destructor
LinkedList::~LinkedList(){
    ListNode *nodePtr;
    ListNode *nextNode;
    nodePtr = head;
	while (nodePtr!=NULL){
        nextNode = nodePtr->next;

        delete nodePtr;
		nodePtr = nextNode;
    }
	cout << endl;
	cout << "All list nodes have been removed." << endl;
	cout << endl;
	cout << endl;
}
	
#endif