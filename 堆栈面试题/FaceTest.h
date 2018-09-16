#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1.ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(������Сֵ)��ʱ�� ���Ӷ�ΪO(1)
////3.ʹ������ջʵ��һ������
////4.ʹ����������ʵ��һ��ջ
////5.Ԫ�س�ջ����ջ˳��ĺϷ��ԡ�����ջ������(1, 2, 3, 4, 5)����ջ����Ϊ(4, 5, 3, 2, 1)
//6.һ������ʵ������ջ(����ջ)
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
//5.�жϳ�ջ�Ϸ���
static DataType arry1[] = StackNumber;
static DataType arry2[] = StackTNumber;
void Test1();
int FindRightOrder();
///////////////////////////
//�жϳ�ջ�Ϸ���(�Ż���1)
int IsLegalStackOrder(int* in, int insize, int* out, int outsize);
void Test2();
///////////////////////////
//�жϳ�ջ�Ϸ��ԣ��Ż���2��
int IsLegalStackOrder_R(int* in, int insize, int* out, int outsize);
void Test3();
//˼·;
//һֱ��������˳����ջ.
//ֻҪ�����Ա�,���������ջ˳��ƥ��,��ͳ�ջ,��֮�򲻶�
//����ж�ջ�Ƿ�Ϊ�ռ����жϳ��Ƿ�Ϸ�.




