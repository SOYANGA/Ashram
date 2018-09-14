#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//typedef int HTKeyType;
typedef char* HTKeyType;
typedef int HTValueType;

enum State
{
	EMPTY = 0,
	EXIST = 1,
	DELETE = 2,
};

typedef struct HashData
{
	enum State	_state;
	HTKeyType	_key;
	HTValueType _value;
}HashData;

typedef struct HashTable
{
	HashData* _tables;
	size_t _len;   // 长度
	size_t _size;  // 有效数据个数
}HashTable;

void HTInit(HashTable* ht, size_t len);
void HTDestroy(HashTable* ht);

int HTInsert(HashTable* ht, HTKeyType key, HTValueType value);
int HTRemove(HashTable* ht, HTKeyType key);
HashData* HTFind(HashTable* ht, HTKeyType key);

size_t HTSize(HashTable* ht);
int HTEmpty(HashTable* ht);

void TestHashTable();
void TestHashSTable();
