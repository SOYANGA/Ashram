#pragma once
//1.实现一个栈，要求实现Push(出栈)、Pop(入栈)、Min(返回最小值)的时间 复杂度为O(1)
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
//思维:
//利用"双栈"O(1)复杂度的数组,用一个栈存储元素,另一个栈存储最小值,最小值通过比较不断更新.
//(假如压栈一个比最小值大或等于的数, 则在stack _min中继续存储一个当前最小值, 防止重复存放最小值, 出栈时不好删除_min内的值)
//最优方法是创一个栈专门存储结构体(其中包含了当前最小值和压入最小值相同大小的次数)
//,只有最小值的次数为零或者出现比当前最小值还要小的数时更替最小值.