/*************************************************************************
	> File Name: test.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年10月07日 星期日 22时49分39秒
 ************************************************************************/

#include"Seqlist.h"

void test()
{
	SeqList seq;//int
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
}
int main()
{
	test();
	return 0;
}
