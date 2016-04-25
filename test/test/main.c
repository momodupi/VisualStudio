#include "stdio.h"

int main(void)
{
	int nc, c;
	int prechar = 0;
	for (nc = 0; (c = getchar()) != EOF; nc++)
	{
		if (c == '\t')
		{
			printf("\t");
		}
		else if (c == '\b')
		{
			printf("\b");
		}
		else if (c == '\\')
		{
			printf("\\");
		}
		else
		{
			putchar(c);
		}
	}
	printf("%d\n", nc);
	getchar();
}