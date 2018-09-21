#define _CRT_SECURE_NO_WARNINGS 1
#include "StackByTwoQueue.h"
void test()
{
	StackByTwoQueue sbtq;
	StackByTwoQueueInit(&sbtq);
	StackByTwoQueuePush(&sbtq, 1);
	StackByTwoQueuePush(&sbtq, 2);
	StackByTwoQueuePush(&sbtq, 3);
	StackByTwoQueuePush(&sbtq, 4);
	printf("%d\n", StackByTwoQueueSize(&sbtq));
	while (StackByTwoQueueEmpty(&sbtq) != 0)
	{
		printf("%d ", StackByTwoQueueTop(&sbtq));
		StackByTwoQueuePop(&sbtq);
	}
	printf("\n");
	StackByTwoQueueDestory(&sbtq);
}
int main()
{
	test();
	system("pause");
	return 0;
}