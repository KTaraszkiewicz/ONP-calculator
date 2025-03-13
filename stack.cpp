#include "stack.h"
using namespace std;

Stack::Stack()
{ 
	first = NULL; 
}
StackData* Stack::GetFirst()
{
	return first;
}
bool Stack::empty() const
{
	return first == NULL;
}
char* Stack::topValue()
{
	if (!empty())
		return first->data;
	else {
		printf("Cannot give top value while empty");
		exit(1);
	}	
}
void Stack::pop()
{
	if (first == NULL) {
		printf("\nStack empty!");
		exit(1);
	}
	else {
		StackData* temp;
		temp = first;
		first = first->under;
		delete temp;
	}
}

void Stack::push(const char* n)
{
	StackData* temp = new StackData(n);
	if (!temp) {
		printf("\nTemporary StackData Error!");
		exit(1);
	}
	temp->under = first;
	first = temp;
}

void Stack::displayStack()
{
	StackData* temp;
	if (empty()) {
		printf("\nStack empty!");
		exit(1);
	}
	else {
		temp = GetFirst();
		while (temp != NULL) {
			printf("%s", temp->data);
			temp = temp->under;
			if (temp != NULL)
				printf(" ");
		}
	}
	printf("\n");
}

Stack::~Stack() 
{
	while (!empty()) {
		pop();
	}
	delete first;
}