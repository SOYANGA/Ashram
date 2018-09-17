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
//1.先初始化
//2.再做插入
//3.然后再销毁
//4.再写删除
//最后写其他
//插入可以用来写头插尾插
//删除可以用来写头删尾删