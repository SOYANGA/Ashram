#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
typedef int SSDataType;
typedef struct ShareSack
{
	SSDataType* _arry;
	int Top1, Top2;
	int cacity;
}ShareSack;
void ShareSackInit(ShareSack* ps);
void ShareSackDestory(ShareSack* ps);

void ShareSackPush(ShareSack* ps, SSDataType x,int which);
void ShareSackPop(ShareSack* ps,int which);
SSDataType ShareSackTop(ShareSack* ps,int which);
int ShareSackEmpty(ShareSack* ps,int which);
int ShareSackSize(ShareSack* ps,int which);
void Test();
//思维:
//利用"奇偶栈"的方法在数组中存储另个栈,数组下标为[奇数]存一个栈,数组下标为[偶数]存另个栈,有效的利用了数组的空间.