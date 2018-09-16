#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1.实现一个栈，要求实现Push(出栈)、Pop(入栈)、Min(返回最小值)的时间 复杂度为O(1)
////3.使用两个栈实现一个队列
////4.使用两个队列实现一个栈
////5.元素出栈、入栈顺序的合法性。如入栈的序列(1, 2, 3, 4, 5)，出栈序列为(4, 5, 3, 2, 1)
//6.一个数组实现两个栈(共享栈)
#define StackNumber  {1,2,3,4,5}
#define StackTNumber {5,3,1,2,4}
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


////////////////////////////
//5.判断出栈合法性
static DataType arry1[] = StackNumber;
static DataType arry2[] = StackTNumber;
void Test1();
int FindRightOrder();
///////////////////////////
//判断出栈合法性(优化版1)
int IsLegalStackOrder(int* in, int insize, int* out, int outsize);
void Test2();
///////////////////////////
//判断出栈合法性（优化版2）
int IsLegalStackOrder_R(int* in, int insize, int* out, int outsize);
void Test3();
//思路;
//一直按给出的顺序入栈.
//只要经过对比,与出给出的栈顺序匹配,则就出栈,反之则不动
//最后判断栈是否为空即可判断出是否合法.




