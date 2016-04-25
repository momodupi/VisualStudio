/**
******************************************************************************
* @File    main.c
* @Author  邵仕平
* @Number  415914114042 
* @Date    2014.12.13
* @Brief   CAD/CAM第二次作业：任意多边形开窗剪裁
******************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#define TOP     0
#define RIGHT   1
#define BOTTOM  2
#define LEFT    3

#define X       0
#define Y       1

#define TURE    1
#define FALSE   0

#pragma warning(disable:4996)

typedef unsigned int  Status;
typedef unsigned int  Bound;

typedef struct
{
	float px;
	float py;
}Node;

int VertexNum = 0;
int PolygonEdges = 0;
int EdgeCount = 0;
int FinalVertexNum = 0;

Node OriGra[4];
Node InGra[20];
Node OutGra[20];

Status IfInside(Bound bound, int Number)
{
	int fI, fM = 0;
	fI = Number % PolygonEdges;
	switch (bound)
	{
		case TOP:
		{
			if ((InGra[fI].py - OriGra[0].py) <= 0)
			{
				return TURE;
			}
			else
			{
				return FALSE;
			}
		}
		break;
		case RIGHT:
		{
			if ((InGra[fI].px - OriGra[0].px) <= 0)
			{
				return TURE;
			}
			else
			{
				return FALSE;
			}
		}
		break;
		case BOTTOM:
		{
			if ((InGra[fI].py - OriGra[2].py) >= 0)
			{
				return TURE;
			}
			else
			{
				return FALSE;
			}
		}
		break;
		case LEFT:
		{
			if ((InGra[fI].px - OriGra[2].px) >= 0)
			{
				return TURE;
			}
			else
			{
				return FALSE;
			}
		}
		break;
	}
}



Status IfCross(Bound bound, int Number)
{
	int fI, fM = 0;
	fI = Number % PolygonEdges;
	fM = (Number + 1) % PolygonEdges;
	switch (bound)
	{
		case TOP:
		{
			if ((InGra[fI].py - OriGra[0].py)*(InGra[fM].py - OriGra[0].py) < 0)
			{
				return TURE;
			}
			else
			{
				return FALSE;
			}
		}
		break;
		case RIGHT:
		{
			if ((InGra[fI].px - OriGra[0].px)*(InGra[fM].px - OriGra[0].px) < 0)
			{
				return TURE;
			}
			else
			{
				return FALSE;
			}
		}
		break;
		case BOTTOM:
		{
			if ((InGra[fI].py - OriGra[2].py)*(InGra[fM].py - OriGra[2].py) < 0)
			{
				return TURE;
			}
			else
			{
				return FALSE;
			}
		}
		break;
		case LEFT:
		{
			if ((InGra[fI].px - OriGra[2].px)*(InGra[fM].px - OriGra[2].px) < 0)
			{
				return TURE;
			}
			else
			{
				return FALSE;
			}
		}
		break;
	}
}


void GetTheNode(int bound, int Number)
{
	int fI, fM = 0;
	fI = Number % PolygonEdges;
	fM = (Number + 1) % PolygonEdges;

	float k = 0;
	float b = 0;

	if ((InGra[fM].px - InGra[fI].px) != 0)
	{
		k = (InGra[fM].py - InGra[fI].py) / (InGra[fM].px - InGra[fI].px);
		b = InGra[fI].py - (k * InGra[fI].px);

		switch (bound)
		{
		case TOP:
		{
					InGra[fI].px = (OriGra[0].py - b) / k;
					InGra[fI].py = OriGra[0].py;
		}
			break;
		case RIGHT:
		{
					  InGra[fI].px = OriGra[0].px;
					  InGra[fI].py = OriGra[0].px * k + b;
		}break;
		case BOTTOM:
		{
					   InGra[fI].px = (OriGra[2].py - b) / k;
					   InGra[fI].py = OriGra[2].py;
		}
			break;
		case LEFT:
		{
					 InGra[fI].px = OriGra[2].px;
					 InGra[fI].py = OriGra[2].px * k + b;
		}
			break;
		}
	}
	else
	{
		switch (bound)
		{
		case TOP:
		{
			InGra[fI].px = InGra[fI].px;
			InGra[fI].py = OriGra[fI].py;
		}
			break;
		case RIGHT:
		{
			InGra[fI].px = OriGra[fI].px;
			InGra[fI].py = InGra[fI].py;
		}break;
		case BOTTOM:
		{
			InGra[fI].px = InGra[fI].px;
			InGra[fI].py = OriGra[fI].py;
		}
			break;
		case LEFT:
		{
			InGra[fI].px = OriGra[fI].px;
			InGra[fI].py = InGra[fI].py;
		}
			break;
		}
	}
}




void RightClipping(void)
{
	int iNum;
	int iEdges = 0;
	
	for (iNum = 0; iNum < PolygonEdges; iNum++)
	{
		if (IfInside(RIGHT, iNum) == TURE)
		{
			OutGra[iEdges].px = InGra[iNum].px;
			OutGra[iEdges].py = InGra[iNum].py;
			iEdges++;
		}
		if (IfCross(RIGHT, iNum) == TURE)
		{
			GetTheNode(RIGHT, iNum);
			OutGra[iEdges].px = InGra[iNum % PolygonEdges].px;
			OutGra[iEdges].py = InGra[iNum % PolygonEdges].py;
			iEdges++;
		}
	}

	for (iNum = 0; iNum < 20; iNum++)
	{
		InGra[iNum].px = OutGra[iNum].px;
		InGra[iNum].py = OutGra[iNum].py;
	}
	PolygonEdges = iEdges;
}


void BottomClipping(void)
{
	int iNum;
	int iEdges = 0;

	for (iNum = 0; iNum < PolygonEdges; iNum++)
	{
		if (IfInside(BOTTOM, iNum) == TURE)
		{
			OutGra[iEdges].px = InGra[iNum].px;
			OutGra[iEdges].py = InGra[iNum].py;
			iEdges++;
		}
		if (IfCross(BOTTOM, iNum) == TURE)
		{
			GetTheNode(BOTTOM, iNum);
			OutGra[iEdges].px = InGra[iNum % PolygonEdges].px;
			OutGra[iEdges].py = InGra[iNum % PolygonEdges].py;
			iEdges++;
		}
	}

	for (iNum = 0; iNum < 20; iNum++)
	{
		InGra[iNum].px = OutGra[iNum].px;
		InGra[iNum].py = OutGra[iNum].py;
	}
	PolygonEdges = iEdges;
}

void LeftClipping(void)
{
	int iNum;
	int iEdges = 0;

	for (iNum = 0; iNum < PolygonEdges; iNum++)
	{
		if (IfInside(LEFT, iNum) == TURE)
		{
			OutGra[iEdges].px = InGra[iNum].px;
			OutGra[iEdges].py = InGra[iNum].py;
			iEdges++;
		}
		if (IfCross(LEFT, iNum) == TURE)
		{
			GetTheNode(LEFT, iNum);
			OutGra[iEdges].px = InGra[iNum % PolygonEdges].px;
			OutGra[iEdges].py = InGra[iNum % PolygonEdges].py;
			iEdges++;
		}
	}

	for (iNum = 0; iNum < 20; iNum++)
	{
		InGra[iNum].px = OutGra[iNum].px;
		InGra[iNum].py = OutGra[iNum].py;
	}
	PolygonEdges = iEdges;
}

void TopClipping(void)
{
	int iNum;
	int iEdges = 0;

	for (iNum = 0; iNum < PolygonEdges; iNum++)
	{
		if (IfInside(TOP, iNum) == TURE)
		{
			OutGra[iEdges].px = InGra[iNum].px;
			OutGra[iEdges].py = InGra[iNum].py;
			iEdges++;
		}
		if (IfCross(TOP, iNum) == TURE)
		{
			GetTheNode(TOP, iNum);
			OutGra[iEdges].px = InGra[iNum % PolygonEdges].px;
			OutGra[iEdges].py = InGra[iNum % PolygonEdges].py;
			iEdges++;
		}
	}

	for (iNum = 0; iNum < 20; iNum++)
	{
		InGra[iNum].px = OutGra[iNum].px;
		InGra[iNum].py = OutGra[iNum].py;
	}
	PolygonEdges = iEdges;
}


int main(void)
{
	int i;

	printf("\r\n/**\r\n");
	printf("  * 名称：CAD/CAM第二次作业：任意多边形开窗剪裁 \r\n");
	printf("  * 作者：邵仕平 \r\n");
	printf("  * 学号：415914114042 \r\n");
	printf("  * 日期：2014年12月13日 \r\n");
	printf("  */ \r\n");

	printf("\r\n请从右上角开始顺时针输入窗口边界四个顶点坐标：\r\n");
	printf("请先输入X坐标，再输入Y坐标：\r\n");
	for (i = 0; i < 4; i++)
	{
		scanf("%f,%f", &OriGra[i].px, &OriGra[i].py);
	}

	printf("\r\n请输入任意多边形边数：\r\n");
	scanf("%d", &PolygonEdges);


	printf("\r\n请输入%d边形各顶点坐标：\r\n", PolygonEdges);
	printf("请先输入X坐标，再输入Y坐标：\r\n");
	for (i = 0; i < PolygonEdges; i++)
	{
		scanf("%f,%f", &InGra[i].px, &InGra[i].py);
	}

	RightClipping();
	BottomClipping();
	LeftClipping();
	TopClipping();

	printf("\r\n裁剪后图形坐标为：\r\n");

	for (i = 0; i < PolygonEdges; i++)
	{
		printf("x%d = %.2f, y%d = %.2f \r\n", i, OutGra[i].px, i, OutGra[i].py);
	}

	printf("\n\r\n/*** 结束 ***/ \r\n\n");
	while(1);
	return 0;
}