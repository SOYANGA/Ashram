#define _CRT_SECURE_NO_WARNINGS 1
#include"ShareStack.h"

void ShareSackInit(ShareSack* ps)
{
	assert(ps);
	ps->_arry = (SSDataType*)malloc(sizeof(SSDataType)* 3);
	if (ps->_arry == NULL)
	{
		exit(EXIT_FAILURE);
	}
	ps->Top1 = 0;
	ps->Top2 = 1;
	ps->cacity = 3;
}
void ShareSackDestory(ShareSack* ps)
{
	assert(ps);
	ps->cacity = ps->Top1 = ps->Top2 = 0;
	free(ps->_arry);
	ps->_arry = NULL;
}

void ShareSackPush(ShareSack* ps, SSDataType x, int which)
{
	assert(ps);
	if (ps->Top1 >= ps->cacity || ps->Top2 >= ps->cacity)
	{
		ps->_arry = (SSDataType*)realloc(ps->_arry, sizeof(SSDataType)*(ps->cacity) * 2);
		ps->cacity *= 2;
	}
	if (which == 1)
	{
		ps->_arry[ps->Top1] = x;
		ps->Top1 += 2;
	}
	else
	{
		ps->_arry[ps->Top2] = x;
		ps->Top2 += 2;
	}
}
void ShareSackPop(ShareSack* ps, int which)
{
	assert(ps);
	if (which == 1)
	{
		assert(ps->Top1 >= 0);
		ps->Top1 -= 2;
	}
	else
	{
		assert(ps->Top2 >= 0);
		ps->Top2 -= 2;
	}
}
SSDataType ShareSackTop(ShareSack* ps, int which)
{
	assert(ps);
	if (which == 1)
	{
		assert(ps->Top1 >= 0);
		return ps->_arry[ps->Top1-2];
	}
	else
	{
		assert(ps->Top2 >= 0);
		return ps->_arry[ps->Top2-2];
	}
}
//¿ÕÎª0
//·Ç¿ÕÎª1
int ShareSackEmpty(ShareSack* ps, int which)
{
	assert(ps);
	if (which == 1)
	{
		return ps->Top1 == 0 ? 0 : 1;
	}
	else
	{
		return ps->Top2 == 1 ? 0 : 1;
	}
}
int ShareSackSize(ShareSack* ps, int which)
{
	assert(ps);
	if (which == 1)
		return (ps->Top1/2);
	else
		return (ps->Top2-1)/2;
}
void Test()
{
	ShareSack ss;
	ShareSackInit(&ss);
	ShareSackPush(&ss, 1, 1);
	ShareSackPush(&ss, 2, 1);
	ShareSackPush(&ss, 3, 1);
	ShareSackPush(&ss, 4, 1);
	ShareSackPush(&ss, 1, 2);
	ShareSackPush(&ss, 2, 2);
	ShareSackPush(&ss, 3, 2);
	ShareSackPush(&ss, 4, 2);
	printf("%d\n",ShareSackSize(&ss,1));
	while (ShareSackEmpty(&ss,1) != 0)
	{
		printf("%d ", ShareSackTop(&ss,1));
		ShareSackPop(&ss,1);
	}
	printf("\n");	
	printf("%d\n", ShareSackSize(&ss, 2));
	while (ShareSackEmpty(&ss, 2) != 0)
	{
		printf("%d ", ShareSackTop(&ss, 2));
		ShareSackPop(&ss, 2);
	}
	printf("\n");
	ShareSackDestory(&ss);



}