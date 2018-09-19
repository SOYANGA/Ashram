#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack-O(1).h"
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

/////////////////////////////////////////
void StackMinInit(MinStack* ps)
{
	assert(ps);
	StackInit(&ps->_st);
	StackInit(&ps->_min);
}
void StackMinDestory(MinStack* ps)
{
	assert(ps);
	StackDestory(&ps->_st);
	StackDestory(&ps->_min);
}
DataMinType StackMinTop(MinStack* ps)
{
	assert(ps);
	return StackTop(&(ps->_min));
}

void StackMinPush(MinStack* ps, DataMinType x)
{
	assert(ps);
	StackPush(&(ps->_st), x);
	if (StackEmpty(&(ps->_min))==0 || StackTop(&ps->_min) >= x)
	{
		StackPush(&(ps->_min), x);
	}
	else
		StackPush(&(ps->_min), StackTop(&(ps->_min)));
}
void StackMinPop(MinStack* ps)
{
	assert(ps);
	StackPop(&(ps->_min));
	StackPop(&(ps->_st));
}

////////////////////
void Test()
{
	MinStack s1;
	StackMinInit(&s1);
	StackMinPush(&s1, 4);
	StackMinPush(&s1, 3);
	StackMinPush(&s1, 3);
	StackMinPush(&s1, 1);
	StackMinPush(&s1, 0);
	StackMinPop(&s1);
	printf("栈中最小数为%d\n",StackMinTop(&s1));
	while (StackEmpty(&s1._min) != 0)
	{
		printf("%d ", StackTop(&s1._min));
		StackPop(&s1._min);
		printf("\n");
	}
	StackMinDestory(&s1);
}