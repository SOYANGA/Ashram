#define _CRT_SECURE_NO_WARNINGS 1
#include "FaceTest.h"
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
	assert((ps->_top) > 0);
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
////////////////////////////////////////////////
//5.判断出栈合法性
int FindRightOrder()
{
	Stack s1;
	Stack s2;
	int j = 0;
	StackInit(&s1);
	StackInit(&s2);
	for (int i = 0; i < 5; i++)
	{
		StackPush(&s1, arry1[i]);
	}
	while (s1._top != 0 || s2._top != 0)
	{

		if (arry2[j] == s1._a[s1._top - 1])
		{
			StackPop(&s1);
			j++;
			continue;
		}
		if (arry2[j] == s2._a[s2._top - 1])
		{
			StackPop(&s2);
			j++;
			continue;
		}
		else if (arry2[j] != s1._a[s1._top - 1] && s1._top != 0)
		{
			StackPush(&s2, StackTop(&s1));
			StackPop(&s1);
			continue;
		}
		else
			return 0;
	}
	return 1;
}
void Test1()
{
	printf("出栈是否合法？：%d \n", FindRightOrder());
}

/////////////////////////////////////////////////////////////
//判断出栈合法性(优化版1)
int IsLegalStackOrder(int* in, int insize, int* out, int outsize)
{
	assert(in&&out);
	Stack st;
	StackInit(&st);
	int index = 0;
	int outdex = 0;
	while (insize != 0 || outsize != 0)
	{
		while (insize != 0)
		{
			StackPush(&st, in[index]);
			++index;
			--insize;
			if (StackTop(&st) == out[outdex])
			{
				StackPop(&st);
				++outdex;
				--outsize;
			}
		}
		if (StackTop(&st) == out[outdex])
		{
			StackPop(&st);
			++outdex;
			--outsize;
		}
		else
			return 0;
	}
	return 1;
}


void Test2()
{
	int in[5] = { 1, 2, 3, 4, 5 };
	int out[5] = { 5, 4, 3, 2, 2 };
	int insize = 5;
	int outsize = 5;
	printf("是否合法？：%d \n", IsLegalStackOrder(in, insize, out, outsize));
}
//////////////////////////////////////////////////////////
//判断出栈合法性（优化版2）
int IsLegalStackOrder_R(int* in, int insize, int* out, int outsize)
{
	assert(in&&out);
	Stack st;
	StackInit(&st);
	int index = 0;
	int outdex = 0;
	while (index < insize)
	{
		StackPush(&st, in[index]);
		++index;
		while (outdex < outsize&&StackTop(&st) == out[outdex])
		{
			StackPop(&st);
			++outdex;
		}
	}
	if (StackEmpty(&st))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void Test3()
{
	int in[5] = { 1, 2, 3, 4, 5 };
	int out[5] = { 5, 4, 3, 1, 2 };
	int insize = 5;
	int outsize = 5;
	printf("是否合法？：%d \n", IsLegalStackOrder_R(in, insize, out, outsize));
}
