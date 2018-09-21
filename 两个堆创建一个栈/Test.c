#define _CRT_SECURE_NO_WARNINGS 1
#include "QueueByTwoStack.h"
void Test()
{
	QueueByTwoStack qbts;
	QueueByTwoStackInit(&qbts);
	QueueByTwoStackPush(&qbts, 1);
	QueueByTwoStackPush(&qbts, 2);
	QueueByTwoStackPush(&qbts, 3);
	QueueByTwoStackPush(&qbts, 4);
	printf("%d\n", QueueByTwoStackSize(&qbts));
	while (QueueByTwoStackEmpty(&qbts) != 0)
	{
		printf("%d ", QueueByTwoStackFront(&qbts));
		QueueByTwoStackPop(&qbts);
	}
	printf("\n");
	QueueByTwoStackDestory(&qbts);
}
int main()
{                                                                   
	Test();
	system("pause");
	return 0;
}