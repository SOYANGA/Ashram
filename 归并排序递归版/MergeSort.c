/*************************************************************************
	> File Name: MergeSort.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年10月05日 星期五 14时41分50秒
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
}
void Merge(int* a, int begin1, int end1, int begin2, int end2, int* temp)   //合并
{
	assert(a&&temp);
	int start = begin1;
	int index = begin1;             //从begin1开始合并     //和两条有序单链表的合并相似
	int n = end2-start+1;
	while(begin1 <= end1 && begin2 <= end2)           //小在前大在后
	{
		if(a[begin1] > a[begin2])
		{
			temp[index++] = a[begin2++];
		}
		else
		{
			temp[index++] = a[begin1++];
		}
	}                                               //剩余的未排序内容拷贝回去
	while(begin1 <= end1)
	{
		temp[index++]=a[begin1++];
	}
	while(begin2 <= end2)
	{
		temp[index++]=a[begin2++];
	}                                                  //把temp合并的空间拷贝到原数组上去
	memcpy(a+start, temp+start, sizeof(int)*n);
}


void _MergeSort(int* a, int begin ,int end ,int* temp)
{
	assert(a&&temp);
	if(begin>=end)               //递归出口  当分段里只剩一个元素时即排好序了
	{
		return;
	}
	int mid = (begin&end)+((begin^end)>>1);
	//分段【begin~mid】【mid+1,end]
	_MergeSort(a, begin ,mid, temp);
	_MergeSort(a, mid+1, end, temp);
	//合并
	Merge(a, begin, mid, mid+1, end, temp);
}
void MergeSort(int* a, int n)   //外排  归并排序
{
	assert(a);
	//创建一个等大的空间
	int *temp =(int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n-1 ,temp);
	free(temp);
	temp = NULL;
}


int main()
{
	int a[] = {9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(a)/sizeof(int);
	MergeSort(a, size);
	Print(a,size);
	return 0;
}



//第一步  创建等大空间
//        交给_MergeSort 传给他总区间 进行分组
//第二步  在_MergeSort中一个递归  当分组内只剩一个元素就跳出递归 
//		  分组（利用区间取中）划分区间，先前再后
//		  合并  传给Merge 原数组两个区间，还有创建的等大区间
//第三步  Merge进行合并，在两个分区内比大小，小的在前。两个区间有可能不一样大，排好后。将剩下的元素也补到temp后面
//        最后利用memcpy拷贝完成  ，注意是  memcpy(a+start, temp+start, sizeof(int)*  ;
