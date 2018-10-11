/*************************************************************************
	> File Name: test.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年10月07日 星期日 22时49分39秒
 ************************************************************************/

#include"Seqlist.h"

void testBack()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PushBack(&seq,5);
	PrintSeqList(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
}
void testFront()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq,1);
	PushFront(&seq,2);
	PushFront(&seq,3);
	PushFront(&seq,4);
	PushFront(&seq,5);
	PushFront(&seq,6);
	PrintSeqList(&seq);
	PopFront(&seq);
	PopFront(&seq);
	PopFront(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
}
void testErase()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PushBack(&seq,5);
	Insert(&seq,5,6);
	PrintSeqList(&seq);
	Erase(&seq,5);
	PrintSeqList(&seq);
	Remove(&seq,2);
	PrintSeqList(&seq);
	PushBack(&seq,2);
	PushBack(&seq,2);
	PrintSeqList(&seq);
	RemoveAll(&seq,2);
	PrintSeqList(&seq);
}
void testSort()
{

	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq,1);
	PushFront(&seq,2);
	PushFront(&seq,3);
	PushFront(&seq,4);
	PushFront(&seq,5);
	PushFront(&seq,6);
	SelectSort(&seq);
	PrintSeqList(&seq);
	PushFront(&seq,1);
	PushFront(&seq,2);
	PushFront(&seq,3);
	PushFront(&seq,4);
	PushFront(&seq,5);
	PushFront(&seq,6);
	BubbleSort(&seq);
	PrintSeqList(&seq);
}
int main()
{
//	testBack();
//	testFront();
//	testErase();
	testSort();
	return 0;
}
