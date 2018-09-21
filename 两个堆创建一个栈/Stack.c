#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (DataType*)malloc(sizeof(DataType)* 3);
	if (ps->_a == NULL)
	{
		exit(EXIT_FAILURE);
	}
	ps->_top = 0;
	ps->_capcity = 3;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	ps->_top = ps->_capcity = 0;
	free(ps->_a);
	ps->_a = NULL;
}
void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	if (ps->_capcity == ps->_top)
	{
		ps->_a = (DataType*)realloc(ps->_a, sizeof(DataType)*(ps->_capcity) * 2);
		if (ps->_a == NULL)
		{
			exit(EXIT_FAILURE);
		}
		ps->_capcity *= 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps->_a);
	assert(ps->_top > 0);
	ps->_top--;
}
DataType StackTop(Stack* ps)
{
	assert(ps->_a);
	assert((ps->_top)>0);
	return ps->_a[ps->_top - 1];
}
//为空为0
//非空为1
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
