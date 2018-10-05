/*************************************************************************
	> File Name: 11work_4.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年10月03日 星期三 22时28分28秒
 ************************************************************************/

#include<stdio.h>
#include<assert.h>
void reversed_arr(char*left, char*right) //交换函数
{
	assert(right&&left);
	while(left<right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

int my_stlren(const char *arr)  //求长度函数
{
	assert(arr);
	int count = 0;
	while(*arr)
	{
		arr++;
		count++;
	}
	return count;
}

void reversed(char *arr)  //反转函数
{
	assert(arr);
	char* cur = arr;
	char* left = arr;
	char* right = arr+my_stlren(arr)-1;
	reversed_arr(left,right);  //整体交换
	while(*cur)               //部分交换
	{
		char* start = cur             //定义left;
		while((*cur!=' ')&&(*cur!='\0'))                           //一个单词之内交换
		{
			cur++;
		}                                 //得出right
		reversed_arr(start,cur-1);         //反转（交换）
		if(*cur==' ')                                                //遇到空格（即转换下一个单词跳过即可）
		{
			cur++;
		}
	}
}

int main()
{
	char ret = 0;
	char arr[] = " student a am i ";
	reversed(arr);
	printf("%s\n ", arr);
	return 0;
}
