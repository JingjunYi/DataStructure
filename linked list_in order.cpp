// linked list_in order.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#include <string.h>
#pragma warning(disable:4996)
#define Status int
#define ElemType int
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 1
#define ERRO 0
#define DONE 1
using namespace std;



typedef struct Sqlist//just like array
{
	ElemType* data;
	int length;//current size
	int listsize;//max size
}Sqlist;


Status Init_Sqlist(Sqlist &L)
{
	L.data = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.data) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return DONE;
}

Status Insert_Sqlist(Sqlist &L, int i, ElemType x)//insert before no.i node
{
	ElemType* p;
	if (i<1 || i>L.length + 1) return ERRO;//adjust if i is leagal
	if (L.length >= L.listsize)
	{
		ElemType* newbase = (ElemType*)realloc(L.data, (L.listsize + LISTINCREMENT) * sizeof(ElemType));//add listsize
		if (!newbase) exit(OVERFLOW);//adjust add success
		L.data = newbase;//add space
		L.listsize += LISTINCREMENT;
	}
	ElemType* q= &L.data[i - 1];//take insert position
	for (p = &L.data[L.length - 1]; p >= q; p--) *(p + 1) = *p;//move others
	*q = x;//insert
	L.length++;//insert done
	return DONE;
}

Status Delete_Sqlist(Sqlist &L, int i, ElemType &x)
{
	if (i<1 || i>L.length) return ERRO;//adjust if i is leagal
	ElemType* p = &L.data[i - 1];
	ElemType* q = L.data + L.length - 1;
	x = *p;//get remove value
	for (p++; p <= q; p++) *(p - 1) = *p;//move others
	L.length--;//delete done
}

int LocateElem_Sqlist(Sqlist &L, ElemType x)
{
	int i = 1;
	ElemType* p = L.data;
	for (; p <= L.data + L.length - 1; p++)
	{
		if (x == L.data[i - 1]) break;
		i++;
	}
	if (i <= L.length) return i;
	else return 0;
}

void Show_Sqlist(Sqlist &L)
{
	for (int i = 0; i < L.length; i++) printf("%d ", L.data[i]);
}



int main()
{
	Sqlist L;
	Init_Sqlist(L);
	Insert_Sqlist(L, 1, 2);
	Insert_Sqlist(L, 1, 0);
	Insert_Sqlist(L, 2, 1);
	Show_Sqlist(L);
	cout << endl;
	int e;
	Delete_Sqlist(L, 3, e);
	Show_Sqlist(L);
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
