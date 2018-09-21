#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "Stack.h"
#include "Queue.h"

typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;
void StackByTwoQueueInit(StackByTwoQueue* ps);
void StackByTwoQueueDestory(StackByTwoQueue* ps);

void StackByTwoQueuePush(StackByTwoQueue* ps, DataType x);
void StackByTwoQueuePop(StackByTwoQueue* ps);
DataType StackByTwoQueueTop(StackByTwoQueue* ps);
DataType StackByTwoQueueBack(StackByTwoQueue* ps);


int StackByTwoQueueEmpty(StackByTwoQueue* ps);
int StackByTwoQueueSize(StackByTwoQueue* ps);
//˼ά:
//����ȷ��һ���ǿն��У�q1,q2֮�佻����Push����һ�����У�ֻ���¶�β���ҰѶ�βPOp��ȥ�ﵽ���������ȳ���Ŀ�ġ�����
//��ջ�Ļ���ֻ�뵽�ǿն�������
//eg:��ջ4=>��ջ5=>��ջ
//�ǿն��У�1 2 3 4        ����>      4      ->Pop    ->            ->      ->  1 2 3 ->   ->   1 2 3
//�� ���У�                ����>      1 2 3  ->Push 5 ->   1 2 3 5  ->Ppp 5 ->  5     ->Pop->   
