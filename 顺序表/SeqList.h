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


void InintSeqList(PSeqList pSeq);//��ʼ�� 

void PushBack(PSeqList pSeq, DataType data);//β������ 
 
void PopBack(PSeqList pSeq);//β��ɾ��

void PushFront(PSeqList pSeq, DataType data);//ͷ������ 
 
void PopFront(PSeqList pSeq);//ͷ��ɾ��

int Find(PSeqList pSeq, DataType data);//����ָ��Ԫ�� 

void Insert(PSeqList pSeq, int pos, DataType data);//ָ��λ�ò��� 

void Erase(PSeqList pSeq, int pos);//ɾ��ָ��λ��Ԫ�� 

void Remove(PSeqList pSeq, DataType data);//ɾ��ָ��Ԫ�� 
 
void RemoveAll(PSeqList pSeq, DataType data);//ɾ�����е�ָ��Ԫ��

int Size(PSeqList pSeq);//����˳���Ĵ�С 

int Empty(PSeqList pSeq);//�ж�˳����Ƿ�Ϊ��   Ϊ�շ���0 �ǿշ���1
 
void BubbleSort(PSeqList pSeq);//ð������

void SelectSort(PSeqList pSeq);//ѡ������ 

void SelectSort_OP(PSeqList pSeq);//ѡ��������Ż� 

int BinarySearch(PSeqList pSeq, DataType data);//���ֲ��� 
 
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d);//���ֲ��ҵݹ�д��

void PrintSeqList(PSeqList pSeq);//��ӡ 

#endif //_SEQLIST_H__