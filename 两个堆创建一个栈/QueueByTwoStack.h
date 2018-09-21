#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "Stack.h"
#include "Queue.h"

//两个栈的模拟实现队列
typedef struct QueueByTwoStack
{
	Stack s1;//入队列
	Stack s2;//出队列
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* pq);
void QueueByTwoStackDestory(QueueByTwoStack* pq);

//QueueNode* BuyQueueByTwoStackNode(DataType x);

void QueueByTwoStackPush(QueueByTwoStack* pq, DataType x);
void QueueByTwoStackPop(QueueByTwoStack* pq);
DataType QueueByTwoStackFront(QueueByTwoStack* pq);
DataType QueueByTwoStackBack(QueueByTwoStack* pq);
int QueueByTwoStackEmpty(QueueByTwoStack* pq);
int QueueByTwoStackSize(QueueByTwoStack* pq);
//思维:
//只确定一个栈专门作为队列的Push(s1),另一个专门作为队列的Pop(s2),实现"先入先出"
//eg:出队列Pop(出队列头)=>入队列(Push)
//"入队列的栈":1 2 3 4 ->   ->       ->Push->5     ->   ->5     ->   ->5   ->   ->5->   ->5  ->   ->  ->NULL    
//"出队列的栈":        ->Pop->4 3 2 1->Pop ->4 3 2 ->Pop->4 3 2 ->Pop->4 3 ->Pop->4->Pop->   ->Pop->5 ->NULL   