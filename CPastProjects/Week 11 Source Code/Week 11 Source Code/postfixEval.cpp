//
//	test of rpn calculator routine
//
//	Described in Chapter 10 of
//	Data Structures in C++ using the STL
//	Published by Addison-Wesley, 1997
//	Written by Tim Budd, budd@cs.orst.edu
//	Oregon State University
//
// Modified by Charles R. Hardnett, 2011

#include <list>
#include <stack>
#include <iostream>

using namespace std;


//
//	class calculatorEngine
//		simulate the behavior of a simple integer calculator
//

class calculatorEngine {
public:
	enum  binaryOperator {plus, minus, multiply, divide};

	int   currentMemory   () { return data.top (); }
	void  pushOperand     (int value) { data.push (value); }
	void  doOperator      (binaryOperator theOp);

protected:
	stack <int, list<int> > data;
};


void calculatorEngine::doOperator(binaryOperator theOp)
	// perform a binary operation on stack values
{
	int right = data.top();
	data.pop();
	int left = data.top();
	data.pop();
	int result;
	switch(theOp) {	// do the operation
		case plus: 
			result = left + right;
			break;
		case minus:
			result = left - right;
			break;
		case multiply:
			result = left * right;
			break;
		case divide:
			result = left / right;
			break;
		}

	// push the result back on the stack
	data.push(result);
}

void calculator()
{	int intval;
	calculatorEngine calc;
	char c;

	while (cin >> c) {
		switch(c) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				cin.putback(c);
				cin >> intval;
				calc.pushOperand(intval);
				break;

			case '+':
				calc.doOperator(calculatorEngine::plus);
				break;

			case '-':
				calc.doOperator(calculatorEngine::minus);
				break;

			case '*':
				calc.doOperator(calculatorEngine::multiply);
				break;

			case '/':
				calc.doOperator(calculatorEngine::divide);
				break;

			case 'p':
				cout << calc.currentMemory() << '\n';
				break;

			case 'q':
				return; // quit calculator
			}
		}
}

int main () { 
	calculator();
	
	return 0;
 }