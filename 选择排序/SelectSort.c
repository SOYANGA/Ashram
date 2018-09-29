/*************************************************************************
	> File Name: SelectSort.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年09月28日 星期五 16时21分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void Swap(int*a1,int*a2)
{
	assert(a1&&a2);
	int temp=*a1;
	*a1=*a2;
	*a2=temp;
}
void Print(int*a,int n)
{
	assert(a);
	int i = 0;
	for(;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void SelectSort(int*a,int n)
{
	assert(a);
	int i = 0;
	int begin = 0;
	int end = n-1;
	while(begin<end)
	{
		int maxindex = begin;
		int minindex = end;
		for(i=begin;i<end;i++)
		{
			if(a[i]>a[begin])
			{
				maxindex = i;
			}
			if(a[i]<a[end])
			{
				minindex = i;
			}
		}
			Swap(&a[begin],&a[minindex]);
			if(a[begin] == a[maxindex])
			{
				maxindex = minindex;
			}
			Swap(&a[end],&a[maxindex]);
			++begin;
			--end;
		
	}
}

int main()
{
	int a[] = {9 , 8 ,7  ,6 ,5 ,4 ,3 ,2 ,1 ,0 };
	int size = sizeof(a)/sizeof(int);
	SelectSort(a,size);
	Print(a,size);
	return 0;
}
