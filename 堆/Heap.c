#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void swap(HPDataType*h1, HPDataType*h2)//��������
{
	HPDataType x = *h1;
	*h1 = *h2;
	*h2 = x;
}
void ADjustDownMin(HPDataType*a, int n, int root)//���µ��� С��
{
	assert(a);
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//�ҳ�������������С��һ��
		if (child + 1 < n && a[child] > a[child + 1])
			++child;
		//
		//����
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void ADjustUpMin(HPDataType*a, int n, int child)//���ϵ��� С��
{
	assert(a);
	int parent = (child - 1) / 2;
	while (a[child] > 0)
	{
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}

}
void ADjustDownMax(HPDataType*a, int n, int root)//���µ��� ���
{
	assert(a);
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//�ҳ���������������һ��
		if (child + 1 < n && a[child] < a[child + 1])
			++child;
		//
		//����
		if (a[child]>a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void ADjustUpMax(HPDataType*a, int n, int child)//���ϵ��� ���
{
	assert(a);
	int parent = (child - 1) / 2;
	while (a[child] > 0)
	{
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}

}

void HeapInit(Heap*hp, HPDataType*a, int n)//��ʼ������
{
	assert(hp&&a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)* n);
	hp->_capacity = n;
	hp->_size = n;
	for (int i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	//������
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		ADjustDownMax(hp->_a, hp->_size, i);
		//ADjustDownMin(hp->_a, hp->_size, i);

	}
}
void HeapDestory(Heap*hp)//���ٺ���
{
	assert(hp);
	hp->_capacity = 0;
	hp->_size = 0;
	free(hp->_a);
	hp->_a = NULL;
}

void HeapPush(Heap*hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	++hp->_size;
	ADjustUpMax(hp->_a, hp->_size, hp->_size - 1);
	//ADjustUpMin(hp->_a, hp->_size, hp->_size - 1);

}
void HeapPop(Heap*hp)
{
	assert(hp);
	swap(&hp->_a[hp->_size - 1], &hp->_a[0]);
	hp->_size--;
	ADjustDownMax(hp->_a, hp->_size, 0);
	//ADjustDownMin(hp->_a, hp->_size, 0);
}
HPDataType HeapTop(Heap*hp)
{
	assert(hp);
	return hp->_a[0];
}
int HeapSize(Heap*hp)
{
	assert(hp);
	return hp->_size;
}
void Heapprint(Heap*hp)
{
	for (int i = 0; i < hp->_size; i++)//��ӡ
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
//0Ϊ��
//1Ϊ�ǿ�
int HeapEmpty(Heap*hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}
//��ֱ�ӵ�Heap
void HeapSort(HPDataType*a, int n)
{
	assert(a);
	//������
	int i = (n - 2) / 2;
	for (; i >= 0; --i)
	{
		ADjustDownMax(a, n, i);
	}
	//���ϵ��������ֵ����Сֵ
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		ADjustDownMax(a, end, 0);
		end--;
	}
}
void TestHeap()
{
	Heap hp;
	HPDataType a[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	HeapInit(&hp, a, sizeof(a) / sizeof(HPDataType));//������
	Heapprint(&hp);//��ӡ
	printf("�ѵ�Size��%d \n", HeapSize(&hp));//�ѵĳ���
	printf("�Ѷ�Ϊ��%d \n", HeapTop(&hp));//�Ѷ�Ԫ��
	HeapPush(&hp, 99);//�����β
	Heapprint(&hp);//��ӡ
	printf("�ѵ�Size��%d \n", HeapSize(&hp));//�ѵĳ���
	printf("�Ѷ�Ϊ��%d \n", HeapTop(&hp));//�Ѷ�Ԫ��
	printf("���Ƿ�Ϊ�գ���%d \n", HeapEmpty(&hp));//�п�	
	HeapPop(&hp);//���Ѷ�
	Heapprint(&hp);//��ӡ
	printf("�ѵ�Size��%d \n", HeapSize(&hp));//�ѵĳ���
	printf("�Ѷ�Ϊ��%d \n", HeapTop(&hp));//�Ѷ�Ԫ��
	printf("���Ƿ�Ϊ�գ���%d \n", HeapEmpty(&hp));//�п�	
	HeapDestory(&hp);//����
	printf("�ѵ�Size��%d \n", HeapSize(&hp));//�ѵĳ���
	printf("���Ƿ�Ϊ�գ���%d \n", HeapEmpty(&hp));//�п�

	HPDataType arr[] = { 12, 35, 48, 68, 45, 96, 36, 67, 41 };
	HeapSort(arr, sizeof(arr) / sizeof(HPDataType));
	for (int i = 0; i < sizeof(arr) / sizeof(HPDataType); i++)
	{
		printf("%d ", arr[i]);
	}
	HeapDestory(&hp);
}
