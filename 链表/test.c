#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"

void test()
{
	pList plist;
	InitList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintList(plist);
	//printf("%d\n", GetListLength(plist));
	//DestoryList(&plist);
	//printf("%d\n", GetListLength(plist));
	//PrintList(plist);
	PopBack(&plist);//1 2 3 4 
	PrintList(plist);
	PopBack(&plist);//1 2 3 4 
	PrintList(plist);
	PopBack(&plist);//1 2 3 4 
	PrintList(plist);
	PopBack(&plist);//1 2 3 4 
	PrintList(plist);
	PopBack(&plist);//1 2 3 4 
	PrintList(plist);
	PopBack(&plist);//1 2 3 4 
	PrintList(plist);//1 2 3 4 
	DestoryList(&plist);

}

void testPushFront()
{
	pList plist;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);
	DestoryList(&plist);
}
void testPopFront()
{
	pList plist;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);
	PopFront(&plist);
	PrintList(plist);
	PopFront(&plist);
	PrintList(plist);
	PopFront(&plist);
	PrintList(plist);
	PopFront(&plist);
	PrintList(plist);
	PopFront(&plist);
	PrintList(plist);
	DestoryList(&plist);
}
void testFind()
{
	pList plist;
	pNode pos = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);
	pos = Find(plist, 3);
	if (pos != NULL)
	{
		printf("%d\n", pos->data);
	}
	DestoryList(&plist);
}
void testInsert()
{
	pList plist;
	pNode pos = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);// 4 3 2 1
	pos = Find(plist, 4);
	if (pos != NULL)
	{
		Insert(&plist, pos, 5);
	}
	PrintList(plist);//4 5 3 2 1
	DestoryList(&plist);

}
void testErase()
{
	pList plist;
	pNode pos = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);// 4 3 2 1
	pos = Find(plist, 4);
	if (pos != NULL)
	{
		Erase(&plist, pos);
	}
	PrintList(plist);//3 2 1
	DestoryList(&plist);
}
void testRemove()
{
	pList plist;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 2);
	PrintList(plist);//2 4 3 2 1
	Remove(&plist, 2);// 4 3 2 1
	PrintList(plist);
	DestoryList(&plist);

}
void testRemoveAll()
{
	pList plist;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 2);
	PrintList(plist);//2 4 3 2 1
	RemoveAll(&plist, 2);// 4 3 2 1
	PrintList(plist);
	DestoryList(&plist);

}
void testPrintTailToHead()
{
	pList plist;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);// 4 3 2 1
	PrintTailToHead(plist);//1 2 3 4
	DestoryList(&plist);

}
void testEraseNotTailNode()
{
	pList plist;
	pNode pos = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);// 4 3 2 1
	pos = Find(plist, 3);
	if (pos != NULL)
	{
		EraseNotTailNode(pos);
	}
	PrintList(plist);//4 2 1
	DestoryList(&plist);
}

void testInsertNode()
{
	pList plist;
	pNode pos = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);// 4 3 2 1
	pos = Find(plist, 3);
	if (pos != NULL)
	{
		InsertNode(pos, 5);
	}
	PrintList(plist);//4  5 3 2 1
	DestoryList(&plist);
}

