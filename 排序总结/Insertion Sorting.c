#include "Sort_Rank.h"
#include "Stack.h"

void Swap(int*a, int*b)//交换函数
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
void InsertSort(int *a, int n)//直接插入排序
{
	int i = 0;
	int j = 0;
	assert(a);
	int temp = 0;
	for (i = 1; i < n; i++)
	{
		temp = a[i];//将要比较的值先绶存起来留出一个空位，方便移动
		j = i - 1;
		while (j >= 0 && a[j]>temp)///比较直到出现比temp小的值，或向前找到头
		{
			a[j + 1] = a[j];//将前面的值往后移
			j--;
		}
		a[j + 1] = temp;//插在a[j]的后面
	}
}
void ShellSort(int*a, int n)
{
	assert(a);
	int gap, i, j; /*,temp;*/
	//gap的值逐渐递减
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)//
		{
			for (j = i - gap; j >= 0 && a[j]>a[j + gap]; j -= gap)
			{
				//temp = a[j];
				//a[j] = a[j + gap];           //利用temp交换两个值
				//a[j + gap] = temp;
				Swap(&a[j], &a[j + gap]);
			}
		}
	}

}


void SelectSort(int *a, int n)//选择排序
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxindex = begin;
		int minindex = end;
		for (int i = begin; i < end; i++)
		{
			if (a[i]>a[begin])
			{
				maxindex = i;
			}
			if (a[i] < a[end])
			{
				minindex = i;
			}
		}
		Swap(&a[begin], &a[minindex]);
		if (a[begin] == a[maxindex])
		{
			maxindex = minindex;
		}
		Swap(&a[end], &a[maxindex]);
		begin++;
		end--;
	}
}
//堆排
void ADjustDownMax(int *a, int n, int root)
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
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int *a, int n)
{
	assert(a);
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		ADjustDownMax(a, n, i);//建堆
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		ADjustDownMax(a, end, 0);
		end--;
	}
}
//冒泡排序
void BubbleSort(int *a, int n)
{
	assert(a);
	int i, j, flag;
	//外循环  //大循环增  使内循环值递减 因为每次把小于a[j]的值后移
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		//内循环  确定顶比较次数
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 1;               //确定当前许序列是否有序
				Swap(&a[j], &a[j + 1]);
			}
		}
		if (flag == 0)
			break;
	}
}
//快排
int GetMidIndex(int *a, int begin, int end)//“三数取中"优化
{
	int mid = begin + ((end - begin) >> 1);//移位运算比除法运算快
	//begin mid end                         求取3个数的中间数
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] < a[end])
			return end;
		else  /*if(a[end]<a[begin])*/
			return begin;
	}
	else//a[mid]<a[begin]
	{
		if (a[end] < a[mid])
		{
			return mid;
		}
		else if (a[end]>a[mid])
		{
			return end;
		}
		else /*if (a[end] > a[begin])*/
		{
			return begin;
		}
	}

}
//普通法hoare版本
int PartSort1(int *a, int begin, int end)
{
	assert(a);
	int mid = GetMidIndex(a, begin, end);//选定一个好的基准值（三数取中）
	Swap(&a[mid], &a[end]);//交换使得选出的值变为 基准值
	int key = a[end];

	int last = end;//记录最后的一个位置方便返回基准值
	while (begin < last)
	{
		while (begin < last&&a[begin] <= a[end])//左边找比key大的值
		{
			begin++;
		}
		while (begin < last&&a[last] >= a[end])//右边找比key小的值
		{
			last--;
		}
		Swap(&a[begin], &a[last]);//交换
	}
	Swap(&a[begin], &a[end]);//全部交换完后吧基准值放到左变小于他右边大于他的位置
	return begin;//返回基准值
}
//挖坑法
int PartSort2(int *a, int begin, int end)
{
	assert(a);
	int mid = GetMidIndex(a, begin, end);//同上
	Swap(&a[mid], &a[end]);
	int key = a[end];
	int pit = a[end];//确定基准值
	while (begin < end)
	{
		//在左边找比基准大的一个元素，放入坑中
		while (begin < end&&a[begin] <= key)
		{
			begin++;  //找过一个就递增
		}
		a[end] = a[begin];
		//在右边找比基准小的一个元素，放入左边那个比基准值大的元素的位置 等于利用坑交换两个数
		while (begin < end&&a[end] >= key)
		{
			end--;//找过一个就递减
		}
		a[begin] = a[end];
	}
	//把拿出来的基准值，放入坑中 （这时）a[begin]==a[end]
	//但因为比基准值大的时放到基准值的右边所以a[begin]=key
	a[begin] = key;
	//返回基准值，可用于下来继续划分区间
	return begin;
}
//双指针法
int PartSort3(int *a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);// 三数取中”
	Swap(&a[end], &a[mid]); //取得基准值
	int prev = begin - 1; ///要比较的前一个值，用于确定那些不符合在基准值 （比基准值大的值（用于交换）），达到左边都是小于基准值的原则
	int cur = begin;  //要比较的值
	int key = a[end]; //基准值
	while (cur < end) //确定循环次数 区间一直减小
	{
		//++prev==cur说明这是第一个元素，不需要交换，或这时一段连续小于基准值的序列
		if (a[cur] < key && ++prev != cur)  //找到小于基准值的值，交换++prev里存的大于基准值的值
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[++prev], &a[end]);//将基准值交换++prev里面存的大于基准值的值，达到左小右大
	//返回基准值
	return prev;
}

