// String.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MAXSIZE 100
#define Status int
#define ERRO 0
#define DONE 1
#define CHUNKSIZE 100
using namespace std;



//SqstaticString
typedef char SqStaticString[MAXSIZE + 1];//only have char in it,s[0] store its size

Status Concat(SqStaticString &S, SqStaticString s1, SqStaticString s2)
{
	Status cut;
	if (s1[0] + s2[0] <= MAXSIZE)
	{
		for (int i = 1; i <= s1[0]; i++) { S[i] = s1[i]; }
		for (int i = s1[0] + 1; i <= s1[0] + s2[0]; i++) { S[i] = s2[i - s1[0]]; }
		S[0] = s1[0] + s2[0];
		cut = false;
	}
	else if (s1[0] < MAXSIZE&&s1[0] + s2[0] > MAXSIZE)
	{
		for (int i = 1; i <= s1[0]; i++) { S[i] = s1[i]; }
		for (int i = s1[0] + 1; i < MAXSIZE; i++) { S[i] = s2[i - s1[0]]; }
		S[0] = MAXSIZE;
		cut = true;
	}
	else if (s1[0] >= MAXSIZE)
	{
		for (int i = 1; i <= MAXSIZE; i++)
		{
			S[i] = s1[i];
		}
		S[0] = MAXSIZE;
		cut = true;
	}
	return cut;
}

Status SubString(SqStaticString &sub, SqStaticString s, int p, int len)
{
	if (p < 1 || p>s[0] || p + len - 1 > s[0] || len < 0) return ERRO;
	for (int i = 1; i <= len; i++)
	{
		sub[i] = s[p + i - 1];
	}
	sub[0] = len;
	return DONE;
}


//SqString
typedef struct SqString
{
	char *base;
	int length;
};

Status Init_SqString(SqString &S)
{
	S.base = (char *)malloc(MAXSIZE * sizeof(char));
	S.length = 0;
}




//LineString
typedef struct ChunkNode
{
	char ch[CHUNKSIZE];
	ChunkNode *next;
}ChunkNode;

typedef struct LinkString
{
	ChunkNode *front;
	ChunkNode *rear;
	int curlen;//because often use its length so we set;in queue we don't usally use length,so we did't set it
	//if don't set it,every time we need to know length,we must search from head
}LinkString;





int main()
{
    std::cout << "Hello World!\n";
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
