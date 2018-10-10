/*************************************************************************
	> File Name: Seqlist.h
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年10月07日 星期日 22时48分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


#define Max 100
typedef int DataType;

typedef struct SeqList
{
	DataType data[Max];
	int sz;
}SeqList,*pSepList;

void InitSeqList(pSepList pSeq);   //初始化
void PushBack(pSepList pSeq, DataType data);  //尾部插入
void PopBack(pSepList pSeq);//尾部删除
void PushFront(pSepList pSeq,DataType data);  //头插
void PopFront(pSepList pSeq);  //头删
int Find(pSepList pSeq, DataType data);  //查找
void Insert(pSepList pSeq,int pos, DataType data);  //指定位置插入

void Erase(pSepList pSeq, int pos);//删除指定位置元素
void Remove(pSepList pSeq,DataType data);//删除指定元素
void RemoveAll(pSepList pSeq, DataType data);//删除所有指定元素

int size(pSepList pSeq);//返回顺序表大小
int Empty(pSepList pSeq);//判断顺序表是否为空，空返回0 非空返还1

void BubbleSort(pSepList pSeq);//冒泡排序
void SelectSort(pSepList pSeq);//插排

int BinarySearch(pSepList pSeq, DataType data);//二分查找
int BinarySearch_R(pSepList pSeq, int left ,int right, DataType d);//二分查找 递归版

void PrintSeqList(pSepList pSeq);//打印
void test();
#endif  //-SEQLIST_H
