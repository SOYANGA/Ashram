#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void swap(HPDataType*h1, HPDataType*h2)//交换函数
{
	HPDataType x = *h1;
	*h1 = *h2;
	*h2 = x;
}
void ADjustDownMin(HPDataType*a, int n, int root)//向下调整 小堆
{
	assert(a);
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//找出左右两个中最小的一个
		if (child + 1 < n && a[child] > a[child + 1])
			++child;
		//
		//交换
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
void ADjustUpMin(HPDataType*a, int n, int child)//向上调整 小堆
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
void ADjustDownMax(HPDataType*a, int n, int root)//向下调整 大堆
{
	assert(a);
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//找出左右两个中最大的一个
		if (child + 1 < n && a[child] < a[child + 1])
			++child;
		//
		//交换
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
void ADjustUpMax(HPDataType*a, int n, int child)//向上调整 大堆
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

void HeapInit(Heap*hp, HPDataType*a, int n)//初始化函数
{
	assert(hp&&a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)* n);
	hp->_capacity = n;
	hp->_size = n;
	for (int i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	//堆排序
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		ADjustDownMax(hp->_a, hp->_size, i);
		//ADjustDownMin(hp->_a, hp->_size, i);

	}
}
void HeapDestory(Heap*hp)//销毁函数
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
	for (int i = 0; i < hp->_size; i++)//打印
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
//0为空
//1为非空
int HeapEmpty(Heap*hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}
//不直接调Heap
void HeapSort(HPDataType*a, int n)
{
	assert(a);
	//创建堆
	int i = (n - 2) / 2;
	for (; i >= 0; --i)
	{
		ADjustDownMax(a, n, i);
	}
	//不断调整出最大值或最小值
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
	HeapInit(&hp, a, sizeof(a) / sizeof(HPDataType));//创建堆
	Heapprint(&hp);//打印
	printf("堆的Size：%d \n", HeapSize(&hp));//堆的长度
	printf("堆顶为：%d \n", HeapTop(&hp));//堆顶元素
	HeapPush(&hp, 99);//插入堆尾
	Heapprint(&hp);//打印
	printf("堆的Size：%d \n", HeapSize(&hp));//堆的长度
	printf("堆顶为：%d \n", HeapTop(&hp));//堆顶元素
	printf("堆是否为空？：%d \n", HeapEmpty(&hp));//判空	
	HeapPop(&hp);//出堆顶
	Heapprint(&hp);//打印
	printf("堆的Size：%d \n", HeapSize(&hp));//堆的长度
	printf("堆顶为：%d \n", HeapTop(&hp));//堆顶元素
	printf("堆是否为空？：%d \n", HeapEmpty(&hp));//判空	
	HeapDestory(&hp);//销毁
	printf("堆的Size：%d \n", HeapSize(&hp));//堆的长度
	printf("堆是否为空？：%d \n", HeapEmpty(&hp));//判空

	HPDataType arr[] = { 12, 35, 48, 68, 45, 96, 36, 67, 41 };
	HeapSort(arr, sizeof(arr) / sizeof(HPDataType));
	for (int i = 0; i < sizeof(arr) / sizeof(HPDataType); i++)
	{
		printf("%d ", arr[i]);
	}
	HeapDestory(&hp);
}
