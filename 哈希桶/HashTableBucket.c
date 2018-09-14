#define _CRT_SECURE_NO_WARNINGS 1
#include "HashTableBucket.h"
size_t GetNextPrimeNum(size_t cur)
{
	//const int _PrimeSize = 28;
	static const unsigned long _PrimeList[28] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul, 1543ul, 3079ul,
		6161ul, 12289ul, 24593ul, 49157ul, 98317ul, 196613ul,
		393241ul, 786433ul, 1572869ul, 3145739ul, 6291469ul, 12582917ul,
		25165843ul, 50331653ul, 100663319ul, 201326611ul, 402653189ul,
		805306457ul, 1610612741ul, 3221225473ul, 4294967291ul
	};
	for (size_t i = 0; i < 28; ++i)
	{
		if (_PrimeList[i]>cur)
		{
			return _PrimeList[i];
		}
	}
	return _PrimeList[27];
}
void HTBInit(HTB* htb, size_t len)
{
	assert(htb);
	htb->_len = GetNextPrimeNum(len);
	htb->_tables = (HashNode**)malloc(sizeof(HashNode*)*htb->_len);
	htb->_size = 0;
	for (size_t i = 0; i < htb->_len; i++)
	{
		htb->_tables[i] = NULL;
	}
}
void HTBDestory(HTB* htb)
{
	assert(htb);
	size_t i = 0;
	for (; i < htb->_len; i++)
	{
		HashNode* cur = htb->_tables[i];
		HashNode*next = NULL;
		while (cur)
		{
			next = cur->_next;
			free(cur);
			cur = next;
		}
	}
	free(htb->_tables);
	htb->_tables = NULL;
}
HashNode* BuyHashNode(HTBKeyType key, HTBValueType value)
{
	HashNode *node = (HashNode*)malloc(sizeof(HashNode));
	node->_key = key;
	node->_next = NULL;
	node->_value = value;
	return node;
}
int HashFanc(HTB* htb, HTBKeyType key)
{
	assert(htb);
	return key%htb->_len;
}
void HashInsertCapacity(HTB* htb)
{
	if ((10*htb->_size)/(htb->_len)==7)
	{
		HTB newhtb;
		HTBInit(&newhtb, htb->_len);
		for (size_t i = 0; i < htb->_len; i++)
		{
			HashNode* ptr = htb->_tables[i];
			while (ptr)
			{
				HashNode* cur = ptr;
				ptr = ptr->_next;
				cur->_next = newhtb._tables[HashFanc(&newhtb, cur->_key)];
				newhtb._tables[HashFanc(&newhtb, cur->_key)] = cur;
			}
		}
		free(htb->_tables);
		htb->_len = newhtb._len;
		htb->_tables = newhtb._tables;
	}
}
int HTBInsert(HTB* htb, HTBKeyType key, HTBValueType value)
{
	assert(htb);
	HashInsertCapacity(htb);
	int index = HashFanc(htb, key);
	HashNode *cur = htb->_tables[index];
	while (cur)//查看是否已经拥有
	{
		if (cur->_key == key)
		{
			cur->_value++;
			return 1;
		}
		cur = cur->_next;
	}
	HashNode* newnode = BuyHashNode(key, value);
	//没有,创结点 头插
	newnode->_next = htb->_tables[index];
	htb->_tables[index] = newnode;
	htb->_size++;
	return 1;
}
int HTBRemove(HTB* htb, HTBKeyType key)
{
	assert(htb);
	int index = HashFanc(htb, key);
	HashNode* cur = htb->_tables[index];
	HashNode* next = NULL;
	HashNode* prev = NULL;
	while (cur)
	{
		next = cur->_next;
		if (cur->_key == key)
		{
			if (cur->_value == 1)
			{
				if (prev == NULL)
				{
					htb->_tables[index] = next;
					free(cur);
					htb->_size--;
					return 1;
				}
				else
				{
					prev->_next = next;
					free(cur);
					htb->_size--;
					return 1;
				}
			}
			else
			{
				cur->_value--;
				return 1;
			}
		}
		prev = cur;
		cur = next;
	}
	return -1;
}
HashNode* HTBFind(HTB* htb, HTBKeyType key)
{
	assert(htb);
	int index = HashFanc(htb, key);
	HashNode *cur = htb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void HTBPrint(HTB* htb)
{
	assert(htb);
	size_t i = 0;
	for (; i < htb->_len; i++)
	{
		printf("[%u]->", i);
		HashNode* cur = htb->_tables[i];
		while (cur)
		{
			printf("%d:%d->", cur->_key, cur->_value);
			cur = cur->_next;
		}
		printf("%s \n", "NULL");
	}
	printf("\n");
}
//int HTBSize(HTB* htb)
//{
//
//}
//int HTBEmpty(HTB* htb)
//{
//
//}

void TestHashTableBucket()
{
	HTB htb;
	clock_t start = 0;
	clock_t finish = 0;
	double  duration;
	HTBInit(&htb, 10);
	//HTBInsert(&htb, 1, 1);
	//HTBInsert(&htb, 1, 1);
	//HTBInsert(&htb, 2, 1);
	//HTBInsert(&htb, 4, 1);
	//HTBInsert(&htb, 5, 1);
	//HTBInsert(&htb, 6, 1);
	//HTBInsert(&htb, 7, 1);
	//HTBInsert(&htb, 8, 1);
	HTBPrint(&htb);
	for (int i = 0; i < 1000; i++)
	{
		HTBInsert(&htb, i, 1);
	}
	HTBPrint(&htb);
	//if (HTBFind(&htb, 11))
	//{
	//	printf("%d:%d \n", HTBFind(&htb, 11)->_key, HTBFind(&htb, 11)->_value);
	//}
	HTBDestory(&htb);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f \n", duration);
}