#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
	int value;
	IntNode *next;
	IntNode(int value) : value(value), next(nullptr) { }
};

class IntList {
 private:
	IntNode *head;
	IntNode *tail;
 public:
	IntList(); //done
	~IntList(); //done
	void clear(); 
	void push_front(int); //done
	void pop_front(); //done
	bool empty() const; //done
	const int & front() const; // done
	const int & back() const; //done
	friend ostream & operator<<(ostream &, const IntList &); //done
};

#endif
