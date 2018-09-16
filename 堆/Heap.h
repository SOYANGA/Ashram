#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap*hp, HPDataType*a, int n);
void HeapDestory(Heap*hp);

void HeapPush(Heap*hp, HPDataType x);
void HeapPop(Heap*hp);
void Heapprint(Heap*hp);
HPDataType HeapTop(Heap*hp);
int HeapSize(Heap*hp);
int HeapEmpty(Heap*hp);

//不直接调Heaps
void HeapSort(HPDataType*a, int n);
void TestHeap();
