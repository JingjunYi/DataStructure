// linked list_in line.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <math.h>
#define Status int
#define ElemType int
#define ERRO 0
#define DONE 1
#pragma warning(disable:4996)
using namespace std;



typedef struct LinkNode
{
	ElemType data;
	LinkNode* next;
}LinkNode,*LinkList;


Status Create_LinkList(LinkList &L,int n)
{
	LinkList p; 
	L = (LinkList)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = n; i > 0; i--)
	{
		p = (LinkList)malloc(sizeof(LinkNode));
		p->data = i;
		p->next = L->next;
		L->next = p;
	}//every time insert from head
	return DONE;
}

Status GetElem_LikList(LinkList &L, int i, ElemType &x)
{
	LinkList p;
	p = L->next;
	int j = 1;//p is the first node after head
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}//find no.i node
	if (!p || j > i) return ERRO;
	x = p->data;
	return DONE;
}

Status Insert_LinkList(LinkList &L, int i, ElemType x)//insert before no.i node
{
	LinkList p, s;
	p = L;
	int j = 0;//p is the first node
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}//finde node before no.i
	if (!p || j > i - 1) return ERRO;
	s = (LinkList)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
	return DONE;
}

Status Delete_LinkList(LinkList &L, int i, ElemType &x)
{
	LinkList p;
	p = L;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERRO;
	LinkList q = p->next;
	x = q->data;
	p->next = q->next;
	free(q);
	return DONE;
}

Status Destroy_LinkList(LinkList &L)
{
	LinkList p;
	LinkList q;
	p = L;
	while (p->next)
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}
	free(L);
	L = NULL;
	return DONE;
}

void Show_LinkList(LinkList &L)
{
	LinkList p;
	if (L == NULL)
	{
		printf("not exit\n");
	}
	else
	{
		p = L->next;
		while (p)
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
}




int main()
{
	LinkList L;
	Create_LinkList(L,3);
	Show_LinkList(L);

	cout << endl;
	
	Insert_LinkList(L, 1, 0);
	Show_LinkList(L);
	
	cout << endl;

	ElemType x;
	Delete_LinkList(L, 1, x);
	Show_LinkList(L);

	cout << endl;

	Destroy_LinkList(L);
	Show_LinkList(L);

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
