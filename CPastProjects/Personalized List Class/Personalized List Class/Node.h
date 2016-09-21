#include <string>

using namespace std;

class Node
{
public:
	Node *next;
	Node *prev;
	string value;

	//constructors
	Node();
	Node(string &);
	~Node();
};