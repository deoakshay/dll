#include<iostream>

#ifndef CSCI_311_DOUBLYLINKEDLIST_CPP
#define CSCI_311_DOUBLYLINKEDLIST_CPP
#include "doublylinkedlist.h"

using std::string;
using namespace std;
//Constructor for the Doubly Linked List
DoublyLinkedList::DoublyLinkedList()

{

	head = NULL;
	tail = NULL;
	current = NULL;//new Node();
}

//Destructor for the Doubly Linked List
DoublyLinkedList::~DoublyLinkedList()
{

}

//Constructor for the Node
DoublyLinkedList::Node::Node()
{
	next = NULL;
	prev = NULL;
}

//Destructor for the Node
DoublyLinkedList::Node::~Node()
{

}

//Parameterized constructor for the Node to assign and store data in the node
DoublyLinkedList::Node::Node(string& node_data)
{
		this->data = new string(node_data);
}

//The function appends the song, but if no list exist then it creates the list
void DoublyLinkedList::append(string &append_song)
{
	current = new Node(append_song);
	if (empty())
	{
		head = new Node(append_song);
		head->prev = NULL;
		head->next = NULL;
		current = head;
		tail = head;
	}
	else
	{
		tail->next = current;
		current->prev = tail;
		tail = current;
		tail->next = NULL;
	}
	current = tail;
}

//The function checks if there is a list or not.
bool DoublyLinkedList::empty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

// Inserts a song after the song to which the current node is pointing
void DoublyLinkedList::insertAfter(string&ia_song)
{
	Node* y = new Node;
	if (empty())
	{
		head = new Node(ia_song);
		head->prev = NULL;
		head->next = NULL;
		current = head;
		tail = head;
	}
	else
	{
		if (current == tail)
		{
			Node *y = new Node(ia_song);
			tail->next = y;
			y->prev = tail;
			y->next=NULL;
			tail = y;
			current = tail;
		}
		else
		{
			Node *y = new Node(ia_song);
			y->next = current->next;
			current->next->prev = y;
			current->next = y;
			y->prev = current;
			current = y;
		}
	}
}

//Inserts a song before the song to which the current node is pointing
void DoublyLinkedList::insertBefore(string&ib_song)
{
	Node* y = new Node;
	if (empty())
	{
		head = new Node(ib_song);
		head->prev = NULL;
		head->next = NULL;
		current = head;
		tail = head;
	}
	else
	{
		if (current == head)
		{
			Node *y = new Node(ib_song);
			y->next = head;
			head->prev = y;
			y->prev = NULL;
			head = y;
			current = head;
		}
		else
		{
			Node *y = new Node(ib_song);
			y->next = current;
			current->prev->next = y;
			y->prev = current->prev;
			current->prev = y;
			current = y;
		}
	}
}

//Will delete the song from the playlist
void DoublyLinkedList::remove(string&r_song)
{
	if (find(r_song))
	{
		Node *y = new Node;
		if (*(head->data) == r_song)
		{
			if (!next())
			{
				y = head;
				current = NULL;
				tail = NULL;
				head = NULL;
			}
			else
			{
				y = head;
				head = head->next;
				head->prev = NULL;
				current = head;
			}
		}
		else
		{
			if (*(tail->data) == r_song)
			{
				y = tail;
				tail = y->prev;
				tail->next = NULL;
				current = tail;
			}
			else
			{
				y = current;
				current = y->next;
				y->prev->next = current;
				current->prev = y->prev;
			}
		}
		delete y;
	}
	else
	{
		return;
	}
}
//Will make the current node point to the head of the Doubly Linked List
void DoublyLinkedList::begin()
{
	current = head;
}
//Will make the current node point to the tail of the Doubly Linked List
void DoublyLinkedList::end()
{
	current = tail;
}
//Checks if there is a next node for the current node
bool DoublyLinkedList::next()
{
	if ((current->next) ==NULL)
		return false;
	else
	{
		current = current->next;
		return true;
	}
}
//Checks if there is a previous node for the current node
bool DoublyLinkedList::prev()
{
	if ((current->prev) == NULL)
		return false;
	else
	{
		current = current->prev;
		return true;

	}
}
//Searches for the reuqested song in the playlist
bool DoublyLinkedList::find(string&f_song)
{
	Node *y = head;
	if (empty())
	{
		return false;
	}
	else
	{
		while (y != NULL)
		{
			if (*(y->data) == f_song)
			{
				current = y;
				return true;
			}
			else
			{
				y = y->next;
			}
		}
		return false;
	}
	delete y;
}
//This returns the data to which the current node is pointing
const string &DoublyLinkedList::getData()
{
		const string *s = (current->data);
		return *s;
}


void  DoublyLinkedList::show()
{
	Node*x = head;
	while (x != NULL)
	{
		cout << "\n" << *x->data << endl;
		x = x->next;
	}
}

#endif
