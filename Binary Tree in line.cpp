// Binary Tree in line.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <math.h>
#define Telemtype int
using namespace std;




//Stack
#define Status int
#define SElemType Bitree
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 100
#define ERRO 0
#define DONE 1
#pragma warning(disable:4996)

typedef struct LinkStackNode//head pointer as top pointer,don't need two(base and top)
//because when delete and insert we don't need to search for top pointer
{
	SElemType data;
	LinkStackNode *next;
}LSNode, *LinkStack;


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

bool IsEmpty(LinkStack &L)
{
	if (L->next == NULL) return true;
	else return false;
}
//Stack



//Binary Tree
typedef struct BiTreeNode
{
	Telemtype data;
	BiTreeNode* Lchild;
	BiTreeNode* Rchild;
}BiTNode,*Bitree;//just like two pointer linklist

void Visit(Bitree T)
{
	printf("%d ", &T->data);
}

//Preorder Traversal
void PreorderTraversal(Bitree BT)
{
	Bitree T = BT;
	LinkStack S;
	Init_LinkStack(S);
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Visit(T);
			Push(S, T);
			T = T->Lchild;
		}
		if (!IsEmpty(S))
		{
			Pop(S,T);
			T = T->Rchild;
		}
	}
}

//Midorder Traversal
void MidorderTraversal(Bitree BT)
{
	Bitree T = BT;
	LinkStack S;
	Init_LinkStack(S);

}






int main()
{

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
