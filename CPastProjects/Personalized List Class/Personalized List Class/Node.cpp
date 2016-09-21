#include "Node.h"

using namespace std;

Node::Node()
{
	value = " ";
	prev = NULL;
	next = NULL;
};

Node::Node(string & val)
{
	value = val;
	prev = NULL;
	next = NULL;
};

Node::~Node()
{
	delete next;
	delete prev;
};