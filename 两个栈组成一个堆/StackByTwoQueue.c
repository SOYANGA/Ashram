#define _CRT_SECURE_NO_WARNINGS 1
#include "StackByTwoQueue.h"
void StackByTwoQueueInit(StackByTwoQueue* ps)
{
	assert(ps);
	Queue* pq1, *pq2;
	pq1 = &(ps->q1);
	pq2 = &(ps->q2);
	pq1->_front = NULL;
	pq1->_back = NULL;
	pq2->_front = NULL;
	pq2->_back = NULL;
}
void StackByTwoQueueDestory(StackByTwoQueue* ps)
{
	assert(ps);
	Queue* pq1, *pq2;
	pq1 = &(ps->q1);
	pq2 = &(ps->q2);
	QueueNode* cur = pq1->_front;
	while (cur != NULL)
	{
		QueueNode* del = cur;
		cur = cur->_next;
		free(del);
	}
	pq1->_front = NULL;
}

//认定 pq1或inqueue为非空栈
//
void returnback(Queue**pq1,Queue**pq2)
{
	Queue *tmp;
	if ((*pq1)->_front == NULL)
	{
		tmp =*pq1;
		*pq1 = *pq2;
		*pq2 = tmp;
	}
}
//Queue* inqueue, *nonequeue;
void StackByTwoQueuePush(StackByTwoQueue* ps, DataType x)
{
	assert(ps);
	Queue* pq1, *pq2;
	pq1 = &(ps->q1);
	pq2 = &(ps->q2);
	QueuePush(pq1, x);
}
void StackByTwoQueuePop(StackByTwoQueue* ps)
{
	assert(ps);
	Queue* pq1, *pq2;
	pq1 = &(ps->q1);
	pq2 = &(ps->q2);
	int data;
	//if (pq1->_front == NULL)
	//{
	//	inqueue = pq1;
	//	nonequeue = pq2;
	//}
	//else
	//{
	//	inqueue = pq2;
	//	nonequeue = pq1;
	//}
	returnback(&pq1, &pq2);
	while (pq1->_front != pq1->_back)
	{
		data = QueueFront(pq1);
		QueuePop(pq1);
		QueuePush(pq2, data);
	}
	QueuePop(pq1);
}
DataType StackByTwoQueueTop(StackByTwoQueue* ps)
{
	assert(ps);
	Queue* pq1, *pq2;
	pq1 = &(ps->q1);
	pq2 = &(ps->q2);
	//if (pq1->_front == NULL)
	//{
	//	inqueue = pq1;
	//	nonequeue = pq2;
	//}
	//else
	//{
	//	inqueue = pq2;
	//	nonequeue = pq1;
	//}
	returnback(&pq1, &pq2);
	return pq1->_back->_data;
}
DataType StackByTwoQueueBack(StackByTwoQueue* ps)
{
	assert(ps);
	Queue* pq1, *pq2;
	pq1 = &(ps->q1);
	pq2 = &(ps->q2);
	//if (pq1->_front == NULL)
	//{
	//	inqueue = pq1;
	//	nonequeue = pq2;
	//}
	//else
	//{
	//	inqueue = pq2;
	//	nonequeue = pq1;
	//}
	returnback(&pq1, &pq2);
	return pq1->_front->_data;
}

//空为0
//非空为1
int StackByTwoQueueEmpty(StackByTwoQueue* ps)
{
	assert(ps);
	Queue* pq1, *pq2;
	pq1 = &(ps->q1);
	pq2 = &(ps->q2);
	if (pq1->_front == NULL&&pq1->_front == pq2->_front)
		return 0;
	else
		return 1;

}
int StackByTwoQueueSize(StackByTwoQueue* ps)
{
	assert(ps);
	Queue* pq1, *pq2;
	pq1 = &(ps->q1);
	pq2 = &(ps->q2);
	int size1 = 0;
	int size2 = 0;
	QueueNode* cur1 = pq1->_front;
	QueueNode* cur2 = pq2->_front;
	while (cur1)
	{
		size1++;
		cur1 = cur1->_next;
	}
	while (cur2)
	{
		size2++;
		cur2 = cur2->_next;
	}
	return (size1 + size2);

}