#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "Stack.h"


void TestInserSort();//����ϣ��������Ժ���
void TestSelectSort();//ѡ��������Ժ���
void TestHeapSort();//���Ų��Ժ���
void TestBubbleSort();//ð��������Ժ���
void TestQuickSort();//���Ų��Ժ���
void TestQuick_SortNoR();//���ŷǵݹ���Ժ���

void TestMergeSort();//�鲢���Ժ���

void Compare_QuickSort();//���ŵݹ�ǵݹ�Ч�ʱȽϺ���
void Compare_AllSort();//�������ܺ���
void Print();//��ӡ����


//��������
void InsertSort(int *a, int n);//ֱ�Ӳ�������
void ShellSort();//ϣ������
//ϣ����˳��ֱ�Ӳ�������Ļ������Ż�����ֱ�Ӳ�����˳��Ч�ʸߺöࡣ
void SelectSort(int *a, int n);//ѡ������
void HeapSort(int *a, int n);//����
void BulbbleSort(int *a, int n);//ð������
void QuickSort(int *a, int left, int right);//����
void QuickSortOP(int *a, int left, int right);//�����Ż���
void Qick_SortNoR(int *a, int left, int right);//���ŷǵݹ�
//˫ָ��
//�ڿ�
//��ͨ��
void MergeSort(int *a, int n);//�鲢����
