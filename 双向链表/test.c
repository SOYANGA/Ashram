#define _CRT_SECURE_NO_WARNINGS 1
#include"DoubleList.h"
void Test()
{
	List Dl;
	ListInit(&Dl);
	ListInsert(Dl._head, 1);
	ListInsert(Dl._head, 2);
	ListInsert(Dl._head, 3);
	ListInsert(Dl._head, 4);
	ListPrint(&Dl);
	printf("\n");


	ListErase(&Dl, ListFind(&Dl, 1));
	ListErase(&Dl, ListFind(&Dl, 2));
	ListPrint(&Dl);
	printf("\n");

	ListPushBack(&Dl, 5);
	ListPushFront(&Dl, 2);
	ListPrint(&Dl);
	printf("\n");

	ListPopBack(&Dl);
	ListPopFront(&Dl);
	ListPrint(&Dl);
	printf("\n");

	printf("%d\n", ListSize(&Dl));

	printf("链表是否为空？：%d \n", ListEmpty(&Dl));
	ListPopFront(&Dl);
	ListPopFront(&Dl);
	ListPopFront(&Dl);
	printf("链表是否为空？：%d \n", ListEmpty(&Dl));
}
int main()
{
	Test();
	system("pause");
	return 0;
}