void QuickSort(int *a, int left, int right)//快排
{
	if (left >= right)//递归出口当最小子区间只剩一个值时则序列有序
		return;

	//if (right - left + 1 < 10)//小区间优化
	//{
	//	InsertSort(a + left, right - left + 1);
	//}
	else
	{
		int div = PartSort2(a, left, right);
		//子问题排左区间
		QuickSort(a, left, div - 1);
		//子问题排右区间
		QuickSort(a, div + 1, right);
	}
}
void QuickSortOP(int *a, int left, int right)//快排优化版-加上了小区间
{
	if (left >= right)
		return;
	if (right - left + 1 < 10)//小区间优化
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int div = PartSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}
//快排非递归
void Quick_SortNoR(int *a, int left, int right)
{
	Stack st;
	StackInit(&st);         // 利用栈来实现非递归
	StackPush(&st, right);//压入总区间末尾     先压后出
	StackPush(&st, left);//压入总区间开始    
	while (StackEmpty(&st) != 0)
	//  当栈为空时就是只有一个数的时候 即排好序的时候，没有大于2个值得子区间没排好序得时候
	{
		//每次处理一个区间的值变为有序，先一直向右处理然后再是右的左，然后在是左。（RVL）后序
		int begin = StackTop(&st);//区间开始
		StackPop(&st);
		int end = StackTop(&st);//区间结束
		StackPop(&st);
		//划分好区间
		int div = PartSort1(a, begin, end); //确定基准值并排序
		if (begin < div)  //左区间还有大于1得元素时，入栈待处理  等于
		{
			StackPush(&st, div - 1);  //压入左区间尾
			StackPush(&st, begin);//压左入区间头

		}
		if (div + 1 < end) ////右区间还有大于1得元素时，入栈待处理
		{
			StackPush(&st, end);//压入右区间尾
			StackPush(&st, div + 1);//压入右区间头
		}
	}

}
//归并排序
void Merge(int*a, int begin1, int end1, int begin2, int end2, int *tmp)  //合并
{
	assert(a&&tmp);
	int start = begin1;
	int index = begin1;//从begin1开始合并
	//和两条有序单链表的合并相似
	int n = end2 - start + 1;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	//剩余的未排序内容拷贝回去
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//把tmp合并的空间拷贝到a上
	memcpy(a + start, tmp + start, sizeof(int)*(n));

}
void _MergeSort(int *a, int begin, int end, int *tmp)
{
	assert(a&&tmp);
	if (begin >= end)
	{
		return;
	}
	int mid = begin + ((end - begin) >> 1);//移位运算比除法运算快
	//分段  【begin mid】【mid+1 end】像二叉树一样分组
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	Merge(a, begin, mid, mid + 1, end, tmp);  //合并
}

void MergeSort(int *a, int n)
{
	assert(a);
	int *tmp = (int *)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}


