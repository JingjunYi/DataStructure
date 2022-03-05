// Stack in order.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


typedef struct SqStack
{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;


Status Init_SqStack(SqStack &s)//just like Sqlist without length//*top=*base+length waste time,so give two pointer
{
	s.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s.base) exit(OVERFLOW);
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return DONE;
}

Status GetTop(SqStack &s, int &x)
{
	if (s.top == s.base) return ERRO;
	x = *(s.top - 1);//top point the block on the top data
	return DONE;
}

Status Push(SqStack &s, SElemType &x)
{
	if (s.top - s.base >= s.stacksize)//adjust if stack is fullfill
	{
		s.base = (SElemType*)realloc(s.base, (STACKINCREMENT + s.stacksize) * sizeof(SElemType));//open more space
	}
	*s.top = x;
	s.top++;
	s.stacksize += STACKINCREMENT;
	return DONE;
}

Status Pop(SqStack &s, SElemType &x)
{
	if (s.top == s.base) return ERRO;//adjust if stack is empty
	x = *(s.top - 1);
	s.top--;
	return DONE;
}

void Show_SqStack(SqStack &s)
{
	if (s.top == s.base) return;
	SElemType* p;
	p = s.base;
	while (p < s.top)
	{
		printf("%d ", *p);
		p++;
	}
}



int main()
{
	SqStack s;
	Init_SqStack(s);
	for (int i = 1; i <= 8; i++)
	{
		Push(s, i);
	}
	Show_SqStack(s);

	cout << endl;

	int a = 0;
	Pop(s, a);
	Show_SqStack(s);

	cout << endl;

	GetTop(s, a);
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
