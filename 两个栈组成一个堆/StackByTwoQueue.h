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
//思维:
//利用确定一个非空队列（q1,q2之间交换）Push到另一个队列，只留下队尾并且把队尾POp出去达到（“后入先出的目的”）。
//入栈的化，只入到非空队列里面
//eg:出栈4=>入栈5=>出栈
//非空队列：1 2 3 4        ——>      4      ->Pop    ->            ->      ->  1 2 3 ->   ->   1 2 3
//空 队列：                ——>      1 2 3  ->Push 5 ->   1 2 3 5  ->Ppp 5 ->  5     ->Pop->   
