#include <iostream>
#include "StackElement.h"
#pragma once
using namespace std;


class Stack {
	StackData* first;
public:
	Stack();
	StackData* GetFirst();
	bool empty() const;
	char* topValue();
	void pop();
	void push(const char* n);
	void displayStack();
	~Stack();
};