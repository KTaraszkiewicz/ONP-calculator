#include "stack.h"
#include "StackElement.h"
#include <string.h>
#include <iostream>
#include "queue.h"
using namespace std;
#define CHARSIZE 13


void intToCharTable(int number, char*& l)
{
	int i = 0;
	bool minus = false;
	if (number < 0) {
		minus = true;
		number = -number;
	}
	if (number == 0) {
		l[i++] = '0';
	}
	else {
		while (number > 0 && i < CHARSIZE - 1) {
			l[i++] = char(number % 10)+48;
			number /= 10;
		}
		if (minus) {
			l[i++] = '-';
		}
		for (int j = 0; j < i / 2; ++j) {
			char temp = l[j];
			l[j] = l[i - j - 1];
			l[i - j - 1] = temp;
		}
	}
	l[i] = '\0';
}

void savingTheNumberOfMaxMin(char*& l, Stack& temp, Queue& ONP)
{
	int lenght = strlen(l), j = 0;
	for (j = 3; j < 3 + lenght; j++)
	{
		temp.topValue()[j] = l[j - 3];
	}
	temp.topValue()[j] = '\0';
	ONP.push(temp.topValue());
	temp.pop();
	memset(l, 0, strlen(l));
}


void handleONP_stack(Queue& ONP,Stack& stack)
{
	ONP.push(stack.topValue());
	stack.pop();
}

void ElseCase(Queue& ONP, char*& l)
{
	ONP.push(l);
	memset(l, 0, strlen(l));
}

void RightBracketCase(Queue& ONP, char*& l, Stack& stack,Stack& temp,int &j)
{
	j = 0;
	while (strcmp(stack.topValue(), "("))
	{
		if (strcmp(stack.topValue(), ","))handleONP_stack(ONP, stack);
		else stack.pop();
	}
	stack.pop();
	if (!strcmp(stack.topValue(), "MIN") || !strcmp(stack.topValue(), "MAX") || !strcmp(stack.topValue(), "IF"))
	{
		while (!strcmp(temp.topValue(), ","))
		{
			j++;
			temp.pop();
		}
		j++;
		memset(l, 0, strlen(l));
		if (!strcmp(stack.topValue(), "MIN") || !strcmp(stack.topValue(), "MAX"))
		{
			intToCharTable(j, l);
			savingTheNumberOfMaxMin(l, stack, ONP);
		}
		else handleONP_stack(ONP, stack);
		j = 1;
		temp.pop();
	}
	else if (!strcmp(stack.topValue(), "N")) handleONP_stack(ONP, stack);
	memset(l, 0, strlen(l));
}

void CommaInsideCase(Queue& ONP, Stack& stack)
{
	stack.pop();
	while (strcmp(stack.topValue(), "(") && strcmp(stack.topValue(), ","))
	{
		if (strcmp(stack.topValue(), ","))handleONP_stack(ONP, stack);
		else stack.pop();
	}
}

void PlusMinusCase(Queue& ONP, char*& l, Stack& stack)
{
	while (strcmp(stack.topValue(), "#") && strcmp(stack.topValue(), "(") && strcmp(stack.topValue(), ","))
	{
		handleONP_stack(ONP, stack);
	}
	stack.push(l);
	memset(l, 0, strlen(l));
}

void MultiplicationDivisionCase(Queue& ONP, char*& l, Stack& stack)
{
	while (!strcmp(stack.topValue(), "N"))
	{
		handleONP_stack(ONP, stack);
	}
	if (!strcmp(stack.topValue(), "*") || !strcmp(stack.topValue(), "/"))
	{
		handleONP_stack(ONP, stack);
	}
	stack.push(l);
	memset(l, 0, strlen(l));
}

void ClearingStackStep(Queue& ONP, Stack& stack)
{
	while (strcmp(stack.topValue(), "#"))
	{
		ONP.push(stack.topValue());
		stack.pop();
	}
}

void traditionalToONP(Queue &ONP,char* &l, Stack& stack)
{
	int j = 0;
	Stack temp;
	const char* singleHash = "#";
	temp.push(singleHash);
	stack.push(singleHash);
	while (cin >> l)
	{
		if (*l == '.')break;
		if (*l == ',')
		{
			temp.push(l);
			stack.push(l);
			CommaInsideCase(ONP, stack);
			memset(l, 0, strlen(l));
			continue;
		}
		if (!strcmp(l, "MIN") || !strcmp(l, "MAX")
			|| !strcmp(l, "IF") || !strcmp(l, "N"))
		{
			stack.push(l);
			if(!strcmp(l, "MIN") || !strcmp(l, "MAX") || !strcmp(l, "IF"))temp.push(l);
			memset(l, 0, strlen(l));
			continue;
		}
		if (*l== '(')
		{
			stack.push(l);
			memset(l, 0, strlen(l));
			continue;
		}
		if (*l== ')')
		{
			RightBracketCase(ONP, l, stack,temp,j);
			continue;
		}
		if (*l == '+' || *l == '-')
		{
			PlusMinusCase(ONP, l, stack);
			continue;
		}
		if (*l == '*' || *l == '/')
		{
			MultiplicationDivisionCase(ONP, l, stack);
			continue;
		}
		else
		{
			ElseCase(ONP, l);
		}
	}
	ClearingStackStep(ONP, stack);
	stack.pop();
	temp.pop();
}

void operatorsSequence(Stack& stack,int temp,char *&l)
{
	intToCharTable(temp, l);
	stack.push(l);
}

