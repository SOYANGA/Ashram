#define _CRT_SECURE_NO_WARNINGS 1
#ifndef  _LINKLIST_H_
#define  _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

typedef int DataType;
typedef  struct Node
{
	DataType data;
	struct Node* next;

}Node, *pNode, *pList;

pNode BuyNode(DataType d);//创建结点
void InitList(pList*pplist);//初始化链表
void PrintList(pList plist);//打印链表
void DestoryList(pList*pplist);//销毁链表
void PushBack(pList*pplist, DataType d);//尾插
void PopBack(pList* pplist);//尾删
void PushFront(pList* pplist, DataType d);//头插
void PopFront(pList* pplist);//头删
//查找函数
pNode Find(pList plist, DataType d);
//在指定位置之前插入一个值 
void Insert(pList* pplist, pNode pos, DataType d);
//指定位置删除 
void Erase(pList* pplist, pNode pos);//任意位置删除
void Remove(pList* pplist, DataType d);//删除链表中出现的第一次数据的结点
void RemoveAll(pList* pplist, DataType d);//删除链表中所有该数据结点
//打印链表长度
int GetListLength(pList plist);

//链表面试题 
//1. 逆序打印单项链表 
void PrintTailToHead(pList plist);
//2.删除一个无头单链表的非尾结点（不遍历链表）
void EraseNotTailNode(pNode pos);
//3.在一个无头单链表前的插入一个结点（不遍历链表）
void InsertNode(pNode pos, DataType d);
//4.单链表实现约瑟夫环（JosephusCircle）
void JosephusCircle(pList* pplist, int k);
//5.逆置/反转单链表
void ReverseList(pList*pplist);
//6.单链表排序（冒泡排序）
void BubbleSort(pList plist);
//8.合并两个有序链表，合并后依然有序
pNode Merge(pList p1, pList p2);
//递归版的
pNode Merge_R(pList p1, pList p2);
//查找链表的中间结点，要求只遍历一遍链表
pNode FindMidNode(pList plist);
//查找链表的倒数第k个结点
pNode FindLastKNode(pList plist, int k);
//判断链表是否带环
pNode IsCircle(pList plist);
//环的长度
int GetCircleLength(pNode meet);
//环的入口结点
pNode GetCycleEntryNode(pList plist, pNode meet);
//判断链表是否相交
int CheckCross(pList p1, pList p2);
//链表的交点
pNode GetCrossNode(pList p1, pList p2);
//求两个以排序链表中的相同数据
void UnionSet(pList p1, pList p2);
//一个复杂链表的复制
typedef struct ComplexNode
{
	DataType data;
	struct ComplexNode* next;
	struct ComplexNode* random;
}ComplexNode;
//复杂链表的结点创建
ComplexNode* BuyComplexNode(DataType d);
//复杂链表的打印
void PrintComplexList(ComplexNode* plist);
//复杂链表的复制
ComplexNode* CopyComplexList(ComplexNode* plist);
//复杂链表的尾插
void PushComplexlistBack(ComplexNode**pplist, DataType d);

#endif //__LIST_H__