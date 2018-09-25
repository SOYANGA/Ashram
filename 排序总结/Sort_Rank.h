#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "Stack.h"


void TestInserSort();//插曲希尔排序测试函数
void TestSelectSort();//选择排序测试函数
void TestHeapSort();//堆排测试函数
void TestBubbleSort();//冒泡排序测试函数
void TestQuickSort();//快排测试函数
void TestQuick_SortNoR();//快排非递归测试函数

void TestMergeSort();//归并测试函数

void Compare_QuickSort();//快排递归非递归效率比较函数
void Compare_AllSort();//排序性能函数
void Print();//打印函数


//插入排序
void InsertSort(int *a, int n);//直接插入排序
void ShellSort();//希尔排序
//希尔排顺在直接插入排序的基础上优化，比直接插入排顺序效率高好多。
void SelectSort(int *a, int n);//选择排序
void HeapSort(int *a, int n);//堆排
void BulbbleSort(int *a, int n);//冒泡排序
void QuickSort(int *a, int left, int right);//快排
void QuickSortOP(int *a, int left, int right);//快排优化版
void Qick_SortNoR(int *a, int left, int right);//快排非递归
//双指针
//挖坑
//普通的
void MergeSort(int *a, int n);//归并排序
