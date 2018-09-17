#define _CRT_SECURE_NO_WARNINGS 1
#pragma once 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* _next;
	struct ListNode* _prev;
	LTDataType _data;
}ListNode;

typedef struct List
{
	struct ListNode* _head;
}List;

void ListInit(List* lt);
void ListDestory(List* lt);
void ListPushBack(List* lt, LTDataType x);
void ListPushFront(List* lt, LTDataType x);
void ListPopBack(List* lt);
void ListPopFront(List* lt);

ListNode* BuyListNode(LTDataType x);
ListNode* ListFind(List* lt, LTDataType x);

void ListInsert(ListNode* pos, LTDataType x);
void ListErase(List*lt,ListNode* pos);
int ListSize(List* lt);
int ListEmpty(List* lt);
void ListPrint(List* lt);
//1.�ȳ�ʼ��
//2.��������
//3.Ȼ��������
//4.��дɾ��
//���д����
//�����������дͷ��β��
//ɾ����������дͷɾβɾ