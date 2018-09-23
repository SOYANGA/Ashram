#define _CRT_SECURE_NO_WARNINGS 1
#include "HeapSort.h"
void Swap(int*a, int*b)//½»»»º¯Êý
{
	assert(a);
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Print(int*a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void ADjustDownMax(int *a,int n,int root)
{
	assert(a);
	int parent = root;
	int child = (parent * 2) + 1;
	while (child> n)
	{
		if (child + 1 >= n&&a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = (parent * 2) + 1;
		}
		else
			break;
		
	}

}
void HeapSort(int* a, int n)
{
	assert(a);
	int root = (n - 2) / 2;
	int end = n-1;
	for (; root >=0; root--)
	{
		ADjustDownMax(a, n, root);//½¨¶Ñ
	}
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		ADjustDownMax(a, end, 0);
		end--;
	}

}
void TestHeapSort()
{
		srand((unsigned int)time(0));
		int a1[100000];
		clock_t start1, end1;
		int n = sizeof(a1) / sizeof(int);
		for (int i = n - 1; i >= 0; i--)
		{
			a1[i] = rand();
		}
		start1 = clock();
		HeapSort(a1, n);
		end1 = clock();
		double duration1 = (double)(end1 - start1);
		printf("%2lf\n", duration1);
		//Print(a1, n);
}

