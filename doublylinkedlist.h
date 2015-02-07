#include<string.h>
#include<string>

#ifndef CSCI_311_DOUBLYLINKEDLIST_H
#define CSCI_311_DOUBLYLINKEDLIST_H

using namespace std;

class DoublyLinkedList
{
private:
	class Node
	{
	public:
		Node* prev;
		Node* next;
		string* data;
		Node();
		~Node();
		Node(string&s);
	};
	Node* head;
	Node* tail;
	Node* current;
public:
DoublyLinkedList();
~DoublyLinkedList();
void append(string&);
void insertBefore(string&);
void insertAfter(string&);
void remove(string&);
void begin();
void end();
void show();
bool find(string&);
bool empty();
bool next();
bool prev();
const string& getData();


};



#endif