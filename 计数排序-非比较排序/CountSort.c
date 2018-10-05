/*************************************************************************
	> File Name: CountSort.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年10月05日 星期五 23时11分03秒
 ************************************************************************/

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

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
void CountSort(int*a ,int n)
{
	assert(a);
	int max = a[n-1];
	int min = a[0];
	int i = 0;
	for(i = 0; i < n; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
		if(a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max-min+1;           //找出最大最小数确定范围
	int*  count = (int*)malloc(sizeof(int)*range);  //创建最大最小数范围内数的个数的数组
	memset(count, 0 ,sizeof(int)*range);     //将其置零  为这个数出现的次数
	for(i =0 ;i < n; i++)
	{
		count[a[i]-min]++;                  //计算每个数出现的次数（在这个范围内）
	}
	int index = 0;
	for(i = 0; i < range; i++)                           //读取这个数组中的数（从数组开头向后读
	{                                                      //即从小到大读，次数不为零的存储到原数组a当中
		while(count[i]--)                                   //达到排序的目的
		{
			a[index++] = i+min;
		}
	}
}

int main()
{
	int a[]={9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(a)/sizeof(int);
	CountSort(a, size);
	Print(a,size);
	return 0;
}
