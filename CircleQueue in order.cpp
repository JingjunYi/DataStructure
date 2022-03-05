// CircleQueue in order.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#define Status int
#define QElemType int
#define QUEUE_INIT_SIZE 100
#define QUEUEINCREMENT 100
#define ERRO 0
#define DONE 1
#pragma warning(disable:4996)
using namespace std;


typedef struct CircleSqQueue//no realloc space
{
	QElemType *base;
	int front;
	int rear;
}CSQueue;

Status Init_CSQueue(CSQueue &Q)
{
	Q.base = (QElemType *)malloc(QUEUE_INIT_SIZE * sizeof(QElemType));
	if (!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;//structure in order pointer always point at first block
	//structure in line pointer always point at last node
	return DONE;
}

Status En_CSQueue(CSQueue &Q, QElemType &x)
{
	if ((Q.rear + 1) % QUEUE_INIT_SIZE == Q.front) return ERRO;//adjust if is fullfil
	Q.base[Q.rear] = x;
	Q.rear = (Q.rear + 1) % QUEUE_INIT_SIZE;//if come to the last block,when insert use % to return head
	return DONE;
}

Status De_CSQueue(CSQueue &Q, QElemType &x)
{
	if (Q.front == Q.rear) return ERRO;
	x = Q.base[Q.front];
	Q.front = (Q.front + 1) % QUEUE_INIT_SIZE;//just the same as insert process
	return DONE;
}

void Show_CSQueue(CSQueue &Q)
{
	if (Q.front == Q.rear) return;
	for (int i = Q.front; i < Q.rear; i++)
	{
		printf("%d ", Q.base[i]);
	}
}




int main()
{
	CSQueue Q;
	Init_CSQueue(Q);
	for (int i = 1; i <= 8; i++)
	{
		En_CSQueue(Q, i);
	}
	Show_CSQueue(Q);

	cout << endl;

	int a = 0;
	De_CSQueue(Q, a);
	Show_CSQueue(Q);


    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
