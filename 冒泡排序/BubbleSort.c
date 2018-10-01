/*************************************************************************
	> File Name: BubbleSort.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年10月01日 星期一 16时44分00秒
 ************************************************************************/

#include<stdio.h>
#include<assert.h>
void Swap(int* a1, int* a2)
{
	assert(a1&&a2);
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}
void Print(int* a, int n)
{
	assert(a);
	int i = 0;
	for(i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void BubbleSort(int* a, int n)
{
	assert(a);
	int i = 0;
	int j = 0;
	int flag = 0;
	for(i = 0; i < n-1; i++)
	{
		flag = 0;
		for(j = 0;j < n-1-i; j++)
		{
			if(a[j] > a[j+1])
			{
				flag = 1;
				Swap(&a[j], &a[j+1]);
			}
		}
		if(flag==0)
			break;
	}
}



int main()
{
	int a[]={9,8,7,6,5,4,3,2,1,0};
	int size=sizeof(a)/sizeof(int);
	BubbleSort(a,size);
	Print(a,size);
	return 0;
}