int MinMaxNumber(Stack& stack)
{
	char* dest = new char[strlen(stack.topValue()) - 2];
	memset(dest, 0, strlen(stack.topValue()) - 2);
	for (unsigned int i=0; i < strlen(stack.topValue()) - 3; i++)
	{
		dest[i] = stack.topValue()[i + 3];
	}
	int number = atol(dest);
	delete[] dest;
	return number;
}

void MinN(Stack& stack,int &howMany,int &smallest)
{
	for (int i = 0; i < howMany-1; i++)
	{
		if (strtol(stack.topValue(), NULL, 10) < smallest)smallest = strtol(stack.topValue(), NULL, 10);
		stack.pop();
	}
}

void MaxN(Stack& stack,int& howMany, int& biggest)
{
	for (int i = 0; i < howMany-1; i++)
	{
		if (strtol(stack.topValue(), NULL, 10) > biggest)biggest = strtol(stack.topValue(), NULL, 10);
		stack.pop();
	}
}

void MinMaxNCalc(Stack& stack, char*& l)
{
	int howMany;
	int temp, whichOne = 0;
	if (!strncmp(stack.topValue(), "MIN", 3))whichOne = -1;
	if (!strncmp(stack.topValue(), "MAX", 3))whichOne = 1;
	if (whichOne)
	{
		stack.displayStack();
		howMany = MinMaxNumber(stack);
		stack.pop();
		temp = strtol(stack.topValue(), NULL, 10);
		stack.pop();
		if (whichOne == -1)MinN(stack, howMany, temp);
		else MaxN(stack, howMany, temp);
		intToCharTable(temp, l);
		stack.push(l);
	}
}

void IfCalc(Stack& stack, char*& l)
{
	int temp1, temp2, temp3;
	if (!strcmp(stack.topValue(), "IF"))
	{
		stack.displayStack();
		stack.pop();
		temp1 = atol(stack.topValue());
		stack.pop();
		temp2 = atol(stack.topValue());
		stack.pop();
		temp3 = atol(stack.topValue());
		stack.pop();
		if (temp3 > 0)
		{
			intToCharTable(temp2, l);
			stack.push(l);
		}
		else
		{
			intToCharTable(temp1, l);
			stack.push(l);
		}
	}
}

void PlusCalc(Stack& stack, char*& l,int &temp)
{
	stack.displayStack();
	stack.pop();
	temp = strtol(stack.topValue(), NULL, 10);
	stack.pop();
	temp += strtol(stack.topValue(), NULL, 10);
	stack.pop();
	operatorsSequence(stack, temp, l);
}

void MinusCalc(Stack& stack, char*& l, int& temp,int& temp2)
{
	stack.displayStack();
	stack.pop();
	temp = strtol(stack.topValue(), NULL, 10);
	stack.pop();
	temp2 = strtol(stack.topValue(), NULL, 10);
	temp = temp2 - temp;
	stack.pop();
	operatorsSequence(stack, temp, l);
}

void MultiplicationCalc(Stack& stack, char*& l, int& temp)
{
	stack.displayStack();
	stack.pop();
	temp = strtol(stack.topValue(), NULL, 10);
	stack.pop();
	temp *= strtol(stack.topValue(), NULL, 10);
	stack.pop();
	operatorsSequence(stack, temp, l);
}

void DivisionCalc(Stack& stack, char*& l, int& temp, int& temp2,bool& breakPoint,Queue& ONP)
{
	stack.displayStack();
	stack.pop();
	temp = strtol(stack.topValue(), NULL, 10);
	stack.pop();
	temp2 = strtol(stack.topValue(), NULL, 10);
	stack.pop();
	if (temp == 0)
	{
		printf("ERROR\n");
		breakPoint = false;
		while (!stack.empty())
			stack.pop();
		while (!ONP.empty())
			ONP.pop();
	}
	else
	{
		temp = temp2 / temp;
		operatorsSequence(stack, temp, l);
	}
}

void doMath(Queue &ONP,Stack& stack,char *&l,bool &breakPoint)
{
	int temp, temp2;
	if (!strcmp(stack.topValue(), "+")) PlusCalc(stack, l, temp);
	if (!strcmp(stack.topValue(), "-")) MinusCalc(stack, l, temp, temp2);
	if (!strcmp(stack.topValue(), "*")) MultiplicationCalc(stack, l, temp);
	if (!strcmp(stack.topValue(), "/")) DivisionCalc(stack, l, temp, temp2,breakPoint, ONP);
	if (breakPoint)
	{
		MinMaxNCalc(stack, l);
		IfCalc(stack, l);
		if (!strcmp(stack.topValue(), "N"))
		{
			stack.displayStack();
			stack.pop();
			temp = strtol(stack.topValue(), NULL, 10) * (-1);
			stack.pop();
			intToCharTable(temp, l);
			stack.push(l);
		}
	}
	if(breakPoint)ONP.pop();
}

void calculating(Queue& ONP, Stack& stack,char *l)
{
	bool breakPoint = true;
	while(!ONP.empty())
	{
		if (breakPoint)
		{
			memset(l, 0, strlen(l));
			stack.push(ONP.frontValue());
			doMath(ONP,stack, l, breakPoint);
		}
		else break;
	}
	if (breakPoint)
	{
		stack.displayStack();
		stack.pop();
	}
}

int main()
{
	Queue ONP;
	Stack stos;
	char* l = new char[CHARSIZE];
	int n;
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		printf("\n");
		traditionalToONP(ONP, l, stos);
		ONP.displayQueue();
		calculating(ONP, stos, l);
	}
	delete[] l;
	return 0;
}


