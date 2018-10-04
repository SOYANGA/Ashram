/*************************************************************************
	> File Name: QuickSort.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年10月01日 星期一 23时51分04秒
 ************************************************************************/

#include<stdio.h>
#include<assert.h>
<<<<<<< HEAD
void InsertSort(int *a ,int n)
{
	assert(a);
	int i = 0;
	int j = 0;
	int temp = 0;
	for(i = 1; i<n; i++)                                         //区间从小到大递增 所以
	{
		temp = a[i];  //存储区间值（在这个区间内的基准值）    i确定了目前在0～i区间内的数需要排序
		j = i-1;     //前面的一位
		while(j>0&&a[j]>temp)  //只要在这个区间内就将区间值安置到他的位置即区间值左右满足（左小右大）
		{
			a[j+1]=a[j];          //大的
			j--;
		}
		a[j+1]=temp;           //遇到比区间值小的则将区间值插到小的后面，或已经到区间的头了。      
	}
}
=======
>>>>>>> b752858e2500983adfbc0d49f5e350adc93b59d6
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
<<<<<<< HEAD
int PartSort1(int *a, int begin ,int end)//  hoare 版本
{
	assert(a);
	int mid = Getmidindex(a,begin ,end);   //三数取中
	Swap(&a[mid],&a[end]);
	int key =a[end];                          //基准值
	int last =end;
	while(begin<last)                          //左小右大
	{
		while(begin<last&&a[begin]<=key)       //从左边找比key大的
		{
			begin++;
		}
		while(begin<last&&a[last]>=key)        //从右边找比key小的
		{
			last--;
		}
		Swap(&a[begin],&a[last]);                 //交换
	}
	Swap(&a[begin],&a[end]);                      //吧基准值放到中间   /此时begin  和 last是一个值
	return begin;                                  //返回划分分区的划分坐标
}
int PartSort2(int *a ,int begin ,int end)//挖坑版本
{
	assert(a);
	int mid = Getmidindex(a,begin,end);
	Swap(&a[end],&a[mid]);
	int key =a[end]; //基准值也是坑
	while(begin<end)
	{
		while(begin<end&&a[begin]<=key) //找基准值小的
		{
			begin++;
		}
		a[end]=a[begin];//小的放入坑中
		while(begin<end&&a[end]>=key)
		{	
			end--;
		}
		a[begin]=a[end];//大的放入小的取出后的坑中
	}
	a[end]=key;                        //此时end和begin是一个值  把基准值放到分区下标处
	return end;

}
int PartSort3(int* a,int begin,int end)
{
	assert(a);
	int mid = Getmidindex(a,begin,end);
	Swap(&a[mid],&a[end]);
	int prev = begin-1;//比基准值大的值，比较的前的一个值。用于找到比基准值小的元素交换用的，最后作为确定放回基准值位置的值
	int cur = begin; //要比较的值
	int key =a[end];//基准值
	while(cur<end)
	{
		if(a[cur]<key&&++prev != cur)//++prev==cur说明是第一个元素或者就是一段符合要求的比基准值小的序列
		{
			Swap(&a[cur],&a[prev]);   //找到笔记准值小的与++prev里存放的比基准值大的值交换，达到左小右大
		}
		++cur;
	}
	Swap(&a[++prev],&a[end]);//把基准值与++prev里存放的比基准值大的值交换，达到左小右大
	return prev;
}
void QuickSort(int* a, int left ,int right)//快排递归版
{
	assert(a);
	if(left>=right)                //递归出口   当区间内只剩一个元素时即排序完成时
		return;
	else
	{
		int div = PartSort3(a,left, right);             //分区  
		QuickSort(a ,0 ,div-1);                         //左区间
		QuickSort(a, div+1,right);                       //右区间
	}
}


//////////////////////////////////////////////////////////
void QuickSortOP(int* a, int left ,int right) //优化版  三数取中   小区间优化
{
	assert(a);
	if(left>=right)                //递归出口   当区间内只剩一个元素时即排序完成时
		return;
	if(right-left+1 < 10)           //小区间优化
	{
		InsertSort(a+left,right-left+1);  
	}
	else
	{
		int div = PartSort1(a,left, right);             //分区  
		QuickSort(a ,0 ,div-1);                         //左区间
		QuickSort(a, div+1,right);                       //右区间
	}
}

//非递归版的利用栈存储区间  压栈（两次）别为尾头  然后依次出栈，直到栈内为空即代表（此时区间大小为一个元素）
/////////////////////////////////////////////////
int main()
{
	int a[]={10,9,8,7,6,5,4,3,2,1,0,11,12,14,13,15,18,19,20,89,99,75,55,68,98,12,35,78,65,14,12,21,16};
	int size=sizeof(a)/sizeof(int);
	int input = 0;
	do
	{
		printf("快排递归版测试请按1\n");
		printf("快排非递归版测试请按2\n");
		printf("推出请按0\n");
		printf("请输入：");
		scanf("%d",&input);
		switch(input)
		{
			case(1):
				QuickSortOP(a,0,size-1);
				Print(a,size);
				break;
			case(2):
				QuickSortOP(a,0,size-1);
				Print(a,size);
				break;
			case(0):
				printf("exit\n");
				break;
			default:
				printf("请输入正确的值\n");
				break;
		}
	}while(input);
	return 0;
=======
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
>>>>>>> b752858e2500983adfbc0d49f5e350adc93b59d6
}
