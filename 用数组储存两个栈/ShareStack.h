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
//˼ά:
//����"��żջ"�ķ����������д洢���ջ,�����±�Ϊ[����]��һ��ջ,�����±�Ϊ[ż��]�����ջ,��Ч������������Ŀռ�.