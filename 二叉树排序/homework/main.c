
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 8
#pragma warning(disable:4996)

typedef struct NodeStruct
{
	int NodeData;
	struct NodeStruct *LeftChild;
	struct NodeStruct *RightChild;
}Node;

Node *p, *n, *Root = NULL;
int A[MAXSIZE] = { 10, 18, 3, 8, 12, 2, 7, 3 };
int B[MAXSIZE];
int i, BCount = 0;

void PushInTree(void)
{

	for (i = 0; i < MAXSIZE; i++)
	{
		n = (Node *)malloc(sizeof(Node));
		n->NodeData = A[i];
		n->LeftChild = NULL;
		n->RightChild = NULL;
		if (Root == NULL)
		{
			Root = n;
			p = Root;
		}
		else
		{

			while ((p->LeftChild != NULL) || (p->RightChild != NULL))
			{
				if (n->NodeData < p->NodeData)
				{
					if (p->LeftChild == NULL)
					{
						break;
					}
					else
					{
						p = p->LeftChild;
					}
				}
				else if (n->NodeData >= p->NodeData)
				{
					if (p->RightChild == NULL)
					{
						break;
					}
					else
					{
						p = p->RightChild;
					}
				}
			}

			if (n->NodeData < p->NodeData)
			{
				p->LeftChild = n;
			}
			else if (n->NodeData >= p->NodeData)
			{
				p->RightChild = n;
			}
			p = Root;
		}
	}
}

void MidOrderTree(Node *p)
{
	if (p != NULL)
	{
		MidOrderTree(p->LeftChild);
		B[BCount++] = p->NodeData;
		MidOrderTree(p->RightChild);
	}
}


int main(void)
{
	printf("\r\n����ǰ������AΪ��\r\n");
	for (i = 0; i < MAXSIZE; i++)
	{
		printf("%d ", A[i]);
	}

	PushInTree();

	printf("\n\r\n��С��������������BΪ��\r\n");

	MidOrderTree(p);
	
	for (i = 0; i < BCount; i++)
	{
		printf("%d ", B[i]);
	}
	printf("\r\n\nͨ���㷨����: \r\n\n");
	printf("ע�����㷨ֻ֧��8�������������� \r\n");
	printf("������8����������ENTER�ָ� \r\n");

	Root = NULL;
	p = Root;
	BCount = 0;
	for (i = 0; i < MAXSIZE; i++)
	{
		A[i] = 0;
		B[i] = 0;
	}

	for (i = 0; i < MAXSIZE; i++)
	{
		scanf("%d", &A[i]);
	}

	printf("\r\n����ǰ������AΪ��\r\n");
	for (i = 0; i < MAXSIZE; i++)
	{
		printf("%d ", A[i]);
	}

	PushInTree();

	printf("\n\r\n��С��������������BΪ��\r\n");

	MidOrderTree(p);

	for (i = 0; i < BCount; i++)
	{
		printf("%d ", B[i]);
		B[i] = 0;
	}

	printf("\n\r\n/*** ���� ***/ \r\n\n");
}