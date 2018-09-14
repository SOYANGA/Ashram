#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
//typedef int DataType;
typedef  int  DataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front; //∂”Õ∑
	QueueNode* _back;  //∂”Œ≤
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(DataType x);

void QueuePush(Queue* pq, DataType x);
void QueuePop(Queue* pq);
DataType QueueFront(Queue* pq);
DataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

#endif // __QUEUE_H__