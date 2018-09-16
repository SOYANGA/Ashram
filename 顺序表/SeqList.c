#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//��ʼ��
void InintSeqList(PSeqList pSeq)
{
	assert(pSeq != NULL);
	pSeq->sz = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));
}
//��ӡ
void PrintSeqList(PSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��!\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
	printf("\n");
}
//β������
void PushBack(PSeqList pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->sz == MAX)
	{
		printf("˳��������޷����룡\n");
		return;
	}
	pSeq->data[pSeq->sz] = data;
	pSeq->sz++;
}

//β��ɾ��
void PopBack(PSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��,�޷�β��ɾ����\n");
		return;
	}
	pSeq->sz--;
}
//ͷ������ 
void PushFront(PSeqList pSeq, DataType data)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == MAX)
	{
		printf("˳����������޷����룡\n");
		return;
	}
	if (pSeq->sz == 0)
	{
		pSeq->data[0] = data;
		pSeq->sz++;
		return;
	}
	for (i = pSeq->sz - 1; i >= 0; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[0] = data;
	pSeq->sz++;
}
//ͷ��ɾ��
void PopFront(PSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ���޷�ɾ����\n");
		return;
	}
	for (i = 1; i < pSeq->sz; i++)
	{
		pSeq->data[i - 1] = pSeq->data[i];
	}
	pSeq->sz--;
}
//����ָ��Ԫ�� 
int Find(PSeqList pSeq, DataType data)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == data)
		{
			return i;
		}
	}
	return -1;
}
//ָ��λ�ò��� 
void Insert(PSeqList pSeq, int pos, DataType data)
{
	int i = 0;
	assert(pSeq);
	assert((pos <= pSeq->sz) && (pos >= 0));
	if (pSeq->sz == MAX)
	{
		printf("˳����������޷����룡\n");
		return;
	}
	for (i = pSeq->sz - 1; i >= pos; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[pos] = data;
	pSeq->sz++;
}
//ɾ��ָ��λ��Ԫ�� 
void Erase(PSeqList pSeq, int pos)
{
	int i = 0;
	assert(pSeq);
	assert((pos <= pSeq->sz) && (pos >= 0));
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ���޷�ɾ����\n");
		return;
	}
	for (i = pos; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}
//ɾ��ָ��Ԫ�� 
void Remove(PSeqList pSeq, DataType data)
{
	int i = 0;
	int pos = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ���޷�ɾ����\n");
		return;
	}
	if (pos = Find(pSeq, data) != -1)
	{
		Erase(pSeq, pos);
	}
#if 0
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == data)
		{
			break;
		}
	}
	if (i == pSeq->sz)
	{
		printf("ɾ����Ԫ�ز����ڣ�\n");
		return;
	}
	for (; i < pSeq->sz-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
#endif
}
//ɾ�����е�ָ��Ԫ��
void RemoveAll(PSeqList pSeq, DataType data)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ���޷�ɾ����\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{

		if (pSeq->data[i] != data)
		{
			pSeq->data[j++] = pSeq->data[i];
		}
	}
	pSeq->sz = j;
#if 0
	int pos = 0;
	assert(pseq!=NULL);
	while((pos=Find(pSeq,data)!=-1))
	{
		Erase(pSeq, pos);
	}
#endif
}
//����˳���Ĵ�С  = j
int Size(PSeqList pSeq)
{
	assert(pSeq);
	return pSeq->sz;
}
//�ж�˳����Ƿ�Ϊ�� 
int Empty(PSeqList pSeq)
{
	assert(pSeq);
	return pSeq->sz == 0;

}
void Swap(DataType*p1, DataType* p2)
{
	DataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;

}
//ð������
void BubbleSort(PSeqList pSeq)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		flag = 0;
		for (j = 0; j < pSeq->sz - i - 1; j++)
		{
			if (pSeq->data[j]>pSeq->data[j + 1])
			{
				Swap(pSeq->data + j, pSeq->data + j + 1);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}

}

//ѡ������ 
void SelectSort(PSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		int max = 0;
		for (j = 1; j < pSeq->sz - i; j++)
		{
			if (pSeq->data[max] < pSeq->data[j])
			{
				max = j;
			}
		}//maxΪ���Ԫ�ص��±�
		if (max != pSeq->sz - i - 1)
		{
			Swap(pSeq->data + max, pSeq->data + pSeq->sz - 1 - i);
		}
	}
}
//�Ż�
void SelectSort_OP(PSeqList pSeq)
{
	int start = 0;
	int end = pSeq->sz - 1;
	assert(pSeq);
	while (start < end)
	{
		int max = start;
		int min = start;
		int i = 0;
		for (i = start; i <= end; i++)
		{
			if (pSeq->data[i] > pSeq->data[max])
			{
				max = i;
			}

			if (pSeq->data[i] < pSeq->data[min])
			{
				min = i;
			}
		}
		if (min != start)
		{
			Swap(pSeq->data + start, pSeq->data + min);
		}
		if (max == min)//�ص����׺���
		{
			max = min;
		}
		if (max != start)
		{
			Swap(pSeq->data + max, pSeq->data + end);
		}
		start++;
		end--;
	}
}
//���ֲ��� 
int BinarySearch(PSeqList pSeq, DataType data)
{
	int left =0;
	int right = pSeq->sz - 1;
	assert(pSeq);
	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if (pSeq->data[mid] > data)
		{
			right = mid - 1;
		}
		else if (pSeq->data[mid] < data)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
//���ֲ��ҵݹ�д��
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType data)
{
	int mid = 0;
	assert(pSeq);
	if (left > right)
		return -1;
	mid = left + (right - left) / 2;
	if (pSeq->data[mid] > data)
		return BinarySearch_R(pSeq, left, mid - 1, data);
	else if (pSeq->data[mid] < data)
		return BinarySearch_R(pSeq, mid + 1, right, data);
	else
		return mid;
}


