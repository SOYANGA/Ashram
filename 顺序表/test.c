#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void test()
{
	SeqList seq;//int
	InintSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);


}
void testPushFront()
{
	SeqList seq;//int
	InintSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);



}
void testPopFront()
{
	SeqList seq;//int
	InintSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
}
void testfind()
{
	SeqList seq;//int
	int pos = 0;
	InintSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	pos = Find(&seq, 3);
	if (pos == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标是：%d\n", pos);
	}
}
void testInsert()
{
	SeqList seq;//int
	int pos = 0;
	InintSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	pos = Find(&seq, 3);
	if (pos != -1)
	{
		//指定位置前面插入
		Insert(&seq, pos, 5);
	}
	PrintSeqList(&seq);
}
void testErase()
{
	SeqList seq;//int
	int pos = 0;
	InintSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	pos = Find(&seq, 3);
	if (pos != -1)
	{
		//指定位置前面插入
		Erase(&seq, pos);
	}
	PrintSeqList(&seq);
}
void testRemove()
{
	SeqList seq;//int
	InintSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PrintSeqList(&seq);
	Remove(&seq, 2);
	PrintSeqList(&seq);
}
void testRemoveAll()
{
	SeqList seq;//int
	InintSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PrintSeqList(&seq);
	RemoveAll(&seq, 2);
	PrintSeqList(&seq);
	if (!Empty(&seq))
	{
		printf("顺序表共有%d个元素\n", Size(&seq));
	}
}
void testBubbleSor()
{
	SeqList seq;//int
	int i = 0;
	InintSeqList(&seq);
	for (i = 0; i < 10; i++)
	{
		PushFront(&seq, i);
	}
	PrintSeqList(&seq);
	BubbleSort(&seq);
	PrintSeqList(&seq);

}
void testSelectSort()
{
	SeqList seq;//int
	int i = 0;
	InintSeqList(&seq);
	for (i = 0; i < 10; i++)
	{
		PushFront(&seq, i);
	}
	PrintSeqList(&seq);
	SelectSort_OP(&seq);
	PrintSeqList(&seq);
}
void testBinarySearch()
{
	SeqList seq;//int
	int i = 0;
	int pos = 0;
	InintSeqList(&seq);
	for (i = 0; i < 10; i++)
	{
		PushFront(&seq, i);
	}
	SelectSort_OP(&seq);
	PrintSeqList(&seq);
	//pos = BinarySearch(&seq,6);
	pos = BinarySearch_R(&seq,0,seq.sz-1,6);
	if (pos != -1)
	{
		printf("下标是：%d\n", pos);
	}
	else
	{
		printf("找不到!\n");
	}
}


int main()
{
	//test();
	//testPushFront();
	//testPopFront();
	//testfind();
	//testInsert();
	//testErase();
	//testRemove();
	//testRemoveAll();
	//testBubbleSor();
	//testSelectSort();
	testBinarySearch();
	system("pause");
	return 0;
}