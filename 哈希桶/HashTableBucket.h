#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

//typedef char* HTBKeyType;
//typedef char* HTBValueType;

//typedef char* HTBKeyType;
//typedef int HTBValueType;

typedef int HTBKeyType;
typedef int HTBValueType;

typedef struct HashNode
{
	struct HashNode* _next;
	HTBKeyType _key;
	HTBValueType _value;
}HashNode;

typedef struct HashTableBucket
{
	HashNode** _tables;
	size_t _size;
	size_t _len;
}HTB;

void HTBInit(HTB* htb, size_t len);
void HTBDestory(HTB* htb);

int HTBInsert(HTB* htb, HTBKeyType key, HTBValueType value);
int HTBRemove(HTB* htb, HTBKeyType key);
HashNode* HTBFind(HTB* htb, HTBKeyType key);

int HTBSize(HTB* htb);
int HTBEmpty(HTB* htb);

void TestHashTableBucket();