#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void Test()
{
	Stack stk;
	StackInit(&stk);
	StackPush(&stk, 1);
	StackPush(&stk, 2);
	StackPush(&stk, 3);
	StackPush(&stk, 4);
	printf("%d\n", StackSize(&stk));
	while(StackEmpty(&stk)!= 0)
	{
		printf("%d ", StackTop(&stk));
		StackPop(&stk);
	}
	printf("\n");
	StackDestory(&stk);
}

int main()
{
	Test();
	system("pause");
	return 0;
}