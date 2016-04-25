#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

#define CHROMNUM   4
#define CHROMPOS   8



//定义染色体结构
typedef struct Chrom
{
	short int bit[CHROMPOS];
	int fit;
}chrom;


/**
  * @brief  二元函数关系
  * @param  x: 自变量
  * @retval fy: 因变量
  */
int y(int x1, int x2)
{
	int fy = 0;
	fy = -(x1 * x1) - (x2 * x2) + 8;
	if (fy > 7)fy = 7;
	return(fy);
} 

/**
  * @brief  将二进制转化为十进制
  * @param  popcurrent: 当前染色体结构体
  * @retval z: 十进制数
  */
int x1(chrom popcurrent)
{
	int z;
	z = (popcurrent.bit[0] * 1) + (popcurrent.bit[1] * 2) + (popcurrent.bit[2] * 4);

	if (popcurrent.bit[3] == 1)
	{
		z = z*(-1);                               //转换前为有符号数
	}

	return(z);
	flushall();                                 //清除缓冲
}

int x2(chrom popcurrent)
{
	int z;
	z = (popcurrent.bit[4] * 1) + (popcurrent.bit[5] * 2) + (popcurrent.bit[6] * 4);

	if (popcurrent.bit[7] == 1)
	{
		z = z*(-1);                               //转换前为有符号数
	}

	return(z);
	flushall();                                 //清除缓冲
}


/**
  * @brief  随机生成初始种群
  * @param  popcurrent[CHROMNUM]: 染色体结构体数组
  * @retval 无
  */
void *evpop(chrom popcurrent[CHROMNUM])
{
	int i, j, value;
	int random;
	for (j = 0; j < CHROMNUM; j++)                            //从种群中的第1个染色体到第m个染色体
	{
		for (i = 0; i < CHROMPOS; i++)                        //从染色体的第1个基因位到第n个基因位
		{
			random = rand();                                  //生产0-1随机数
			random = (random % 2);                            
			popcurrent[j].bit[i] = random;                    //赋值到染色体
		}

		popcurrent[j].fit = y(x1(popcurrent[j]), x2(popcurrent[j]));              //计算染色体的适应度；
		//输出染色体编码
		printf("\n 染色体%d编码为: popcurrent[%d] = %d%d%d%d%d%d%d%d;", j, j, popcurrent[j].bit[7], popcurrent[j].bit[6], popcurrent[j].bit[5], popcurrent[j].bit[4], popcurrent[j].bit[3], popcurrent[j].bit[2], popcurrent[j].bit[1], popcurrent[j].bit[0]);
		printf("值为: [%d, %d]; 适应度为: %d", x2(popcurrent[j]), x1(popcurrent[j]), popcurrent[j].fit);
	}
	return(0);
	flushall();                                 //清除缓冲
}


/**
  * @brief  选择函数体
  * @param  popcurrent[4] 当前染色体
  * @retval 无
  */
void *pickchroms(chrom popcurrent[CHROMNUM])
{
	int i, j;
	chrom temp;

	for (i = 0; i < CHROMNUM - 1; i++)                           //根据个体适应度来排序
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
		printf("\n当前为: popnext[%d] 适应度为: %d\n", i, popcurrent[i].fit);
	}
	flushall();                                 //清除缓冲
}

/**
  * @brief  交叉产生后代
  * @param  popnext[4] 下一代染色体
  * @retval 无
  */
void *crossover(chrom popnext[CHROMNUM])
{
	int random;
	int i;
	random = rand();                              //在染色体范围内随机产生交叉点
	random = ((random % (CHROMPOS - 1)) + 1);

	for (i = 0; i < random; i++)
	{
		popnext[2].bit[i] = popnext[0].bit[i];    //交叉产生后代，popnext[2]为孩子1，popnext[3]为孩子2
		popnext[3].bit[i] = popnext[1].bit[i];    
	}

	for (i = random; i < CHROMPOS; i++)
	{
		popnext[2].bit[i] = popnext[1].bit[i];
		popnext[3].bit[i] = popnext[0].bit[i];
	}

	for (i = 0; i < CHROMNUM; i++)
	{
		popnext[i].fit = y(x1(popnext[i]), x2(popnext[i]));        //计算新种群适应度
	}

	for (i = 0; i < CHROMNUM; i++)
	{
		printf("\n交叉后为: popnext[%d] = %d%d%d%d%d%d;", i, popnext[i].bit[5], popnext[i].bit[4], popnext[i].bit[3], popnext[i].bit[2], popnext[i].bit[1], popnext[i].bit[0]);
		printf(" 值为: [%d, %d]; 适应度为: %d\n", x1(popnext[i]), x2(popnext[i]), popnext[i].fit);
	}
	flushall();                                 //清除缓冲
}

/**
  * @brief  后代随机突变
  * @param  popnext[4] 下一代染色体
  * @retval 无
  */
void *mutation(chrom popnext[CHROMNUM])
{
	int random;
	int row, col;
	random = rand() % 50;                           //产生0到49的随机数；

	if (random == 1)                                //变异率为0.02(2%)；
	{
		row = rand() % CHROMNUM;                    //随机产生变异染色体号；
		col = rand() % CHROMPOS;                    //随机产生变异基因位号；

		if (popnext[row].bit[col] == 0)             //变异
		{
			popnext[row].bit[col] = 1;
		}
		else if (popnext[row].bit[col] == 1)
		{
			popnext[row].bit[col] = 0;
		}

		popnext[row].fit = y(x1(popnext[row]), x2(popnext[row]));     //计算变异后种群适应度

		printf("\n突变发生: popnext[%d] bit[%d]:=%d%d%d%d%d%d;", row, col, popnext[row].bit[5], popnext[row].bit[4], popnext[row].bit[3], popnext[row].bit[2], popnext[row].bit[1], popnext[row].bit[0]);
		printf(" 值为: [%d, %d]; 适应度为: %d\n", x1(popnext[row]), x2(popnext[row]), popnext[row].fit);
	}
	flushall();                                 //清除缓冲
}


/**
  * @brief  主函数
  * @param  无
  * @retval 0
  */
int main(void)
{
	int num;
	int i, j, k, Max;
	Max = 0;                                    //函数最大值

	printf("原函数为: y = -(x1 * x1) - (x2 * x2) + 9：\n");
    printf("\n请输入一个大于1的迭代次数：\n");

	scanf("%d", &num);                          //输入迭代次数
	
	while (num <= 1)                            
	{
		printf("\n请输入一个大于1的整数！\n");
		scanf("%d", &num);
	}

	chrom popcurrent[CHROMNUM];                 //定义初始种群
	chrom popnext[CHROMNUM];                    //定义子代种群
	evpop(popcurrent);                          //随机产生初始种群；

	for (i = 0; i<num; i++)                     //开始迭代
	{
		printf("\ni = %d\n", i);                //输出当前迭代次数
		
		for (j = 0; j < CHROMNUM; j++)
		{
			popnext[j] = popcurrent[j];         //更新种群
		}

		pickchroms(popnext);                    //选取适应度较高的个体来传播后代
		crossover(popnext);                     //交叉产生子代
		mutation(popnext);                      //子代随机变异

		for (j = 0; j < CHROMNUM; j++)
		{
			popcurrent[j] = popnext[j];         //种群更替
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
	printf("\n当 x1 = %d, x2 = %d 时，函数得到最大值为: %d ", j, k, Max);
	printf("\n按任意键结束！ ");

	flushall();                                 //清除缓冲
	getchar();

	return 0;
}
