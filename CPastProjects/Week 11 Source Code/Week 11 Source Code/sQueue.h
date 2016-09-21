//
//
//      simplified queue class (adapter)
//
//      Described in Chapter 10 of
//      Data Structures in C++ using the STL
//      Published by Addison-Wesley, 1997
//      Written by Tim Budd, budd@cs.orst.edu
//      Oregon State University
//
//              Modified by Charles R. Hardnett, 2011

#include <deque>

using std::deque;


template <class T, class Container = deque<T> > 
class queue
{
public:
	// constructors
	queue() : qSize(0) {}
	
	// operations
	bool empty() { return qSize == 0; } 
	int size() { return qSize; } 
	T& front() { return c.front(); } 
	T& back() { return c.back(); } 
	
	void enqueue(T& x)	{ 
		qSize++;
		c.push_back(x); } 
	
	void dequeue() { 
		if (qSize > 0)
			qSize--;
		c.pop_front(); 
	}
	
protected:
    Container c;
	unsigned int qSize;
};

