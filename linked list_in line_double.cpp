// linked list_in line_double.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#define Status int
#define ElemType int
#define ERRO 0
#define DONE 1
#pragma warning(disable:4996)
using namespace std;


typedef struct DoubleLinkNode
{
	ElemType data;
	DoubleLinkNode* prior;
	DoubleLinkNode* next;
}DuLinkNode,*DuLinkList;

Status Create_DoubleLinkList(DuLinkList &L,int n)
{
	L = (DuLinkList)malloc(sizeof(DuLinkNode));
	L->prior = NULL;
	L->next = NULL;
	DuLinkList p;
	for (int i = n; i > 0; i--)
	{
		if (i == n)
		{
			p = (DuLinkList)malloc(sizeof(DuLinkNode));
			p->data = i;
			p->next = L->next;
			p->prior = L;
			L->next = p;
		}
		else
		{
			p = (DuLinkList)malloc(sizeof(DuLinkNode));
			p->data = i;
			p->next = L->next;
			p->next->prior = L->next;
			p->prior = L;
			L->next = p;
		}
	}
	return DONE;
}

//Status Insert_DoubleLinkList(DuLinkList &L,int i,ElemType x)//insert after no.i node
//{
//	DuLinkList p, s;
//	p = L->next;
//	int j = 1;
//	while (p&&j < i)
//	{
//		p = p->next;
//		j++;
//	}
//	if (!p || j > i) return ERRO;
//	s->data = x;
//	s->next = p->next;
//	p->next->prior = s;
//	s->prior = p;
//	p->next = s;
//	return DONE;
//}

void Show_DoubleLinkList(DuLinkList &L)
{
	DuLinkList p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}




int main()
{
	DuLinkList L;
	Create_DoubleLinkList(L, 3);
	Show_DoubleLinkList(L);
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
