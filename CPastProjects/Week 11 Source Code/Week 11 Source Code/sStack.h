//
//
//      simplified stack class (adapter)
//
//      Described in Chapter 10 of
//      Data Structures in C++ using the STL
//      Published by Addison-Wesley, 1997
//      Written by Tim Budd, budd@cs.orst.edu
//      Oregon State University
//
//		Modified by Charles R. Hardnett, 2011
#include <deque>

using std::deque;


template <class T, class Container = deque<T> > 
class stack {
public:
	stack() : sSize(0) {}
	
	// operatiions
	bool	empty()	{ return sSize == 0; }
	int		size()	{ return sSize; }
	T&		top() { return cont.back(); }
	void	push(T& x) { 
		sSize++;
		cont.push_back(x); 
	}
	void	pop()	{ 
		if (sSize > 1)
			sSize--;
		cont.pop_back(); 
	}
	
protected:
	Container cont;
	unsigned int sSize;
};

