// CircularQueue Implementation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define DONE 1
#define ERRO 0
#define EMPTY 2
#define FULL 3
#define Status int
#define QElemType int
#define QUEUE_INIT_SIZE 1000



void menu()
{
	printf("1.Init      2.EnQueue\n");
	printf("3.DeQueue   4.SearchKey\n");
	printf("5.Display   6.Destroy\n");
	printf("7.Setvalue  8.exit\n");
}



typedef struct CircularQueue
{
	QElemType *base;
	int front;
	int rear;
}CQueue;//Circular rear always block(all sqstruct the same)
//use one less space to tell the difference between fullfill and empty

Status Init(CQueue &Q)
{
	Q.base = (QElemType *)malloc(QUEUE_INIT_SIZE * sizeof(QElemType));
	if (!Q.base) return ERRO;
	Q.front = Q.rear = 0;
	return DONE;
}

Status EnQueue(CQueue &Q, QElemType &x)//only enqueue from tail
{
	if ((Q.rear + 1) % QUEUE_INIT_SIZE == Q.front) return ERRO;//adjust if fullfill
	Q.base[Q.rear] = x;
	Q.rear = (Q.rear + 1) % QUEUE_INIT_SIZE;//if come to the last block,use % to go to head
	return DONE;
}

Status DeQueue(CQueue &Q, QElemType &x)//only dequeque from head
{
	if (Q.front == Q.rear) return ERRO;
	x = Q.base[Q.front];
	Q.front = (Q.front + 1) % QUEUE_INIT_SIZE;//if come to the last block,use % to go to head
	return DONE;
}

Status SearchKey(CQueue &Q, QElemType &key, vector<QElemType> &positions)
{
	if (Q.front == Q.rear) return ERRO;
	int j = 1;
	for (int i = Q.front; i < Q.rear; i++)
	{
		if (key == Q.base[i])
		{
			positions.push_back(j);
		}
		j++;
	}
	return DONE;
}

void Display(CQueue &Q)
{
	if (Q.base == NULL)
	{
		printf("Erro");
	}
	else if (Q.front == Q.rear)
	{
		printf("Empty");
	}
	for (int i = Q.front; i < Q.rear; i++)
	{
		printf("%d ", Q.base[i]);
	}
	printf("\n");
}

void Destroy(CQueue &Q)
{
	if (Q.base != NULL) free(Q.base);
	Q.base = NULL;
}

Status SetValue(CQueue &Q, int position, QElemType &x)//calculate position from front
{
	if (Q.front == Q.rear) return ERRO;
	if (Q.front + position - 1 < Q.rear)
	{
		Q.base[Q.front + position - 1] = x;
		return DONE;
	}
	else return ERRO;
}




int main()
{
	CQueue Q;
	menu();
	int choice = 0;
	QElemType x = 0; int position = 0;
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
			Init(Q);
			printf("Done\n");
			break;
		case 2:
			printf("Please input what you want to enter queue(int): ");
			scanf("%d", &x);
			if (EnQueue(Q, x))
			{
				printf("Done\n");
			}
			else
			{
				printf("Erro\n");
			}
			break;
		case 3:
			if (DeQueue(Q, x))
			{
				printf("Done\n");
			}
			else
			{
				printf("Erro\n");
			}
			break;
		case 4:
			printf("Please input Key(int): ");//search key return its position
			scanf("%d", &x);
			if (SearchKey(Q, x, positions))
			{
				printf("Done\n");
				cout << "positions in queue: ";
				vector<int>::iterator itr;
				for (itr = positions.begin(); itr != positions.end(); itr++)
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
			Display(Q);
			break;
		case 6:
			Destroy(Q);
			printf("Done\n");
			break;
		case 7:
			printf("Please input where you want to set and set to what(int,int): ");
			scanf("%d,%d", &position, &x);
			if (SetValue(Q, position, x))
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
