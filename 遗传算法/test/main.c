#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

#define CHROMNUM   4
#define CHROMPOS   8



//����Ⱦɫ��ṹ
typedef struct Chrom
{
	short int bit[CHROMPOS];
	int fit;
}chrom;


/**
  * @brief  ��Ԫ������ϵ
  * @param  x: �Ա���
  * @retval fy: �����
  */
int y(int x1, int x2)
{
	int fy = 0;
	fy = -(x1 * x1) - (x2 * x2) + 8;
	if (fy > 7)fy = 7;
	return(fy);
} 

/**
  * @brief  ��������ת��Ϊʮ����
  * @param  popcurrent: ��ǰȾɫ��ṹ��
  * @retval z: ʮ������
  */
int x1(chrom popcurrent)
{
	int z;
	z = (popcurrent.bit[0] * 1) + (popcurrent.bit[1] * 2) + (popcurrent.bit[2] * 4);

	if (popcurrent.bit[3] == 1)
	{
		z = z*(-1);                               //ת��ǰΪ�з�����
	}

	return(z);
	flushall();                                 //�������
}

int x2(chrom popcurrent)
{
	int z;
	z = (popcurrent.bit[4] * 1) + (popcurrent.bit[5] * 2) + (popcurrent.bit[6] * 4);

	if (popcurrent.bit[7] == 1)
	{
		z = z*(-1);                               //ת��ǰΪ�з�����
	}

	return(z);
	flushall();                                 //�������
}


/**
  * @brief  ������ɳ�ʼ��Ⱥ
  * @param  popcurrent[CHROMNUM]: Ⱦɫ��ṹ������
  * @retval ��
  */
void *evpop(chrom popcurrent[CHROMNUM])
{
	int i, j, value;
	int random;
	for (j = 0; j < CHROMNUM; j++)                            //����Ⱥ�еĵ�1��Ⱦɫ�嵽��m��Ⱦɫ��
	{
		for (i = 0; i < CHROMPOS; i++)                        //��Ⱦɫ��ĵ�1������λ����n������λ
		{
			random = rand();                                  //����0-1�����
			random = (random % 2);                            
			popcurrent[j].bit[i] = random;                    //��ֵ��Ⱦɫ��
		}

		popcurrent[j].fit = y(x1(popcurrent[j]), x2(popcurrent[j]));              //����Ⱦɫ�����Ӧ�ȣ�
		//���Ⱦɫ�����
		printf("\n Ⱦɫ��%d����Ϊ: popcurrent[%d] = %d%d%d%d%d%d%d%d;", j, j, popcurrent[j].bit[7], popcurrent[j].bit[6], popcurrent[j].bit[5], popcurrent[j].bit[4], popcurrent[j].bit[3], popcurrent[j].bit[2], popcurrent[j].bit[1], popcurrent[j].bit[0]);
		printf("ֵΪ: [%d, %d]; ��Ӧ��Ϊ: %d", x2(popcurrent[j]), x1(popcurrent[j]), popcurrent[j].fit);
	}
	return(0);
	flushall();                                 //�������
}


/**
  * @brief  ѡ������
  * @param  popcurrent[4] ��ǰȾɫ��
  * @retval ��
  */
void *pickchroms(chrom popcurrent[CHROMNUM])
{
	int i, j;
	chrom temp;

	for (i = 0; i < CHROMNUM - 1; i++)                           //���ݸ�����Ӧ��������
	{
		for (j = 0; j < CHROMNUM - 1; j++)
		{
			if (popcurrent[j + 1].fit > popcurrent[j].fit)
			{
				temp = popcurrent[j + 1];
				popcurrent[j + 1] = popcurrent[j];
				popcurrent[j] = temp;
			}
		}
	}
	for (i = 0; i < CHROMNUM; i++)
	{
		printf("\n��ǰΪ: popnext[%d] ��Ӧ��Ϊ: %d\n", i, popcurrent[i].fit);
	}
	flushall();                                 //�������
}

/**
  * @brief  ����������
  * @param  popnext[4] ��һ��Ⱦɫ��
  * @retval ��
  */
