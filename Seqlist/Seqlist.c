/*************************************************************************
	> File Name: Seqlist.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年10月07日 星期日 22时48分38秒
 ************************************************************************/

#include"Seqlist.h"

void InitSeqList(pSepList pSeq)   //初始化
{
	assert(pSeq);
	pSeq->sz = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));
}
void PushBack(pSepList pSeq, DataType data)  //尾部插入
{
	assert(pSeq);
	if(pSeq->sz == Max)
	{
		printf("顺序表已满\n");
		return;
	}
	pSeq->data[pSeq->sz]=data;
	pSeq->sz++;
}
void PopBack(pSepList pSeq)//尾部删除
{
	assert(pSeq)":"！\n");
		return;::""""
	}
	pSeq->sz--;
}
void PushFront(pSepList pSeq,DataType data)  //头插
{
	assert(pSeq);
	if(pSeq->sz == Max)
	{
		printf("顺序表已满\n");
		return;:wq	}
	if(pSeq->sz == 0)
	{
		pSeq->data[0] = data;
pS:		pSeq->sz++;
		return;
	}
	int i = 0;
	for(i = pSeq->sz-1; i >= 0; i--)
	{
		pSeq->data[i+1]=pSeq->data[i];
	}
	pSeq->data[0] = data;
	pSeq->sz++;
}
void PopFront(pSepList pSeq)  //头删
{
	assert(pSeq);
	int i = 0;
	if(pSeq->sz == Max)
	{
		printf("顺序表已满\n");
		return;
	}
	for(i = 1; i<pSeq->sz; i++)
	{
		pSeq->data[i-1] = pSeq->data[i];
	}
	pSeq->sz--;
}
int Find(pSepList pSeq, DataType data)  //查找
{
	assert(pSeq);
	if(pSeq->sz == 0)
	{
		printf("顺序表为空\n");
		return -1;
	}
	int i = 0;
	for(i = 0; i<pSeq->sz; i++)
	{
		if(pSeq->data[i] == data)
		{
			return i;
		}
	}
	return -1;
}
void Insert(pSepList pSeq,int pos, DataType data) //指定位置插入
{
	assert(pSeq);
	int i = 0;
	if(pSeq->sz == Max)
	{
		printf("顺序表已满。\n");
		return;
	}
	for(i = pSeq->sz-1; i>=pos; i--)
	{
		pSeq->data[i+1] = pSeq->data[i];
	}
	pSeq->data[pos] = data;
	pSeq->sz++;
}

void Erase(pSepList pSeq, int pos)//删除指定位置元素
{
	assert(pSeq);
	assert((pos<=pSeq->sz)&&(pos>=0));
	int i = 0;
	if(pSeq->sz==0)
	{
		printf("顺序表为空\n");
		return;
	}
	for(i = pos;i<pSeq->sz-1;i++)
	{
		pSeq->data[i] = pSeq->data[i+1];
	}
	pSeq->sz--;
}
void Remove(pSepList pSeq,DataType data)//删除指定元素
{
	assert(pSeq);
	if(pSeq->sz==0)
	{
		printf("顺序表为空\n");
		return;
	}
	int i = 0;
	if(pos=Find(pSeq,data)!=-1)
	{
		Erase(pSeq,pos);
	}
}
void RemoveAll(pSepList pSeq, DataType data)//删除所有指定元素
{
	assert(pSeq);
	int i =0;
	int j = 0;
	if(pSeq->sz==0)
	{
		printf("顺序表为空不能删除\n");
		return;
	}
	for(i=0;i<pSeq->sz;i++)
	{
		if(pSeq->data[i]!=data)
		{
			pSeq->data[j++]=pSeq->data[i];
		}
	}
	pSeq->sz=j;
#if 0
	assert(pSeq);
	int pos = 0;
	while((pos=Find(pSeq,data)!=-1))
	{
		Erase(pSeq,pos);
	}
#endif
}

int size(pSepList pSeq)//返回顺序表大小
{
	assert(pSeq);
	return pSeq->sz;
}
int Empty(pSepList pSeq)//判断顺序表是否为空，空返回0 非空返还1
{
	assert(pSeq);
	return pSeq->sz==0;
}

void BubbleSort(pSepList pSeq)//冒泡排序
{
	assert(pSeq);

}
void SelectSort(pSepList pSeq);//插排

int BinarySearch(pSepList pSeq, DataType data);//二分查找
int BinarySearch_R(pSepList pSeq, int left ,int right, DataType d);//二分查找 递归版

void PrintSeqList(pSepList pSeq)//打印
{
	assert(pSeq);
	int i =0;
	for(i=0;i<pSeq->sz;i++)
	{
		printf("%d ",pSeq->data[i]);
	}
	printf("\n");

}
