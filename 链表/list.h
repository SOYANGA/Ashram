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

pNode BuyNode(DataType d);//�������
void InitList(pList*pplist);//��ʼ������
void PrintList(pList plist);//��ӡ����
void DestoryList(pList*pplist);//��������
void PushBack(pList*pplist, DataType d);//β��
void PopBack(pList* pplist);//βɾ
void PushFront(pList* pplist, DataType d);//ͷ��
void PopFront(pList* pplist);//ͷɾ
//���Һ���
pNode Find(pList plist, DataType d);
//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(pList* pplist, pNode pos, DataType d);
//ָ��λ��ɾ�� 
void Erase(pList* pplist, pNode pos);//����λ��ɾ��
void Remove(pList* pplist, DataType d);//ɾ�������г��ֵĵ�һ�����ݵĽ��
void RemoveAll(pList* pplist, DataType d);//ɾ�����������и����ݽ��
//��ӡ������
int GetListLength(pList plist);

//���������� 
//1. �����ӡ�������� 
void PrintTailToHead(pList plist);
//2.ɾ��һ����ͷ������ķ�β��㣨����������
void EraseNotTailNode(pNode pos);
//3.��һ����ͷ������ǰ�Ĳ���һ����㣨����������
void InsertNode(pNode pos, DataType d);
//4.������ʵ��Լɪ�򻷣�JosephusCircle��
void JosephusCircle(pList* pplist, int k);
//5.����/��ת������
void ReverseList(pList*pplist);
//6.����������ð������
void BubbleSort(pList plist);
//8.�ϲ��������������ϲ�����Ȼ����
pNode Merge(pList p1, pList p2);
//�ݹ���
pNode Merge_R(pList p1, pList p2);
//����������м��㣬Ҫ��ֻ����һ������
pNode FindMidNode(pList plist);
//��������ĵ�����k�����
pNode FindLastKNode(pList plist, int k);
//�ж������Ƿ����
pNode IsCircle(pList plist);
//���ĳ���
int GetCircleLength(pNode meet);
//������ڽ��
pNode GetCycleEntryNode(pList plist, pNode meet);
//�ж������Ƿ��ཻ
int CheckCross(pList p1, pList p2);
//����Ľ���
pNode GetCrossNode(pList p1, pList p2);
//�����������������е���ͬ����
void UnionSet(pList p1, pList p2);
//һ����������ĸ���
typedef struct ComplexNode
{
	DataType data;
	struct ComplexNode* next;
	struct ComplexNode* random;
}ComplexNode;
//��������Ľ�㴴��
ComplexNode* BuyComplexNode(DataType d);
//��������Ĵ�ӡ
void PrintComplexList(ComplexNode* plist);
//��������ĸ���
ComplexNode* CopyComplexList(ComplexNode* plist);
//���������β��
void PushComplexlistBack(ComplexNode**pplist, DataType d);

#endif //__LIST_H__