#include <iostream>
#pragma once
using namespace std;
#define MAX_CHAR_SIZE 13

class StackData {
public:
	char data[MAX_CHAR_SIZE];
	StackData* under;
	StackData(const char *n);
	~StackData();
};
