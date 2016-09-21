//
//	test of infix to Postfix routine
//
//	Described in Chapter 10 of
//	Data Structures in C++ using the STL
//	Published by Addison-Wesley, 1997
//	Written by Tim Budd, budd@cs.orst.edu
//	Oregon State University
//
// Modified by Charles R. Hardnett, 2011

#include <string>
#include <list>
#include <stack>
#include <iostream>

using namespace std;


// operators listed in precedence order
enum operators { leftparen, plusOp, minusOp, multiplyOp, divideOp };


// function prototypes
string opString (operators);
void processOp(operators, stack<operators, list<operators> >&, string&);
string infixToPostfix(const string&);


int main () {
	
	string input = "5 * (27 + 3 * 7) + 22";
	
	do {
		cout << "infix: " << input << endl;
		cout << "postfix: " << infixToPostfix(input) << "\n";

		cout << "Enter an expression: "; 
		// read input
		getline(cin, input);

	} while (input != "done");
	
	cout << "Good bye" << endl;
	
	return 0;
}



// return a textual representation of an operator
string opString (operators theOp) {

	switch (theOp) {
		case plusOp:   return " + ";
		case minusOp:  return " - ";
		case multiplyOp:  return " * ";
		case divideOp: return " / ";
	}
}

// pop stack while operators have higher precedence
void processOp(operators theOp, stack<operators, list<operators> > & opStack, string & result) {

	while ((!opStack.empty()) && theOp < opStack.top()) {		
		result += opString(opStack.top());
		opStack.pop();
	}
	// then push current operator
	opStack.push(theOp);
}



// convert infix to postfix 
string infixToPostfix(const string& infixStr)
{ 
	stack <operators, list<operators> > opStack;
	string result("");
	int i = 0;

	while (infixStr[i] != '\0') {
		if (isdigit(infixStr[i])) {	// process constants
			while (isdigit(infixStr[i])) 
				result += infixStr[i++];
			result += " ";	// add separator
			}
		else
			switch(infixStr[i++]) {	// process other characters
				case '(': 
					opStack.push(leftparen); 
					break;
				case ')':
					while (opStack.top() != leftparen) {
						result += opString(opStack.top());
						opStack.pop();
					}
					opStack.pop();	// pop off left paren
					break;
				case '+': processOp(plusOp, opStack, result);
					break;
				case '-': processOp(minusOp, opStack, result);
					break;
				case '*': processOp(multiplyOp, opStack, result);
					break;
				case '/': processOp(divideOp, opStack, result);
					break;
				}
		}
		
		
	while (! opStack.empty()) {	// empty the stack on end of input
		result += opString(opStack.top());
		opStack.pop();
	}

	return result;	// return result string
}



