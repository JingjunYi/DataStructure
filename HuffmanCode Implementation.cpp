// HuffmanCode Implementation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
#define Status int
#define TElemtype int
#define DONE 1
#define ERRO 0




typedef struct BinaryTreeNode
{
	TElemtype data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}*BiTree, BiTreeNode;


typedef struct HuffmanTreeNode
{
	unsigned int weight;
	unsigned int parent;
	unsigned int leftchild;
	unsigned int rightchild;
}HTNode, *HuffmanTree;//n1 node before n2 node,differen from SqBinaryTree

typedef char **HuffmanCode;

void Select(HuffmanTree HT,int end,int &s1,int &s2)
//select algorithm to make huffman tree
//select two weight smallest node in HuffmanTree array

//end means the last node position in the array
//s1,s2 to get two smallest node position
{
	int min1 = 0, min2 = 0;
	int i = 1;//traverse all begin from array[1]

	//find node haven't parent(parent==0)
	while (HT[i].parent != 0 && i <= end)
	{
		i++;
	}
	min1 = HT[i].weight;
	s1 = i;
	i++;
	while (HT[i].parent != 0 && i <= end)
	{
		i++;
	}

	//HT[i] is the second node we found,compare two node to get min2,min2>min1
	if (HT[i].weight < min1)
	{
		min2 = min1;
		s2 = s1;
		min1 = HT[i].weight;
		s1 = i;
	}
	else
	{
		min2 = HT[i].weight;
		s2 = i;
	}

	//two node compare with following no parent node
	for (int j = i + 1; j <= end; j++)
	{
		//if have parent,just continue
		if (HT[j].parent != 0)
		{
			continue;
		}
		//if small than the smaller one,change min1,min2,s1,s2
		if (HT[j].weight < min1)
		{
			min2 = min1;
			min1 = HT[j].weight;
			s2 = s1;
			s1 = j;
		}
		//if between two weight,change min2,s2
		else if (HT[j].weight < min2 && HT[j].weight >= min1)
		{
			min2 = HT[j].weight;
			s2 = j;
		}
	}
}

void CreateHuffmanTree(HuffmanTree *HT,int *weight,int n)//HT is huffmantree pointer
//weight means node weight,n means num of nodes
{
	if (n <= 1) return;
	int m = 2 * n - 1;//m means sum of nodes(n2+n1)
	//HT[i]-HT[2n-1] are all nodes
	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//no use array[0]
	HuffmanTree p = *HT;

	//init all tree n1 node
	for (int i = 1; i <= n; i++)
	{
		(*HT)[i].weight = weight[i - 1];
		(*HT)[i].parent = 0;
		(*HT)[i].leftchild = 0;
		(*HT)[i].rightchild = 0;
	}
	//init extra tree node start from n+1
	for (int i = n + 1; i <= m; i++)
	{
		(*HT)[i].weight = 0;
		(*HT)[i].parent = 0;
		(*HT)[i].leftchild = 0;
		(*HT)[i].rightchild = 0;
	}
	//create huffman tree
	for (int i = n + 1; i <= m; i++)
	{
		int s1 = 0, s2 = 0;
		Select(*HT, i - 1, s1, s2);
		(*HT)[s1].parent = (*HT)[s2].parent = i;
		(*HT)[i].leftchild = s1;
		(*HT)[i].rightchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
}

void HuffmanCoding(HuffmanTree HT, HuffmanCode *HC, int n)
//HC is pointer of string array,means dynamic string array
//n is num of leaf nodes
{
	*HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
	char *cd = (char *)malloc(n * sizeof(char));//store string
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++)
	{
		int start = n - 1;//when coding,start from leave node,so need to transpose
		int c = i;//current node position in array
		int j = HT[i].parent;//current node's parent position in array
		
		//find root and coding
		while (j != 0)
		{
			if (HT[j].leftchild == c)//if it's parent's leftchild,code 0
			{
				start--;
				cd[start] = '0';
			}
			else if (HT[j].rightchild == c)
			{
				start--;
				cd[start] = '1';//if it's parent's rightchild,code 1
			}

			//keep finding root
			c = j;
			j = HT[j].parent;
		}

		//over and get cd which stored current's huffmancode
		(*HC)[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy((*HC)[i], &cd[start]);
	}
	free(cd);//cd now uselesss,free it
}

void OutputHuffmanCode(HuffmanCode c,int *weight,int n)
{
	printf("Huffman Code:\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d code = %s\n", weight[i - 1], c[i]);
	}
}



int main()
{
	printf("Please enter number of nodes: ");
	int n = 0;
	scanf("%d", &n);
	printf("Please enter weight of each node(int):");
	int *weight = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &weight[i]);
	}

	printf("Coding...\n");

	HuffmanTree htree;
	HuffmanCode hcode;
	CreateHuffmanTree(&htree, weight, n);
	HuffmanCoding(htree, &hcode, n);
	printf("Done\n");
	OutputHuffmanCode(hcode, weight, n);
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
