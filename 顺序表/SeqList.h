#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _SEQLIST_H__
#define _SEQLIST_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];
	int sz;
}SeqList, *PSeqList;


void InintSeqList(PSeqList pSeq);//初始化 

void PushBack(PSeqList pSeq, DataType data);//尾部插入 
 
void PopBack(PSeqList pSeq);//尾部删除

void PushFront(PSeqList pSeq, DataType data);//头部插入 
 
void PopFront(PSeqList pSeq);//头部删除

int Find(PSeqList pSeq, DataType data);//查找指定元素 

void Insert(PSeqList pSeq, int pos, DataType data);//指定位置插入 

void Erase(PSeqList pSeq, int pos);//删除指定位置元素 

void Remove(PSeqList pSeq, DataType data);//删除指定元素 
 
void RemoveAll(PSeqList pSeq, DataType data);//删除所有的指定元素

int Size(PSeqList pSeq);//返回顺序表的大小 

int Empty(PSeqList pSeq);//判断顺序表是否为空   为空返回0 非空返回1
 
void BubbleSort(PSeqList pSeq);//冒泡排序

void SelectSort(PSeqList pSeq);//选择排序 

void SelectSort_OP(PSeqList pSeq);//选择排序的优化 

int BinarySearch(PSeqList pSeq, DataType data);//二分查找 
 
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d);//二分查找递归写法

void PrintSeqList(PSeqList pSeq);//打印 

#endif //_SEQLIST_H__