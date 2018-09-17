#define _CRT_SECURE_NO_WARNINGS 1
#include "DoubleList.h"
void ListInit(List* lt)
{
	assert(lt);
	lt->_head = BuyListNode(0);
	lt->_head->_next = lt->_head;
	lt->_head->_prev = lt->_head;

}
void ListDestory(List* lt)
{
	assert(lt);
	ListNode*cur = lt->_head;
	while (cur !=lt->_head)
	{
		ListNode* del = cur;
		free(del);
		cur = cur->_next;
	}
	free(lt->_head);
	lt->_head = NULL;
}

void ListPushBack(List* lt, LTDataType x)
{
	ListInsert(lt->_head, x);
}
void ListPushFront(List* lt, LTDataType x)
{
	ListInsert(lt->_head->_next, x);
}
void ListPopBack(List* lt)
{
	ListErase(lt,lt->_head->_prev);
}

void ListPopFront(List* lt)
{
	ListErase(lt, lt->_head->_next);
}
ListNode* BuyListNode(LTDataType x)
{
	ListNode* NewNode = NULL;
	NewNode = (ListNode*)malloc(sizeof(ListNode));
	NewNode->_data = x;
	return NewNode;
}
ListNode* ListFind(List* lt, LTDataType x)
{
	assert(lt);
	ListNode*cur = lt->_head->_next;
	while (cur != lt->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
//在pos前面插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode*NewNode = BuyListNode(x);
	ListNode* prev = pos->_prev;
	prev->_next = NewNode;
	NewNode->_prev = prev;
	NewNode->_next = pos;
	pos->_prev = NewNode;
}
void ListErase(List*lt, ListNode* pos)
{
	assert(pos);
	ListNode*prev = pos->_prev;
	ListNode*next = pos->_next;
	if (pos == lt->_head)
	{
		printf("链表为空，不需要删除！\n");
		return;
	}
	free(pos);
	pos = NULL;
	prev->_next = next;
	next->_prev = prev;
}
int ListSize(List* lt)
{
	assert(lt);
	ListNode*cur = lt->_head->_next;
	int count = 0;
	while (cur != lt->_head)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
//空为0
//非空为1
int ListEmpty(List* lt)
{
	assert(lt);
	return (lt->_head != lt->_head->_next);
}
void ListPrint(List* lt)
{
	assert(lt);
	ListNode* cur = lt->_head->_next;
	while (cur != lt->_head)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
}