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

#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List : public Node
{
protected:
	Node *firstlink;
	Node *lastlink;

public:

	List();
	List(string &);
	List(List &);
	~List();

	void append(string &);
	void insert(int, string &);
	void deletenode(int);

};

#endif //LIST_H