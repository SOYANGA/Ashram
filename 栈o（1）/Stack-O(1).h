#pragma once
//1.ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(������Сֵ)��ʱ�� ���Ӷ�ΪO(1)
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
typedef int DataType;
typedef struct Stack
{
	DataType* _a;
	int _top;
	int _capcity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, DataType x);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
//////////////////////////////
//
typedef int DataMinType;
typedef struct MinStack
{
	Stack _st;
	Stack _min;
}MinStack;
void StackMinInit(MinStack* ps);
void StackMinDestory(MinStack* ps);
void StackMinPush(MinStack* ps, DataType x);
void StackMinPop(MinStack* ps);
DataMinType StackMinTop(MinStack* ps);

void Test();
//˼ά:
//����"˫ջ"O(1)���Ӷȵ�����,��һ��ջ�洢Ԫ��,��һ��ջ�洢��Сֵ,��Сֵͨ���Ƚϲ��ϸ���.
//(����ѹջһ������Сֵ�����ڵ���, ����stack _min�м����洢һ����ǰ��Сֵ, ��ֹ�ظ������Сֵ, ��ջʱ����ɾ��_min�ڵ�ֵ)
//���ŷ����Ǵ�һ��ջר�Ŵ洢�ṹ��(���а����˵�ǰ��Сֵ��ѹ����Сֵ��ͬ��С�Ĵ���)
//,ֻ����Сֵ�Ĵ���Ϊ����߳��ֱȵ�ǰ��Сֵ��ҪС����ʱ������Сֵ.