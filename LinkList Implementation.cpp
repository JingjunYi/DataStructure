// LinkList Implementation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <string.h>
#include <math.h>
#pragma warning (disable:4996)
#define Status int
#define DONE 1
#define ERRO 0
#define Elemtype int
using namespace std;



void menu()
{
	printf("1.Create    2.Insert\n");
	printf("3.Delete    4.SearchKey\n");
	printf("5.GetElem   6.Display\n");
	printf("7.Destroy   8.SetValue\n");
	printf("0.exit\n");
}


typedef struct LinkNode
{
	Elemtype data;
	LinkNode* next;
}LinkNode,*LinkList;


Status Create(LinkList &L,int n)
{
	if (n == 0) return ERRO;
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

Status Insert(LinkList &L, int i, Elemtype x)
{
	if (L->next == NULL || L == NULL) return ERRO;
	LinkList p,s;
	p = L;
	int j = 0;
	while (p&&j < i - 1)//find node before insert position
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERRO;
	s = (LinkList)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
	return DONE;
}

Status Delete(LinkList &L, int i, Elemtype &x)
{
	if (L->next == NULL || L == NULL) return ERRO;
	LinkList p;
	p = L;
	int j = 0;
	while (p&&j < i - 1)//find node before delete position
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERRO;
	x = p->next->data;
	p->next = p->next->next;
	return DONE;
}

Status SearchKey(LinkList &L, Elemtype x,int *positions)//search key and return its position
{
	int i = 1;
	bool flag = false;
	LinkList p = L->next;
	int j = 1;
	while (p)
	{
		if (x == p->data)
		{
			positions[j] = i;
			j++;
			flag = true;
		}
		p = p->next;
		i++;
	}
	positions[0] = j - 1;
	if (!flag) return ERRO;
	else return j;
}

Status GetElem(LinkList &L, int position, Elemtype &x)//search position and return its key
{
	if (L->next == NULL || L == NULL) return ERRO;
	LinkList p = L;
	int j = 0;
	while (p&&j < position)
	{
		p = p->next;
		j++;
	}
	if (!p || j > position) return ERRO;
	x = p->data;
	return DONE;
}

Status Display(LinkList &L)
{
	if (L == NULL) return ERRO;
	else
	{
		if (L->next == NULL) return ERRO;
		LinkList p = L->next;
		while (p)
		{
			printf("%d ", p->data);
			p = p->next;
		}
		return DONE;
	}
}

Status Destroy(LinkList &L)
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

Status SetValue(LinkList &L,int position,Elemtype &x)
{
	LinkList p = L;
	int j = 0;
	while (p&&j < position - 1)
	{
		p = p->next;
	}
	if (!p || j > position - 1) return ERRO;
	p = p->next;
	p->data = x;
	return DONE;
}




int main()
{
	LinkList L;
	menu();
	int choice = 0;
	Elemtype x = 0; int position = 0;
	int length = 0;
	int positions[100];
	printf("Note that punctuation is in English\n\n\n");
	for (;;)
	{
		printf("Please input menu number: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Please input the length of new list(int): ");
			scanf("%d", &length);
			Create(L, length);
			printf("Done\n");
			//Display(L);
			break;
		case 2:
			printf("Please input what and where you want to insert(int,int): ");
			scanf("%d,%d", &x, &position);
			if (Insert(L, position, x))
			{
				printf("Done\n");
				//Display(L);
			}
			else
			{
				printf("Erro\n");
			}
			break;
		case 3:
			printf("Please input where you want to delete(int): ");
			scanf("%d", &position);
			if (Delete(L, position, x))
			{
				printf("Done\n");
				//Display(L);
			}
			else
			{
				printf("Erro\n");
			}
			break;
		case 4:
			printf("Please input Key(Elemtype): ");//search key return its position
			scanf("%d", &x);
			if (SearchKey(L, x, positions))
			{
				printf("Done\n");
				cout << "positions in list: ";
				for (int i = 1; i <= positions[0]; i++)
				{
					cout << positions[i]<<" ";
				}
				cout << endl;
			}
			else
			{
				printf("Erro\n");
			}
			break;
		case 5:
			printf("Please input position(int): ");//search position return its key
			scanf("%d", &position);
			if (GetElem(L, position, x))
			{
				printf("Done\n");
				printf("%d\n", x);
			}
			else
			{
				printf("Erro\n");
			}
			break;
		case 6:
			if(!Display(L))
			{
				printf("Erro");
			}
			cout << endl;
			break;
		case 7:
			Destroy(L);
			printf("Done\n");
			break;
		case 8:
			printf("Please input where you want to set and set to what(int,int): ");
			scanf("%d,%d", &position, &x);
			if (SetValue(L, position, x))
			{
				printf("Done\n");
			}
			else
			{
				printf("Erro\n");
			}
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}
	}
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
