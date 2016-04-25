#include "stdio.h"
#include "math.h"


#define MAXNUM 1000

typedef struct Matrix
{
	float a1;
	float a2;
	float value;
}Matrix;


typedef struct HMatrix
{
	float a11;
	float a12;
	float a21;
	float a22;
	float value;
}HMatrix;

Matrix X, Y, dY, S;


/**
* @brief  获取目标函数
* @param  X
* @retval fvalue
*/
float Fx(Matrix *X)
{
	float fvalue = 0;
	fvalue = 100 * powf((X->a2 - (X->a1 * X->a1)), 2) + powf((1 - X->a1), 2);
	return fvalue;
}

/**
* @brief  计算梯度
* @param  Y
* @retval Y'
*/
void GetDeriv(Matrix *X, Matrix *Y)
{
	Y->a1 = 400 * X->a1 * (X->a1 - X->a2) + 2 * (X->a1 - 1);
	Y->a2 = 200 * (X->a2 - X->a1);
}

/**
* @brief  获取向量模
* @param  Y
* @retval fvalue
*/
float GetNorm(Matrix *X)
{
	float fvalue = 0;
	fvalue = sqrtf(powf(X->a1, 2) + powf(X->a1, 2));
	return fvalue;
}


/**
* @brief  最优梯度方向
* @param  X
* @retval S
*/
void GetDirection(Matrix *Y, Matrix *S)
{
	//梯度的模
	Y->value = GetNorm(Y);

	S->a1 = -(Y->a1) / Y->value;
	S->a2 = -(Y->a2) / Y->value;
}

/**
* @brief  获取步长
* @param  X
* @retval step
*/
float GetStep(Matrix *X, Matrix *Y, Matrix *S)
{
	float fa, fb, step;
	HMatrix A;
	A.a11 = 800 * X->a1 - 400 * X->a2 + 2;
	A.a12 = -200;
	A.a21 = -200;
	A.a22 = 200;
	
	fa = -Y->a1 * S->a1;
	fb = A.a11 * S->a1 * S->a1 + A.a21 * S->a1 * S->a2 + A.a12 * S->a1 * S->a2 + A.a22 * S->a2 * S->a2;
	step = fa / fb;
}

/**
* @brief  迭代寻找最优点
* @param  X
* @retval None
*/
void Searching(Matrix *X, Matrix *Y, Matrix *S)
{
	float step;
	
	//计算梯度
	GetDeriv(X, Y);

	GetDirection(Y, S);
	step = GetStep(X, Y, S);

	X->a1 = X->a1 + step * S->a1;
	X->a2 = X->a2 + step * S->a2;
}



int main(void)
{
	long int i;
	float e = 0;

	//赋初值
	X.a1 = -1.2;
	X.a2 = 1.0;
	/*
	for (i = 0; i < MAXNUM; i++)
	{
		Searching(&X, &Y, &S);
		
		GetDeriv(&X, &Y);
		Y.value = GetNorm(&Y);
		if (Y.value < e)
		{
			break;
		}
	}*/

	printf("%d, %f, %f", i, Y.value, Fx(&X));

	getchar();

	return 0;
}