#define _CRT_SECURE_NO_WARNINGS 1
#include "HashTable.h"
size_t GetNextPrime(size_t value)
{
	int i = 0;
	//const int _PrimeSize = 28;
	static const unsigned long _PrimeList[28] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};

	for (; i < 28; ++i)
	{
		if (_PrimeList[i] > value)
		{
			return _PrimeList[i];
		}
	}
	return _PrimeList[27];
}
void HTInit(HashTable* ht, size_t len)
{
	assert(ht);
	assert(ht > 0);
	len = GetNextPrime(len);
	size_t i = 0;
	ht->_tables = (HashData*)malloc(sizeof(HashData)*len);
	memset(ht->_tables, 0, sizeof(HashData)*len);
	ht->_len = len;
	ht->_size = 0;
	for (; i < len; i++)
	{
		ht->_tables[i]._state = EMPTY;
	}
}
void HTDestroy(HashTable* ht)
{
	assert(ht);
	free(ht->_tables);
	ht->_tables = NULL;
	ht->_len = ht->_size = 0;
}
size_t StrHash(const char* str)
{
	size_t hash = 0;
	size_t seed = 131;
	while (*str)
	{
		//hash += *str;
		hash = hash*seed + *str;
		++str;
	}
	//printf("%u\n", hash);
	return hash;
}
size_t HTHashFunc(HTKeyType key, size_t len)
{
	return StrHash(key) % len;
}
void CheckCapacity(HashTable* ht)//增容函数
{
	assert(ht);
	if ((10 * ht->_size) / ht->_len == 7)

	{
		HashTable newht;
		size_t i = 0;
		HTInit(&newht, ht->_len);
		for (; i < ht->_len; i++)
		{
			if (ht->_tables[i]._state == EXIST)
			{
				HTInsert(&newht, ht->_tables[i]._key, ht->_tables[i]._value);
			}
		}
		HTDestroy(ht);
		ht->_tables = newht._tables;
		ht->_len = newht._len;
		ht->_size = newht._size;
	}
}
int HTInsert(HashTable* ht, HTKeyType key, HTValueType value)//插入函数
{
	assert(ht);

	size_t i = 0;
	size_t index = HTHashFunc(key, ht->_len);
	size_t start = index;
	while (ht->_tables[index]._state == EXIST)
	{
		if (ht->_tables[index]._key = key)
		{
			ht->_tables[index]._value++;
			return 0;
		}
		else
		{
			i++;
			index = start + i;
			if (index == ht->_len)
				index = 0;

			/*++i;
			index = start + i*i;
			index %= ht->_len;*/
		}
	}
	ht->_tables[index]._key = key;
	ht->_tables[index]._value = value;
	ht->_tables[index]._state = EXIST;
	ht->_size++;
	return 1;
}
int HTRemove(HashTable* ht, HTKeyType key)
{
	assert(ht);
	HashData* data = HTFind(ht, key);
	if (data)
	{
		if (data->_value == 1)
		{
			data->_state = DELETE;
			ht->_size--;
			return 1;
		}
		else
		{
			data->_value--;
			return 1;
		}
	}
	else
	{
		return 0;
	}
}
HashData* HTFind(HashTable* ht, HTKeyType key)
{
	assert(ht);
	size_t index = HTHashFunc(key, ht->_len);
	while (ht->_tables[index]._state != EMPTY)
	{
		if (ht->_tables[index]._key = key)
		{
			if (ht->_tables[index]._state == EXIST)
			{
				return &(ht->_tables[index]);

			}
			else
			{
				return NULL;
			}
		}
		else
		{
			index++;
			if (index == ht->_len)
			{
				index = 0;
			}
		}
	}
	return NULL;
}

size_t HTSize(HashTable* ht)
{
	assert(ht);
	return ht->_size;
}
int HTEmpty(HashTable* ht)
{
	assert(ht);
	return ht->_size == 0;
}
void HTPrint(HashTable* ht)
{
	size_t i = 0;
	char* strState[3] = { "EMPTY", "EXIST", "DELETE" };
	assert(ht);
	for (; i < ht->_len; ++i)
	{
		printf("%s->table[%d]%s:%d\n", strState[ht->_tables[i]._state], i,
			ht->_tables[i]._key, ht->_tables[i]._value);
	}
	printf("\n");
}

//void TestHashTable()
//{
//	HashTable ht;
//	HashData* ret;
//	HTInit(&ht, 10);
//	HTInsert(&ht, 27, 1);
//	HTInsert(&ht, 37, 1);
//	HTInsert(&ht, 17, 1);
//	HTInsert(&ht, 13, 1);
//	HTInsert(&ht, 13, 1);
//	HTInsert(&ht, 13, 1);
//	HTInsert(&ht, 13, 1);
//	HTInsert(&ht, 13, 1);
//	HTPrint(&ht);
//	HTRemove(&ht, 17);
//	HTPrint(&ht);
//	HTInsert(&ht, 17, 1);
//	HTPrint(&ht);
//
//
//	ret = HTFind(&ht, 27);
//	ret->_value = 10;
//	HTPrint(&ht);
//	for (int i = 0; i < 10; ++i)
//	{
//		HTInsert(&ht, rand(), i);
//	}
//	HTPrint(&ht);
//	HTDestroy(&ht);
//}
void TestHashSTable()
{
	HashTable ht;
	HTInit(&ht, 10);
	char* strs1[] = { "insert", "insert", "insert", "insert", "insert", "sort", "insert", "sort", "find" };
	char* strs2[] = { "abcd", "bcad", "cbad", "cbad", "aad", "abc", "acb" };
	char* strs3[] = { "工具", "工具", "工具", "调试" };
	/*for (int i = 0; i < sizeof(strs1) / sizeof(char*); i++)
	{
		HTInsert(&ht, strs1[i], 1);
	}*/
	//for (int i = 0; i < sizeof(strs2) / sizeof(char*); i++)
	//{
	//	HTInsert(&ht, strs2[i], 1);
	//}
	for (int i = 0; i < sizeof(strs3) / sizeof(char*); i++)
	{
		HTInsert(&ht, strs3[i], 1);
	}
	HTPrint(&ht);
	HTRemove(&ht,"工具");
	HTRemove(&ht, "工具");
	HTRemove(&ht, "工具");
	HTRemove(&ht, "工具");
	HTPrint(&ht);
	HTDestroy(&ht);

}