void *crossover(chrom popnext[CHROMNUM])
{
	int random;
	int i;
	random = rand();                              //��Ⱦɫ�巶Χ��������������
	random = ((random % (CHROMPOS - 1)) + 1);

	for (i = 0; i < random; i++)
	{
		popnext[2].bit[i] = popnext[0].bit[i];    //������������popnext[2]Ϊ����1��popnext[3]Ϊ����2
		popnext[3].bit[i] = popnext[1].bit[i];    
	}

	for (i = random; i < CHROMPOS; i++)
	{
		popnext[2].bit[i] = popnext[1].bit[i];
		popnext[3].bit[i] = popnext[0].bit[i];
	}

	for (i = 0; i < CHROMNUM; i++)
	{
		popnext[i].fit = y(x1(popnext[i]), x2(popnext[i]));        //��������Ⱥ��Ӧ��
	}

	for (i = 0; i < CHROMNUM; i++)
	{
		printf("\n�����Ϊ: popnext[%d] = %d%d%d%d%d%d;", i, popnext[i].bit[5], popnext[i].bit[4], popnext[i].bit[3], popnext[i].bit[2], popnext[i].bit[1], popnext[i].bit[0]);
		printf(" ֵΪ: [%d, %d]; ��Ӧ��Ϊ: %d\n", x1(popnext[i]), x2(popnext[i]), popnext[i].fit);
	}
	flushall();                                 //�������
}

/**
  * @brief  ������ͻ��
  * @param  popnext[4] ��һ��Ⱦɫ��
  * @retval ��
  */
void *mutation(chrom popnext[CHROMNUM])
{
	int random;
	int row, col;
	random = rand() % 50;                           //����0��49���������

	if (random == 1)                                //������Ϊ0.02(2%)��
	{
		row = rand() % CHROMNUM;                    //�����������Ⱦɫ��ţ�
		col = rand() % CHROMPOS;                    //��������������λ�ţ�

		if (popnext[row].bit[col] == 0)             //����
		{
			popnext[row].bit[col] = 1;
		}
		else if (popnext[row].bit[col] == 1)
		{
			popnext[row].bit[col] = 0;
		}

		popnext[row].fit = y(x1(popnext[row]), x2(popnext[row]));     //����������Ⱥ��Ӧ��

		printf("\nͻ�䷢��: popnext[%d] bit[%d]:=%d%d%d%d%d%d;", row, col, popnext[row].bit[5], popnext[row].bit[4], popnext[row].bit[3], popnext[row].bit[2], popnext[row].bit[1], popnext[row].bit[0]);
		printf(" ֵΪ: [%d, %d]; ��Ӧ��Ϊ: %d\n", x1(popnext[row]), x2(popnext[row]), popnext[row].fit);
	}
	flushall();                                 //�������
}


/**
  * @brief  ������
  * @param  ��
  * @retval 0
  */
int main(void)
{
	int num;
	int i, j, k, Max;
	Max = 0;                                    //�������ֵ

	printf("ԭ����Ϊ: y = -(x1 * x1) - (x2 * x2) + 9��\n");
    printf("\n������һ������1�ĵ���������\n");

	scanf("%d", &num);                          //�����������
	
	while (num <= 1)                            
	{
		printf("\n������һ������1��������\n");
		scanf("%d", &num);
	}

	chrom popcurrent[CHROMNUM];                 //�����ʼ��Ⱥ
	chrom popnext[CHROMNUM];                    //�����Ӵ���Ⱥ
	evpop(popcurrent);                          //���������ʼ��Ⱥ��

	for (i = 0; i<num; i++)                     //��ʼ����
	{
		printf("\ni = %d\n", i);                //�����ǰ��������
		
		for (j = 0; j < CHROMNUM; j++)
		{
			popnext[j] = popcurrent[j];         //������Ⱥ
		}

		pickchroms(popnext);                    //ѡȡ��Ӧ�Ƚϸߵĸ������������
		crossover(popnext);                     //��������Ӵ�
		mutation(popnext);                      //�Ӵ��������

		for (j = 0; j < CHROMNUM; j++)
		{
			popcurrent[j] = popnext[j];         //��Ⱥ����
		}
	}

	for (i = 0; i < CHROMNUM; i++)
	{
		if (popcurrent[i].fit > Max)
		{
			Max = popcurrent[i].fit;
			j = x1(popcurrent[i]);
			k = x2(popcurrent[i]);
		}

	}
	printf("\n�� x1 = %d, x2 = %d ʱ�������õ����ֵΪ: %d ", j, k, Max);
	printf("\n������������� ");

	flushall();                                 //�������
	getchar();

	return 0;
}
