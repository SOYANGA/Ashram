#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
void test()
{
	Queue que;
	QueueInit(&que);
	QueuePush(&que, 1);
	QueuePush(&que, 2);
	QueuePush(&que, 3);
	QueuePush(&que, 4);
	printf("%d\n", QueueSize(&que));
	while (QueueEmpty(&que) != 0)
	{
		printf("%d ", QueueFront(&que));
		QueuePop(&que);
	}
	printf("\n");
	QueueDestory(&que);
}
int main()
{
	test();
	system("pause");
	return 0;
}