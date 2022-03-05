// SqStack  Implementation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#pragma warning (disable:4996)
#define Status int
#define DONE 1
#define ERRO 0
#define SElemtype int
#define INIT_SIZE 100
#define ADD_SIZE 10
using namespace std;



void menu()
{
	printf("1.Init      2.Push\n");
	printf("3.Pop       4.SearchKey\n");
	printf("5.GetTop    6.Display\n");
	printf("7.Destroy   8.SetValue\n");
	printf("0.exit\n");
}


typedef struct SqStack
{
	SElemtype *base;
	SElemtype *top;//length=top-base
	int stacksize;
}SqStack;


Status Init(SqStack &S)
{
	S.base = (SElemtype *)malloc(INIT_SIZE * sizeof(SElemtype));
	if (!S.base) return ERRO;
	S.top = S.base;
	S.stacksize = INIT_SIZE;
	return DONE;
}

Status Push(SqStack &S, SElemtype &x)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemtype *)realloc(S.base,(INIT_SIZE + ADD_SIZE) * sizeof(SElemtype));
		S.stacksize += ADD_SIZE;
	}
	*S.top = x;
	S.top++;
	return DONE;
}

Status Pop(SqStack &S, SElemtype &x)
{
	if (S.top == S.base) return ERRO;
	x = *S.top;
	S.top--;
	return DONE;
}

Status SearchKey(SqStack &S, SElemtype &key,vector<int> &positions)
{
	if (S.top == S.base) return ERRO;
	SElemtype *p = S.base;
	int i = 1;
	bool flag = false;
	for (p; p < S.top; p++)
	{
		if (*p == key)
		{
			positions.push_back(i);
			flag = true;
		}
		i++;
	}
}

Status GetTop(SqStack &S, SElemtype &x)
{
	if (S.top == S.base) return ERRO;
	x = *(S.top - 1);
	return DONE;
}

void Display(SqStack &S)
{
	if (S.base == NULL)
	{
		printf("Erro\n");
	}
	else if (S.top == S.base)
	{
		printf("Empty Stack\n");
	}
	else
	{
		SElemtype *p = S.base;
		for (p; p < S.top; p++)
		{
			printf("%d ", *p);
		}
		cout << endl;
	}
}

Status Destroy(SqStack &S)
{
	if (S.base != NULL) free(S.base);
	S.base = NULL;
	S.stacksize = 0;
	return DONE;
}

Status SetValue(SqStack &S,int position,SElemtype &x)
{
	SElemtype *p = S.base;
	if (position > S.top - S.base) return ERRO;
	S.base[position - 1] = x;
	return DONE;
}




int main()
{
	SqStack S;
	menu();
	int choice = 0;
	SElemtype x = 0; int position = 0;
	int length = 0;
	vector<int> positions;
	printf("Note that punctuation is in English\n\n\n");
	for (;;)
	{
		printf("Please input menu number: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			Init(S);
			printf("Done\n");
			break;
		case 2:
			printf("Please input what you want to push(int): ");
			scanf("%d", &x);
			if (Push(S,x))
			{
				printf("Done\n");
			}
			else
			{
				printf("Erro\n");
			}
			break;
		case 3:
			if (Pop(S, x))
			{
				printf("Done\n");
			}
			else
			{
				printf("Erro\n");
			}
			break;
		case 4:
			printf("Please input Key(Slemtype): ");//search key return its position
			scanf("%d", &x);
			if (SearchKey(S, x, positions))
			{
				printf("Done\n");
				cout << "positions in list: ";
				vector<int>::iterator itr;
				for (itr=positions.begin();itr!=positions.end();itr++)
				{
					cout << *itr << " ";
				}
				cout << endl;
			}
			else
			{
				printf("Erro\n");
			}
			break;
		case 5:
			if (GetTop(S, x))
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
			Display(S);
			break;
		case 7:
			Destroy(S);
			printf("Done\n");
			break;
		case 8:
			printf("Please input where you want to set and set to what(int,int): ");
			scanf("%d,%d", &position, &x);
			if (SetValue(S, position, x))
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
