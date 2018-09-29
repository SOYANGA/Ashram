/*************************************************************************
	> File Name: ShellSort.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年09月27日 星期四 19时27分21秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void Swap(int* a1,int* a2)
{
	assert(a1&&a2);
	int temp=*a1;
	*a1=*a2;
	*a2=temp;
	return;
}
void Print(int*a,int n)
{
	assert(a);
	int i=0;
	for(;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void ShellSort(int*a,int n)
{
	assert(a);
	int i=0;
	int j=0;
	int gap=0;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			for(j=i-gap;j>=0&&a[j]>a[j+gap];j-=gap)
			{
				Swap(&a[j],&a[j+gap]);
			}
		}
	}
}

int main()
{
	int a[]={9,8,7,6,5,4,3,2,1,0};
	int size=sizeof(a)/sizeof(int);
	ShellSort(a,size);
	Print(a,size);
	return 0;
}
