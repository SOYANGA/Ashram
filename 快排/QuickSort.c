/*************************************************************************
	> File Name: QuickSort.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年10月01日 星期一 23时51分04秒
 ************************************************************************/

#include<stdio.h>
#include<assert.h>
void Swap(int*a1,int*a2)
{
	assert(a1&&a2);
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}
void Print(int*a,int n)
{
	assert(a);
	int i = 0;
	for(i=0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int Getmidindex(int *a, int begin ,int end)
{
	assert(a);
	int mid = begin+((end-begin)>>1);
	if(a[begin]<a[mid])
	{
		if(a[begin]>a[end])
			return begin;
		if(a[mid]<a[end])
			return mid;
		else//(a[end]>a[begin])
			return end;
	}
	else//if(a[mid]<a[begin])
	{
		if(a[begin]<a[end])
			return begin;
		if(a[mid]>a[end])
			return mid;
		else//if(a[end]>a[mid])
			return end;
	}
}
int PartSort1(int *a, int begin ,int end)
{
	assert(a);
	int mid = Getmidindex(a,begin ,end);
	Swap(&a[mid],&a[end]);
	int key =a[end];
	int last =end;
	while(begin<last)
	{
		while(begin<last&&a[begin]<=key)
		{
			begin++;
		}
		while(begin<last&&a[last]>=key)
		{
			last--;
		}
		Swap(&a[begin],&a[last]);
	}
	Swap(&a[begin],&a[end]);
	return begin;
}
void QuickSort(int* a, int left ,int right)
{
	assert(a);
	if(left>=right)
		return;
	else
	{
		int div = PartSort1(a,left, right);
		QuickSort(a ,0 ,div-1);
		QuickSort(a, div+1,right);
	}
}
int main()
{
	int a[]={9,8,7,6,5,4,3,2,1,0};
	int size=sizeof(a)/sizeof(int);
	QuickSort(a,0,size-1);
	Print(a,size);
}
