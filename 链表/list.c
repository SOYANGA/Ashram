#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}
void InitList(pList*pplist)
{
	assert(pplist);
	*pplist = NULL;
}
void DestoryList(pList*pplist)
{
	pNode cur = NULL;
	assert(pplist);
	cur = *pplist;
	while (cur != NULL)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
	}
	*pplist = NULL;
}
void PrintList(pList plist)
{
	pNode cur = plist;
	while (cur != NULL)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
int GetListLength(pList plist)
{
	pNode cur = plist;
	int count = 0;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
void PushBack(pList*pplist, DataType d)
{
	pNode newNode = BuyNode(d);
	assert(pplist);
	//空链表
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		pNode cur = *pplist;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
void PopBack(pList* pplist)
{
	assert(pplist);

	if (*pplist == NULL)//没有结点
	{
		printf("链表为空无法尾部删除！");
		return;
	}
	if ((*pplist)->next == NULL)//一个结点
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		pNode cur = *pplist;
		pNode prev = NULL;
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		prev->next = NULL;
	}
	//else//1个以上结点
	//{
	//	pNode cur = *pplist;
	//	while (cur->next->next != NULL)
	//	{
	//		cur = cur->next;
	//	}
	//	free(cur->next);
	//	cur->next = NULL;
	//}
}
void PushFront(pList* pplist, DataType d)
{
	pNode newNode = NULL;
	assert(pplist);
	newNode = BuyNode(d);
	newNode->next = *pplist;
	*pplist = newNode;
}
void PopFront(pList* pplist)
{
	assert(pplist);
	if (*pplist == NULL)//没有结点
	{
		printf("链表为空无法头部删除！\n");
		return;
	}
	else
	{
		pNode del = *pplist;
		*pplist = del->next;
		free(del);
		del = NULL;
	}
}
pNode Find(pList plist, DataType d)
{
	pNode cur = plist;
	while (cur)
	{
		if (cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void Insert(pList* pplist, pNode pos, DataType d)//插入
{
	pNode newNode = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);
	if (pos == *pplist)
	{
		//newNode = BuyNode(d);
		//PushFront(pplist, d);
		newNode = BuyNode(d);
		newNode->next = *pplist;
		*pplist = newNode;
	}
	else
	{
		pNode cur = *pplist;
		while (cur&&cur->next != pos)
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			newNode = BuyNode(d);
			newNode->next = pos;
			cur->next = newNode;
		}
	}
}
void Erase(pList* pplist, pNode pos)
{
	assert(pplist);
	assert(pos);
	if (*pplist == NULL)
	{
		return;
	}
	if (pos == *pplist)
	{
		//头删
		pNode del = pos;
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	else
	{
		pNode cur = *pplist;
		while (cur&&cur->next != pos)
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			cur->next = pos->next;
			free(pos);
			pos = NULL;
		}
	}

}
void Remove(pList* pplist, DataType d)
{
	pNode cur = NULL;
	pNode prev = NULL;
	assert(pplist);
	cur = *pplist;
	while (cur)
	{
		if (cur->data == d)
		{
			if (*pplist == cur)//第一个结点
			{
				pNode del = *pplist;
				*pplist = del->next;
				free(del);
				del = NULL;
			}
			else//非第一个结点
			{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
			}
			return;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}

}
//void Remove(pList* pplist, DataType d)
//{
//	assert(pplist);
//	pNode pos = Find(*pplist, d);
//	if (pos != NULL)
//	{
//		Erase(pplist,pos);
//	}
//
//}
void RemoveAll(pList* pplist, DataType d)
{
	pNode cur = NULL;
	pNode prev = NULL;
	assert(pplist);
	cur = *pplist;
	while (cur)
	{
		if (cur->data == d)
		{
			if (*pplist == cur)//第一个结点
			{
				pNode del = *pplist;
				*pplist = del->next;
				free(del);
				del = NULL;
				cur = *pplist;
			}
			else//非第一个结点
			{
				prev->next = cur->next;
				free(cur);
				cur = prev;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
//逆序打印单向链表
//1.递归
//void PrintTailToHead(pList plist)
//{
//	if (plist == NULL)
//	{
//		return;
//	}
//	PrintTailToHead(plist->next);
//	printf("%d<- ", plist->data);
//}
//2.非递归
void PrintTailToHead(pList plist)
{
	pNode cur = plist;
	pNode tail = NULL;
	if (plist == NULL)
	{
		return;
	}
	if (plist->next == NULL)
	{
		printf("%d <-", plist->data);
		return;
	}
	//while (plist != tail)
	//{
	//	if (cur->next == tail)
	//	{
	//		printf("%d<- ", cur->data);
	//		tail = cur;
	//		cur = plist;
	//	}
	//	else
	//		cur = cur->next;
	//}
	while (plist != tail)
	{
		cur = plist;
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		printf("%d<- ", cur->data);
		tail = cur;
	}
}
//删除一个无头单链表的非尾结点
//替换删除法
void EraseNotTailNode(pNode pos)
{
	pNode del = NULL;
	assert(pos != NULL);
	assert(pos->next != NULL);
	//移动数据
	del = pos->next;
	pos->data = pos->next->data;
	//删除下一个结点
	pos->next = del->next;
	free(del);
	del = NULL;
}
//在一个无头单链表前的插入一个结点（不遍历链表）
//1.创建结点前交换数据
void InsertNode(pNode pos, DataType d)
{
	pNode newNode = NULL;
	assert(pos);
	//交换数据
	newNode = BuyNode(pos->data);
	pos->data = d;
	//插入
	newNode->next = pos->next;
	pos->next = newNode;

}
//2.交换数据
//void InsertNode(pNode pos, DataType d)
//{
//	pNode newNode = NULL;
//	DataType tmp = 0;
//	assert(pos);
//	newNode = BuyNode(d);
//	//交换数据
//	tmp = newNode->data;
//	newNode->data = pos->data;
//	pos->data = tmp;
//	//插入
//	newNode->next = pos->next;
//	pos->next = newNode;
//
//}
void JosephusCircle(pList* pplist, int k)
{
	pNode cur = *pplist;
	while (cur != cur->next->next)
	{
		int count = k;
		pNode del = NULL;
		while (--count)
		{
			cur = cur->next;
		}
		printf("删除：%d\n", cur->data);
		cur->data = cur->next->data;
		del = cur->next;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("幸存者：%d\n", cur->data);
	printf("幸存者：%d\n", cur->next->data);

}
//逆置/反转单链表
//1.
//void ReverseList(pList*pplist)
//{
//	pNode n1, n2, n3;
//	assert(pplist != NULL);
//	if (*pplist == NULL)
//	{
//		return;
//	}
//	if ((*pplist)->next == NULL)
//	{
//		return;
//	}
//	n1 = *pplist;
//	n2 = n1->next;
//	n3 = n2->next;
//	while (n2)
//	{
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if (n3 != NULL)
//			n3 = n3->next;
//	}
//	(*pplist)->next = NULL;
//	*pplist = n1;
//}
//2.
void ReverseList(pList*pplist)
{
	pNode cur = NULL;
	pNode tmp = NULL;
	pNode head = NULL;
	assert(pplist);
	if (*pplist == NULL)
	{
		return;
	}
	if ((*pplist)->next == NULL)
	{
		return;
	}
	cur = *pplist;
	tmp = cur->next;
	while (cur != NULL)
	{
		cur->next = head;
		head = cur;
		cur = tmp;
		if (tmp != NULL)
			tmp = tmp->next;
	}
	*pplist = head;
}
void BubbleSort(pList plist)
{
	pNode cur = plist;
	pNode next = cur->next;
	pNode tail = NULL;
	int flag = 0;
	if (plist == NULL || (plist->next == NULL))
	{
		return;
	}
	while (plist != tail)
	{
		cur = plist;
		next = cur->next;
		while (next != tail)
		{
			if (cur->data > next->data)
			{
				DataType tmp = 0;
				tmp = cur->data;
				cur->data = next->data;
				next->data = tmp;
				flag = 1;
			}
			cur = next;
			next = cur->next;
		}
		tail = cur;
		if (flag == 0)
		{
			return;
		}
	}

}

pList Merge(pList p1, pList p2)
{
	pList newlist = NULL;
	pList cur = NULL;
	if (p1 == p2)
	{
		return p1;
	}
	if (p1 == NULL)
	{
		return p2;
	}
	if (p2 == NULL)
	{
		return p1;
	}

	if (p1->data > p2->data)
	{
		newlist = p2;
		p2 = p2->next;
	}
	else
	{
		newlist = p1;
		p1 = p1->next;
	}
	cur = newlist;
	while (p1 != NULL&&p2 != NULL)
	{
		if (p1->data > p2->data)
		{
			PushBack(&(cur), p2->data);
			p2 = p2->next;
		}
		else
		{
			PushBack(&(cur), p1->data);
			p1 = p1->next;
		}
	}
	if (p1 == NULL)
	{
		cur->next = p2;
	}
	else
	{
		cur->next = p1;
	}
	return newlist;
}
pNode Merge_R(pList p1, pList p2)
{
	pList newlist = NULL;
	if (p1 == p2)
	{
		return p1;
	}
	if (p1 == NULL)
	{
		return p2;
	}
	if (p2 == NULL)
	{
		return p1;
	}
	if (p1->data < p2->data)
	{
		newlist = p1;
		newlist->next = Merge_R(p1->next, p2);
	}
	else
	{
		newlist = p2;
		newlist->next = Merge_R(p1, p2->next);
	}
	return newlist;
}

pNode FindMidNode(pList plist)
{
	pNode fast = NULL;
	pNode slow = NULL;
	if (plist == NULL || (plist->next == NULL))
	{
		return NULL;
	}
	fast = plist;
	slow = plist;
	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
pNode FindLastKNode(pList plist, int k)
{
	pNode fast = NULL;
	pNode slow = NULL;
	if (plist == NULL)
	{
		return NULL;
	}
	fast = plist;
	slow = plist;
	while (k--)
	{
		fast = fast->next;
		if (fast == NULL)
			return NULL;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
pNode IsCircle(pList plist)
{
	pNode fast = NULL;
	pNode slow = NULL;
	if (plist == NULL)
	{
		return NULL;
	}
	slow = plist;
	fast = plist;
	slow = slow->next;
	if (fast != NULL&&fast->next != NULL)
		fast = fast->next->next;
	while (fast != slow)
	{
		slow = slow->next;
		if (fast != NULL&&fast->next != NULL)
			fast = fast->next->next;
		if (fast == NULL)
		{
			return NULL;
		}
	}
	return slow;
}
int GetCircleLength(pNode meet)
{
	pNode cur = meet->next;
	int count = 1;
	if (meet == NULL)
	{
		return 0;
	}
	while (cur != meet)
	{
		count++;
		cur = cur->next;
	}
	return count;

}
pNode GetCycleEntryNode(pList plist, pNode meet)//x+y=kl-y(入口点)推出来
{
	pNode cur = NULL;
	if (plist == NULL)
	{
		return NULL;
	}
	if (meet == NULL)
	{
		return NULL;
	}
	cur = plist;
	while (cur != meet)
	{
		cur = cur->next;
		meet = meet->next;
	}
	return cur;
}
int CheckCross(pList p1, pList p2)
{
	if (p1 == NULL || p2 == NULL)
	{
		return 0;
	}
	while (p1 != NULL)
	{
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		p2 = p2->next;
	}
	return p1 == p2;
}
pNode GetCrossNode(pList p1, pList p2)
{
	pNode list1 = NULL;
	pNode list2 = NULL;
	int count1 = 0;
	int count2 = 0;
	int gab = 0;
	list1 = p1;//长
	list2 = p2;//短
	while (p1 != NULL)
	{
		p1 = p1->next;
		count1++;
	}
	while (p2 != NULL)
	{
		p2 = p2->next;
		count2++;
	}
	gab = abs(count1 - count2);

	if (count1 <= count2)
	{
		list1 = p2;
		list2 = p1;
	}
	while (gab--)
	{
		list1 = list1->next;
	}
	while (list1 != list2)
	{
		list1 = list1->next;
		list2 = list2->next;
	}
	return list1;

}
void UnionSet(pList p1, pList p2)
{
	if (p1 == NULL || p2 == NULL)
	{
		return;
	}
	while (p1 != NULL&&p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			p1 = p1->next;
		}
		if (p1->data>p2->data)
		{
			p2 = p2->next;
		}
		else
		{
			printf("相同元素有：%d \n", p1->data);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	return;
}


//复杂链表的结点创建
ComplexNode* BuyComplexNode(DataType x)
{
	ComplexNode* node = (ComplexNode*)malloc(sizeof(ComplexNode));
	assert(node);
	node->next = NULL;
	node->random = NULL;
	node->data = x;
	return node;
}
//复杂链表的打印
void PrintComplexList(ComplexNode* plist)
{
	if (plist == NULL)
	{
		printf("复杂链表空，无法删除！\n");
		return;
	}
	while (plist != NULL)
	{
		if (plist->random == NULL)
		{
			printf("%d->(NULL)->", plist->data);
		}
		else
		{
			printf("%d->(%d)->", plist->data, plist->random->data);
		}
		plist = plist->next;
	}
	printf("over\n");
}
void PushComplexlistBack(ComplexNode**pplist, DataType d)
{
	ComplexNode * newNode = BuyComplexNode(d);
	assert(pplist);
	//空链表
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		ComplexNode* cur = *pplist;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
ComplexNode* CopyComplexList(ComplexNode* plist)
{
	ComplexNode *cur = NULL;
	ComplexNode *next = NULL;
	ComplexNode *newNode= NULL;
	ComplexNode *end = NULL;
	if (plist == NULL)
	{
		printf("复杂链表为空,无法复制\n");
		return NULL;
	}
	cur = plist;
	next = cur->next;
	//1.每个结点后面带上自己
	while (cur != NULL)
	{
		newNode = BuyComplexNode(cur->data);
		newNode->next = next;
		cur->next = newNode;
		cur = next;
		if (cur != NULL)
			next = cur->next;
	}
	//2.调整插入节点的random指针
	cur = plist;
	next = cur->next;
	while (cur != NULL)
	{
		if (cur->random != NULL)
		{
			next->random = cur->random;
		}
		cur = next->next;
		if (cur != NULL)
		{
			next = cur->next;
		}
	}
	//3.拆除链表
	cur = plist->next;
	end = plist->next;
	while (cur!=NULL)
	{
		if (cur ->next != NULL)
		{
			plist->next = cur->next;
			cur->next = cur->next->next;
		}
		if (cur->next == NULL)
		{
			plist->next = cur->next;
			cur->next = plist->next;
		}
		plist = plist->next;
		cur = cur->next;
	}
	newNode = end;
	return newNode;
}




