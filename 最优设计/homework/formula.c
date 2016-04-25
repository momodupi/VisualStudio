#include <stdio.h> 

#include <math.h> 
/*
int i = 0;

float f(float *x)
{
	float fi;
	fi = 60 - 10 * x[0] - 4 * x[1] + pow(x[0], 2) + pow(x[1], 2) - x[0] * x[1];

	return (fi);
}


void newton(float *x, float e)
{
	i++;
	float H[2][2] = { { 2, -1 }, { -1, 2 } };
	float H0[2][2] = { { 2.0 / 3.0, 1.0 / 3.0 }, { 1.0 / 3, 2.0 / 3.0 } };
	float g0[2], b[2] = { 0, 0 }, q;

	int i, j;

	g0[0] = 2 * x[0] - 10 - x[1];
	g0[1] = 2 * x[1] - 4 - x[0];

	printf("(%f\t%f)\t%f\t(%f\t%f)\n", x[0], x[1], f(x), g0[0], g0[1]);

	q = sqrt(pow(g0[0], 2) + pow(g0[1], 2));

	if (q > e)
	{
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j<2; j++)
			b[i] += H0[i][j] * g0[j];
		}

		for (i = 0; i < 2; i++)
		{
				x[i] = x[i] - b[i];
		}

		newton(x, e);
	}
	else
	{
		printf("\nx*=(%f,%f)\tmin f = %f\n", x[0], x[1], f(x));
	}
}


int main(void)
{
	float x[2] = {-1.2, 1.0};
	float e = 0;

	printf("\n\tx[2]\t\t\t f(x)\t\t\t g\n");

	newton(x, e);
	printf("\r\ni = %d\r\n", i);

	getch();
}
*/


float goldena(float x[2], float p[2])
{
	float a;
	a = (p[0] * p[0] + p[1] * p[1]) / (2 * p[0] * p[0] - 400 * x[1] * p[0] * p[0] + 1200 * x[0] * x[0] * p[0] * p[0] - 400 * x[0] * p[0] * p[1] - 400 * p[0] * p[1] + 200 * p[1] * p[1]);
	return a;
}

int main(void)

{
	float a = 0, x[2], p[2], g[2] = { 0, 0 }, e = 0.1, t;

	int i = 0;

	x[0] = 0;
	x[1] = 0;
	p[0] = -2 * (1 - x[0]) - 400 * (x[1] - x[0] * x[0])*x[0];
	p[1] = 200 * (x[1] - x[0] * x[0]);
	g[0] = -p[0];
	g[1] = -p[1];

	printf("\n\n");

	while (sqrt(g[0] * g[0] + g[1] * g[1]) > e && i <= 3000)
	{
		a = goldena(x, g);

		x[0] = x[0] + a*g[0];
		x[1] = x[1] + a*g[1];
		p[0] = -2 * (1 - x[0]) - 400 * (x[1] - x[0] * x[0])*x[0];
		p[1] = 200 * (x[1] - x[0] * x[0]);

		g[0] = -p[0];
		g[1] = -p[1];

		printf("di  %d  ci  t=%f  x1=%f\tx2=%f\ta=%f\n", ++i, sqrt(g[0] * g[0] + g[1] * g[1]), x[0], x[1], a);
	}
	printf("\nthe x[1]=%f,x[2]=%f y=%f", x[0], x[1], 100 * (x[1] - x[0] * x[0])*(x[1] - x[0] * x[0]) + (1 - x[0])*(1 - x[0]));
	getchar();
}
