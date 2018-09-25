#include "Sort_Rank.h"
#include "Stack.h"

void Swap(int*a, int*b)//��������
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
void InsertSort(int *a, int n)//ֱ�Ӳ�������
{
	int i = 0;
	int j = 0;
	assert(a);
	int temp = 0;
	for (i = 1; i < n; i++)
	{
		temp = a[i];//��Ҫ�Ƚϵ�ֵ��練���������һ����λ�������ƶ�
		j = i - 1;
		while (j >= 0 && a[j]>temp)///�Ƚ�ֱ�����ֱ�tempС��ֵ������ǰ�ҵ�ͷ
		{
			a[j + 1] = a[j];//��ǰ���ֵ������
			j--;
		}
		a[j + 1] = temp;//����a[j]�ĺ���
	}
}
void ShellSort(int*a, int n)
{
	assert(a);
	int gap, i, j; /*,temp;*/
	//gap��ֵ�𽥵ݼ�
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)//
		{
			for (j = i - gap; j >= 0 && a[j]>a[j + gap]; j -= gap)
			{
				//temp = a[j];
				//a[j] = a[j + gap];           //����temp��������ֵ
				//a[j + gap] = temp;
				Swap(&a[j], &a[j + gap]);
			}
		}
	}

}


void SelectSort(int *a, int n)//ѡ������
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
//����
void ADjustDownMax(int *a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//�ҳ���������������һ��
		if (child + 1 < n && a[child] < a[child + 1])
			++child;
		//
		//����
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
		ADjustDownMax(a, n, i);//����
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		ADjustDownMax(a, end, 0);
		end--;
	}
}
//ð������
void BubbleSort(int *a, int n)
{
	assert(a);
	int i, j, flag;
	//��ѭ��  //��ѭ����  ʹ��ѭ��ֵ�ݼ� ��Ϊÿ�ΰ�С��a[j]��ֵ����
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		//��ѭ��  ȷ�����Ƚϴ���
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 1;               //ȷ����ǰ�������Ƿ�����
				Swap(&a[j], &a[j + 1]);
			}
		}
		if (flag == 0)
			break;
	}
}
//����
int GetMidIndex(int *a, int begin, int end)//������ȡ��"�Ż�
{
	int mid = begin + ((end - begin) >> 1);//��λ����ȳ��������
	//begin mid end                         ��ȡ3�������м���
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
//��ͨ��hoare�汾
int PartSort1(int *a, int begin, int end)
{
	assert(a);
	int mid = GetMidIndex(a, begin, end);//ѡ��һ���õĻ�׼ֵ������ȡ�У�
	Swap(&a[mid], &a[end]);//����ʹ��ѡ����ֵ��Ϊ ��׼ֵ
	int key = a[end];

	int last = end;//��¼����һ��λ�÷��㷵�ػ�׼ֵ
	while (begin < last)
	{
		while (begin < last&&a[begin] <= a[end])//����ұ�key���ֵ
		{
			begin++;
		}
		while (begin < last&&a[last] >= a[end])//�ұ��ұ�keyС��ֵ
		{
			last--;
		}
		Swap(&a[begin], &a[last]);//����
	}
	Swap(&a[begin], &a[end]);//ȫ���������ɻ�׼ֵ�ŵ����С�����ұߴ�������λ��
	return begin;//���ػ�׼ֵ
}
//�ڿӷ�
int PartSort2(int *a, int begin, int end)
{
	assert(a);
	int mid = GetMidIndex(a, begin, end);//ͬ��
	Swap(&a[mid], &a[end]);
	int key = a[end];
	int pit = a[end];//ȷ����׼ֵ
	while (begin < end)
	{
		//������ұȻ�׼���һ��Ԫ�أ��������
		while (begin < end&&a[begin] <= key)
		{
			begin++;  //�ҹ�һ���͵���
		}
		a[end] = a[begin];
		//���ұ��ұȻ�׼С��һ��Ԫ�أ���������Ǹ��Ȼ�׼ֵ���Ԫ�ص�λ�� �������ÿӽ���������
		while (begin < end&&a[end] >= key)
		{
			end--;//�ҹ�һ���͵ݼ�
		}
		a[begin] = a[end];
	}
	//���ó����Ļ�׼ֵ��������� ����ʱ��a[begin]==a[end]
	//����Ϊ�Ȼ�׼ֵ���ʱ�ŵ���׼ֵ���ұ�����a[begin]=key
	a[begin] = key;
	//���ػ�׼ֵ������������������������
	return begin;
}
//˫ָ�뷨
int PartSort3(int *a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);// ����ȡ�С�
	Swap(&a[end], &a[mid]); //ȡ�û�׼ֵ
	int prev = begin - 1; ///Ҫ�Ƚϵ�ǰһ��ֵ������ȷ����Щ�������ڻ�׼ֵ ���Ȼ�׼ֵ���ֵ�����ڽ����������ﵽ��߶���С�ڻ�׼ֵ��ԭ��
	int cur = begin;  //Ҫ�Ƚϵ�ֵ
	int key = a[end]; //��׼ֵ
	while (cur < end) //ȷ��ѭ������ ����һֱ��С
	{
		//++prev==cur˵�����ǵ�һ��Ԫ�أ�����Ҫ����������ʱһ������С�ڻ�׼ֵ������
		if (a[cur] < key && ++prev != cur)  //�ҵ�С�ڻ�׼ֵ��ֵ������++prev���Ĵ��ڻ�׼ֵ��ֵ
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[++prev], &a[end]);//����׼ֵ����++prev�����Ĵ��ڻ�׼ֵ��ֵ���ﵽ��С�Ҵ�
	//���ػ�׼ֵ
	return prev;
}

