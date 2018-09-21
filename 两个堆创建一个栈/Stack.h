#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __STACk_H__
#define __STACk_H__
#include <stdio.h>
#include <string.h>
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
# endif //__STACK_H__

