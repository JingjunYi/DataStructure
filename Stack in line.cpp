// Stack in line.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#define Status int
#define SElemType int
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 100
#define ERRO 0
#define DONE 1
#pragma warning(disable:4996)
using namespace std;


typedef struct LinkStackNode//head pointer as top pointer,don't need two(base and top)
//because when delete and insert we don't need to search for top pointer
{
	SElemType data;
	LinkStackNode *next;
}LSNode,*LinkStack;


Status Init_LinkStack(LinkStack &L)//Init_LinkStack
{
	L = (LinkStack)malloc(sizeof(LinkStackNode));
	L->next = NULL;
	return DONE;
}

Status Push(LinkStack &L, SElemType &x)//insert at head
{
	LinkStack s;
	s = (LinkStack)malloc(sizeof(LinkStackNode));
	s->data = x;
	s->next = L->next;
	L->next = s;
	return DONE;
}

Status Pop(LinkStack &L, SElemType &x)
{
	if (L->next == NULL) return ERRO;
	x = L->next->data;
	L->next = L->next->next;
	return DONE;
}

Status GetTop(LinkStack &L, SElemType &x)
{
	if (L->next == NULL) return ERRO;
	x = L->next->data;
	return DONE;
}

void Show_LinkStack(LinkStack &L)
{
	if (L->next == NULL) return;
	LinkStack p;
	p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}




int main()
{
	LinkStack L;
	Init_LinkStack(L);
	for (int i = 1; i <= 8; i++)
	{
		Push(L, i);
	}
	Show_LinkStack(L);
	
	cout << endl;

	int a;
	Pop(L, a);
	Show_LinkStack(L);

	cout << endl;
	
	GetTop(L, a);
	cout << a << endl;



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