void QuickSort(int *a, int left, int right)//����
{
	if (left >= right)//�ݹ���ڵ���С������ֻʣһ��ֵʱ����������
		return;

	//if (right - left + 1 < 10)//С�����Ż�
	//{
	//	InsertSort(a + left, right - left + 1);
	//}
	else
	{
		int div = PartSort2(a, left, right);
		//��������������
		QuickSort(a, left, div - 1);
		//��������������
		QuickSort(a, div + 1, right);
	}
}
void QuickSortOP(int *a, int left, int right)//�����Ż���-������С����
{
	if (left >= right)
		return;
	if (right - left + 1 < 10)//С�����Ż�
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
//���ŷǵݹ�
void Quick_SortNoR(int *a, int left, int right)
{
	Stack st;
	StackInit(&st);         // ����ջ��ʵ�ַǵݹ�
	StackPush(&st, right);//ѹ��������ĩβ     ��ѹ���
	StackPush(&st, left);//ѹ�������俪ʼ    
	while (StackEmpty(&st) != 0)
	//  ��ջΪ��ʱ����ֻ��һ������ʱ�� ���ź����ʱ��û�д���2��ֵ��������û�ź����ʱ��
	{
		//ÿ�δ���һ�������ֵ��Ϊ������һֱ���Ҵ���Ȼ�������ҵ���Ȼ�������󡣣�RVL������
		int begin = StackTop(&st);//���俪ʼ
		StackPop(&st);
		int end = StackTop(&st);//�������
		StackPop(&st);
		//���ֺ�����
		int div = PartSort1(a, begin, end); //ȷ����׼ֵ������
		if (begin < div)  //�����仹�д���1��Ԫ��ʱ����ջ������  ����
		{
			StackPush(&st, div - 1);  //ѹ��������β
			StackPush(&st, begin);//ѹ��������ͷ

		}
		if (div + 1 < end) ////�����仹�д���1��Ԫ��ʱ����ջ������
		{
			StackPush(&st, end);//ѹ��������β
			StackPush(&st, div + 1);//ѹ��������ͷ
		}
	}

}
//�鲢����
void Merge(int*a, int begin1, int end1, int begin2, int end2, int *tmp)  //�ϲ�
{
	assert(a&&tmp);
	int start = begin1;
	int index = begin1;//��begin1��ʼ�ϲ�
	//��������������ĺϲ�����
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
	//ʣ���δ�������ݿ�����ȥ
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//��tmp�ϲ��Ŀռ俽����a��
	memcpy(a + start, tmp + start, sizeof(int)*(n));

}
void _MergeSort(int *a, int begin, int end, int *tmp)
{
	assert(a&&tmp);
	if (begin >= end)
	{
		return;
	}
	int mid = begin + ((end - begin) >> 1);//��λ����ȳ��������
	//�ֶ�  ��begin mid����mid+1 end���������һ������
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	Merge(a, begin, mid, mid + 1, end, tmp);  //�ϲ�
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
//����
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
	// �������
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
	//��������
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
	//����
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
	//ѡ������

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
	//��������

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
	//�鲢����

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