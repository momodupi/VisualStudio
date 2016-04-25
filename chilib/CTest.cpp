// CTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	const char DANG[] = { 0x00,0x00,0x10,0x00,0x10,0xFE,0x11,0x00,0x7D,0x00,0x11,0x00,0x11,0xFC,0x11,0x82,
		0x15,0x84,0x19,0x44,0x31,0x28,0x51,0x28,0x12,0x10,0x12,0x68,0x14,0x84,0x7B,0x02, };
	char *a = " This is testing of size of unsigned char ";
	char b[] = " This is testing of size of unsigned char ";
	char* d = "当";
	int i, j;
	char c;

	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 8; j++)
		{
			c = DANG[2 * i] << j;
			if (c & 0x80)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		for (j = 0; j < 8; j++)
		{
			c = DANG[2 * i + 1] << j;
			if (c & 0x80)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	printf("\r\n\n");

	printf("\r\n %s ", d);

	printf("\r\n size of a = %d, size of b = %d. ", sizeof(a), sizeof(b));

	printf("\r\n a = %s, b = %s. ", a, b);

	while (1);

    return 0;
}