void testJosephusCircle()
{
	int i = 0;
	pNode plist = NULL;
	for (i = 1; i <= 41; i++)
	{
		PushBack(&plist, i);
	}
	PrintList(plist);
	//构成环
	Find(plist, 41)->next = plist;
	//
	JosephusCircle(&plist, 3);

}
void testReverseList()
{
	int i = 0;
	pNode plist = NULL;
	for (i = 1; i <= 5; i++)
	{
		PushBack(&plist, i);
	}
	PrintList(plist);// 1 2 3 4 5
	ReverseList(&plist);
	PrintList(plist);// 5 4 3 2 1

}
void testBubbleSort()
{
	int i = 0;
	pNode plist = NULL;
	for (i = 1; i <= 5; i++)
	{
		PushFront(&plist, i);
	}
	PrintList(plist);// 5 4 3 2 1
	BubbleSort(plist);
	PrintList(plist);// 1 2 3 4 5
}
void testMergeList()
{
	int i = 0;
	pNode plist1 = NULL;
	pNode plist2 = NULL;
	pNode newList = NULL;
	for (i = 2; i <= 6; i += 2)
	{
		PushBack(&plist1, i);
	}
	PrintList(plist1);//2 4 6
	for (i = 1; i <= 5; i += 2)
	{
		PushBack(&plist2, i);
	}
	PrintList(plist2);//1 3 5 
	newList = Merge_R(plist1, plist2);
	PrintList(newList);// 1 2 3 4 5 6 


}
void testFindMidNode()
{
	int i = 0;
	pNode plist = NULL;
	pNode pos = NULL;
	for (i = 1; i <= 5; i++)
	{
		PushFront(&plist, i);
	}
	PrintList(plist);// 5 4 3 2 1
	pos = FindMidNode(plist);
	if (pos != NULL)
		printf("中间结点是：%d ", pos->data);
}
void testFindLastKNode()
{
	int i = 0;
	pNode plist = NULL;
	pNode pos = NULL;
	for (i = 1; i <= 5; i++)
	{
		PushFront(&plist, i);
	}
	PrintList(plist);// 5 4 3 2 1
	pos = FindLastKNode(plist, 3);
	if (pos != NULL)
		printf("倒数第%d个结点是：%d ", 3, pos->data);
}
void testcircleList()
{
	int i = 0;
	pNode plist = NULL;
	pNode pos = NULL;
	int length = 0;
	pNode enter = NULL;
	for (i = 1; i <= 5; i++)
	{
		PushBack(&plist, i);
	}
	PrintList(plist);
	//构成环
	Find(plist, 5)->next = Find(plist, 3);
	pos = IsCircle(plist);
	length = GetCircleLength(pos);
	enter = GetCycleEntryNode(plist, pos);
	if (pos != NULL)
	{
		printf("存在环\n");
		printf("相遇点是：%d \n", pos->data);
		printf("环的长度是:%d \n", length);
		printf("环的入口点时：%d \n", enter->data);

	}
}
void testCheckCross()
{

	int i = 0;
	pNode plist1 = NULL;
	pNode plist2 = NULL;
	int n = 0;
	pNode cross = NULL;
	for (i = 2; i <= 9; i++)
	{
		PushBack(&plist1, i);
	}
	PrintList(plist1);//2 3 4 5 6 7 8 9
	for (i = 1; i <= 5; i += 2)
	{
		PushBack(&plist2, i);
	}
	Find(plist2, 5)->next = Find(plist1, 6);
	n = CheckCross(plist1, plist2);
	PrintList(plist2);//1 3 5 
	cross = GetCrossNode(plist1, plist2);
	if (n == 1)
	{
		printf("两条链表有交点\n");
		printf("交点是：%d \n", cross->data);
	}
	else
	{
		printf("两条链表没有交点\n");
	}

}
void testUnionSet()
{

	int i = 0;
	pNode plist1 = NULL;
	pNode plist2 = NULL;
	pNode cross = NULL;
	for (i = 2; i <= 9; i++)
	{
		PushBack(&plist1, i);
	}
	PrintList(plist1);//2 3 4 5 6 7 8 9
	for (i = 1; i <= 5; i += 2)
	{
		PushBack(&plist2, i);
	}
	Find(plist2, 5)->next = Find(plist1, 6);
	PrintList(plist2);//1 3 5 6 7 8 9
	UnionSet(plist1, plist2);


}
void testComplexNode()
{
	ComplexNode* plist = NULL;
	PushComplexlistBack(&plist, 5);
	PushComplexlistBack(&plist, 4);
	PushComplexlistBack(&plist, 3);
	PushComplexlistBack(&plist, 2);
	PushComplexlistBack(&plist, 1);
	plist->random = plist->next->next;
	plist->next->random = plist;
	plist->next->next->random = NULL;
	plist->next->next->next->random = plist->next;
	plist->next->next->next->next->random = plist->next->next->next;
	PrintComplexList(plist);
	CopyComplexList(plist);
	PrintComplexList(plist);



}

int main()
{
	//test();
	//testPushFront();
	//testPopFront();
	//testFind();
	//testInsert();
	//testErase();
	//testRemove();
	//testRemoveAll();
	//testPrintTailToHead();
	//testEraseNotTailNode();
	//testInsertNode();
	//testJosephusCircle();
	//testReverseList();
	//testBubbleSort();
	//testMergeList();
	//testFindMidNode();
	//testFindLastKNode();
	//testcircleList();
	//testCheckCross();
	//testUnionSet();
	testComplexNode();
	system("pause");
	return 0;
}