//////////////////////////////////////////////////////////////////////
//测试
void Compare_AllSort()
{
	int a1[10000];
	int a2[10000];
	int a3[10000];
	int a4[10000];
	int a5[10000];
	int a6[10000];
	int a7[10000];
	int a8[10000];
	// 随机排列
	srand((unsigned int)time(0));
	for (int i = 0; i < 10000; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}
	//倒叙排列
	//for (int i=9999; i >=0; i--)
	//{
	//a1[i] = i;
	//a2[i] = a1[i];
	//a3[i] = a1[i];
	//a4[i] = a1[i];
	//a5[i] = a1[i];
	//a6[i] = a1[i];
	//a7[i] = a1[i];
	//a8[i] = a1[i];
	//}
	int n = sizeof(a1) / sizeof(int);
	////////////////////////////////////////////////
	//插排
	clock_t start3 = clock();
	InsertSort(a3, n);
	clock_t end3 = clock();
	printf("InsertSort: %d \n", end3 - start3);
	//Print(a2, n);

	clock_t start4 = clock();
	ShellSort(a4, n);
	clock_t end4 = clock();
	printf("ShellSort: %d \n", end4 - start4);
	//Print(a2, n);
	///////////////////////////////////////////////////////
	//选择排序

	clock_t start7 = clock();
	SelectSort(a7, n);
	clock_t end7 = clock();
	printf("SelectSort: %d \n", end7 - start7);
	//Print(a2, n);

	clock_t start5 = clock();
	HeapSort(a5, n);
	clock_t end5 = clock();
	printf("HeapSort: %d \n", end5 - start5);
	//Print(a2, n);
	//////////////////////////////////////////////////
	//交换排序

	clock_t start8 = clock();
	BubbleSort(a8, n);
	clock_t end8 = clock();
	printf("BubbleSort: %d \n", end8 - start8);
	//Print(a2, n);

	clock_t start1 = clock();
	QuickSortOP(a1, 0, n - 1);
	clock_t end1 = clock();
	printf("QuickSortO: %d \n", end1 - start1);
	//Print(a1, n);

	clock_t start2 = clock();
	Quick_SortNoR(a2, 0, n - 1);
	clock_t end2 = clock();
	printf("Quick_SortNoR: %d \n", end2 - start2);
	//Print(a2, n);
	///////////////////////////////////
	//归并排序

	clock_t start6 = clock();
	MergeSort(a6, n);
	clock_t end6 = clock();
	printf("MergeSort: %d \n", end6 - start6);
	//Print(a2, n);


}
void TestMergeSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int size = sizeof(a) / sizeof(int);
	MergeSort(a, size);
	Print(a, size);
}
void Compare_QuickSort()
{
	int a1[100000];
	int a2[100000];
	srand((unsigned int)time(0));
	for (int i = 0; i < 100000; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
	}
	int n = sizeof(a1) / sizeof(int);
	clock_t start1 = clock();
	QuickSortOP(a1, 0, n - 1);
	clock_t end1 = clock();
	printf("%d \n", end1 - start1);
	//Print(a1, n);

	clock_t start2 = clock();
	Quick_SortNoR(a2, 0, n - 1);
	clock_t end2 = clock();
	printf("%d \n", end2 - start2);
	//Print(a2, n);
}
void TestQuick_SortNoR()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int size = sizeof(a) / sizeof(int);
	Quick_SortNoR(a, 0, size - 1);
	Print(a, size);
}
void TestQuickSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int size = sizeof(a) / sizeof(int);
	QuickSort(a, 0, size - 1);
	Print(a, size);
}
void TestBubbleSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int size = sizeof(a) / sizeof(int);
	BubbleSort(a, size);
	Print(a, size);
}

void TestSelectSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int size = sizeof(a) / sizeof(int);
	SelectSort(a, size);
	Print(a, size);
}
void TestHeapSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int size = sizeof(a) / sizeof(int);
	HeapSort(a, size);
	Print(a, size);
}
void TestInserSort()
{
	int a1[] = { 5, 8, 9, 4, 3, 2, 1, 7, 0, 6 };
	int a2[] = { 5, 8, 9, 4, 3, 2, 1, 7, 0, 6 };
	int n = sizeof(a1) / sizeof(int);
	clock_t start1 = clock();
	InsertSort(a1, 10);
	clock_t end1 = clock();
	printf("%f \n", end1 - start1);
	Print(a1, n);

	clock_t start2 = clock();
	ShellSort(a2, 10);
	clock_t end2 = clock();
	printf("%f \n", end2 - start2);
	Print(a2, n);
}