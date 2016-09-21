/* CIST2362 - 20790 - Kimberly Jackson - SID: 0332
	Week 9ish, Personalized List Class - 10/30/12

	Description: Design and implement your own linked list class of strings (this should not be 
		a class template). The class should have the following methods:

		•append : adds  a new element to the end of the list
		•insert: adds a new element at a position in the list. The position is an integer value (not an iterator).
		•delete: deletes a node at a given position. The position is an integer value. 
		•constructor & copy constructor
		•destructor: must delete all of the nodes

*/

#include "list.h"
#include "Node.h"

using namespace std;

List::List()
{
	firstlink = NULL;
	lastlink = NULL;
};

List::List(string & value)
{
	Node *newnode = new Node(value);

	firstlink->prev = newnode;
	newnode->next = firstlink;
	firstlink = newnode;
};

 List::~List()
{

};

void List::append(string &value)
{

};

void List::insert(int target, string &value)
{
	
};

void List::deletenode(int target)
{
	for(int count = 1; count != target; count++)
	{

	};
};

