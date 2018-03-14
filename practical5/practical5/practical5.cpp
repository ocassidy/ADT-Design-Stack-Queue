//================================================================================
// Name        : practical5.cpp
// Author      : a.mccaughey@ulster.ac.uk
// Version     : 1.0
// Description : practical 5 test program to utilise Static Stack/Queue classes
//================================================================================

#include <string>	// string type
#include <cstddef>	// size_t (an unsigned integer type used for sizes)
#include <cctype>	// tolower, toupper, isalpha, isdigit etc
#include <algorithm>

#include "ArrayStack.h"
#include "ArrayQueue.h"

using namespace std;

// Pre-Condition: c contains '-', '+', '/' or '*' 
// Post-Condition: '+' and '-' have lower precedence (so return 1)
//                  than '*' and '/' (so return 2)
int prec(char c) {
	if (c == '-' || c == '+') return 1; else return 2;
}

// Pre-Condition: infix is a valid infix expression containing single digit numbers
// Post-Condition returns an postfix value of expression
string infix2postfix(string infix) {
	Stack<int> s;                   // stack
	string post;                    // postfix expression

	for (size_t i = 0; i < infix.length(); i++) {
		if (isdigit(infix[i])) {      // operand
			post += infix[i];
		}
		else if (infix[i] == '(') { // opening bracket
			s.push(infix[i]);
		}
		else if (infix[i] == ')') { // closing bracket
			// add all stack elements up to open bracket to post
			while (s.top() != '(') {
				post += s.top();
				s.pop();
			}
			s.pop();  // remove opening bracket    
		}
		else {
			// must be an operator
			while (!s.isEmpty() && s.top() != '(' && prec(infix[i]) <= prec(s.top())) {
				post += s.top();
				s.pop();
			}
			s.push(infix[i]);
		}
	}
	// add remaining elements on stack to post
	while (!s.isEmpty()) {
		post += s.top();
		s.pop();
	}
	return post;
}

// Post-Condition: return true if expr contains matching brackets otherwise false
bool bracketCheck(string expr) {

	Stack<char> sStk(expr.length());
	bool valid = true;

	for (int i = 0; i < expr.length(); i++) {
		if (expr[i] == '{' || expr[i] == '[' || expr[i] == '(') {
			sStk.push(tolower(i));
		}
		else if (expr[i] == '}' || expr[i] == ']' || expr[i] == ')') {
			if (sStk.isEmpty()) {
				valid = false;
			}
			else {
				char c = sStk.top();
				sStk.pop();

				if (c == '(' && expr[i] != ')' || c == '{' && expr[i] != '}' || c == '[' && expr[i] != ']') {
					valid = false;
				}
			}
		}
	}
	if (valid == true) {
		cout << expr << " has valid brackets." << endl;
	}
	else if (valid == false) {
		cout << expr << " has invalid brackets." << endl;
	}
	return (valid && sStk.isEmpty());
}

// Pre-Condition: infix is a valid expression containing single digit numbers
// Post-Condition: returns the result of the expression evaluation
int evaluateInfixExpression(string infix) {

	// complete this function using algorithm from notes

	return 0;
}


// Post-Condition: returns true if string is a palindrome, otherwise false
bool isPalindrome(string str) {
	// complete this function using algorithm from notes
	Stack<char> sStk(str.length());
	Queue<char> qQue(str.length());
	bool same = false;

	for each (char c in str) {
		if (isalpha(c)) {
			sStk.push(tolower(c));
			qQue.enqueue(tolower(c));
		}
	}
	same = true;
	while (!qQue.isEmpty() && same) {
		char qChar = qQue.peek();
		char sChar = sStk.top();

		sStk.pop();
		qQue.dequeue();

		if (qChar != sChar) {
			same = false;

		}
	}

	if (same == true) {
		cout << str << " is a palindrome." << endl;
		return true;
	}
	else {
		cout << str << " is not a palindrome." << endl;
		return false;
	}
}


//------  Following are driver functions called from main function to test the functions completed above ----------

// Provides an expression evaluator sentinel loop
void testSingleDigitCalculator() {

	// complete this function using a sentinel controlled loop to
	// continually request user to enter an expression to evaluate, then print the result
	// loop can be terminated by entering 'quit'

}


// Provides a palindrome evaluator sentinel loop
void testPalindromeChecker() {

	// complete this function using a sentinel controlled loop to
	// continually request user to enter an string to check for palindrome, then print the result
	// loop can be terminated by entering 'quit'
	string sentinel;
	string str;

	cout << "Use 'QUIT' to exit this loop. Else press any key to continue." << endl;
	getline(std::cin, sentinel);
	transform(sentinel.begin(), sentinel.end(), sentinel.begin(), ::toupper);

	while (sentinel != "QUIT") {
		cout << "Enter a string to check as a palindrome." << endl;
		getline(std::cin, str);
		isPalindrome(str);

		cout << "Use 'QUIT' to exit this loop." << endl;
		getline(std::cin, sentinel);
		transform(sentinel.begin(), sentinel.end(), sentinel.begin(), ::toupper);
	}
}


// Provides a bracket evaluator sentinel loop
void testBracketChecker() {

	// complete this function using a sentinel controlled loop to
	// continually request user to enter an string to check for palindrome, then print the result
	// loop can be terminated by entering 'quit'
	string sentinel;
	string str;

	cout << "Use 'QUIT' to exit this loop. Else press any key to continue." << endl;
	getline(std::cin, sentinel);
	transform(sentinel.begin(), sentinel.end(), sentinel.begin(), ::toupper);

	while (sentinel != "QUIT") {
		cout << "Enter a string to check the brackets of." << endl;
		getline(std::cin, str);
		bracketCheck(str);

		cout << "Use 'QUIT' to exit this loop." << endl;
		getline(std::cin, sentinel);
		transform(sentinel.begin(), sentinel.end(), sentinel.begin(), ::toupper);
	}
}

// Main method.
int main() {

	//testPalindromeChecker();
	testBracketChecker();

	// testSingleDigitCalculator();
	system("pause");

	return 0;
}
