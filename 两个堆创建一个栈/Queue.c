#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_back = NULL;
	pq->_front = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur != NULL)
	{
		QueueNode* del = cur;
		cur = cur->_next;
		free(del);
	}
	pq->_front = NULL;
}

QueueNode* BuyQueueNode(DataType x)
{
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (NewNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	NewNode->_data = x;
	NewNode->_next = NULL;
	return NewNode;
}

void QueuePush(Queue* pq, DataType x)
{
	assert(pq);
	if (pq->_back == NULL)  //空队列尾部添加元素
	{
		pq->_front = pq->_back = BuyQueueNode(x);
	}
	else                    //非空队列
	{
		QueueNode* back = BuyQueueNode(x);
		pq->_back->_next = back;
		pq->_back = back;
	}
}
void Queuepop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
}
DataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_front->_data;
}
//空为0
//非空为1
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL ? 0 : 1;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->_front;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}