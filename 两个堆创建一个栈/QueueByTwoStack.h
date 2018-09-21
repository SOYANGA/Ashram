#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "Stack.h"
#include "Queue.h"

//����ջ��ģ��ʵ�ֶ���
typedef struct QueueByTwoStack
{
	Stack s1;//�����
	Stack s2;//������
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
//˼ά:
//ֻȷ��һ��ջר����Ϊ���е�Push(s1),��һ��ר����Ϊ���е�Pop(s2),ʵ��"�����ȳ�"
//eg:������Pop(������ͷ)=>�����(Push)
//"����е�ջ":1 2 3 4 ->   ->       ->Push->5     ->   ->5     ->   ->5   ->   ->5->   ->5  ->   ->  ->NULL    
//"�����е�ջ":        ->Pop->4 3 2 1->Pop ->4 3 2 ->Pop->4 3 2 ->Pop->4 3 ->Pop->4->Pop->   ->Pop->5 ->NULL   