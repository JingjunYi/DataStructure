// Queue in line.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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



typedef struct LinkQueueNode
{
	QElemType data;
	LinkQueueNode* next;
}LinkQueueNode,*LinkQueueNodePtr;

typedef struct LinkQueue
{
	LinkQueueNodePtr front;
	LinkQueueNodePtr rear;//watch out rear point at the last node,not first block
}LinkQueue;//two pointer because every time front to rear waste time,just keep another pointer


Status Init_LinkQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;//make head pointer empty
	return DONE;
}

Status En_LinkQueue(LinkQueue &Q, QElemType &x)//only insert from rear
{
	LinkQueueNodePtr s = (LinkQueueNodePtr)malloc(sizeof(LinkQueueNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	return DONE;
}

Status De_LinkQueue(LinkQueue &Q, QElemType &x)//only delete from head
{
	if (Q.front == Q.rear) return ERRO;
	x = Q.front->data;
	Q.front = Q.front->next;
	return DONE;
}

void Show_LinkQueue(LinkQueue &Q)
{
	if (Q.front == Q.rear) return;
	LinkQueueNode *p = Q.front->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}





int main()
{
	LinkQueue Q;
	Init_LinkQueue(Q);
	for (int i = 1; i <= 8; i++)
	{
		En_LinkQueue(Q, i);
	}
	Show_LinkQueue(Q);

	cout << endl;

	int a = 0;
	De_LinkQueue(Q, a);
	Show_LinkQueue(Q);
    
	
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
