#define _CRT_SECURE_NO_WARNINGS 1
#include "QueueByTwoStack.h"
void QueueByTwoStackInit(QueueByTwoStack* pq)
{
	assert(pq);
	Stack*p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	p1->_a = (DataType*)malloc(sizeof(DataType)* 3);
	p2->_a = (DataType*)malloc(sizeof(DataType)* 3);
	if (p2->_a == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (p1->_a == NULL)
	{
		exit(EXIT_FAILURE);
	}
	p1->_top = p2->_top = 0;
	p1->_capcity = p2->_capcity = 3;
}
void QueueByTwoStackDestory(QueueByTwoStack* pq)
{
	assert(pq);
	Stack*p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	p1->_top = p1->_capcity = p2->_capcity = p2->_top = 0;
	free(p1->_a);
	free(p2->_a);
	p1->_a = p2->_a = NULL;
}
void QueueByTwoStackPush(QueueByTwoStack* pq, DataType x)
{
	assert(pq);
	Stack*p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	StackPush(p1, x);
}
void QueueByTwoStackPop(QueueByTwoStack* pq)
{
	assert(pq);
	Stack*p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	int data = 0;
	if (StackEmpty(p2) == 0)
	{
		while (StackEmpty(p1) != 0)
		{
			data = StackTop(p1);
			StackPop(p1);
			StackPush(p2, data);
		}
	}
	StackPop(p2);
}
DataType QueueByTwoStackFront(QueueByTwoStack* pq)
{
	assert(pq);
	Stack*p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	int data;
	if (StackEmpty(p2) == 0)
	{
		while (StackEmpty(p1) != 0)
		{
			data = StackTop(p1);
			StackPop(p1);
			StackPush(p2, data);
		}
	}
	return StackTop(p2);
}
DataType QueueByTwoStackBack(QueueByTwoStack* pq)
{
	assert(pq);
	Stack*p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	return StackTop(p1);
}

//0Îª¿Õ
//1Îª·Ç¿Õ
int QueueByTwoStackEmpty(QueueByTwoStack* pq)
{
	assert(pq);
	Stack*p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	if ((p1->_top == 0) && (p2->_top == 0))
	{
		return 0;
	}
	else
		return 1;
}
int QueueByTwoStackSize(QueueByTwoStack* pq)
{
	assert(pq);
	Stack*p1, *p2;
	p1 = &(pq->s1);
	p2 = &(pq->s2);
	return (p1->_top) + (p2->_top);
}