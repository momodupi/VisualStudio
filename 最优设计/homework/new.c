#include "stdio.h"
#include "math.h"

float mX[2] = { -1.2, 1.0 };

float e = 0;
float y = 0;
int count = 0;

void FastGra(float x1, float x2, float fe)
{
	float a = 0;
	float b = 0;
	float norm = 0;
	float y = 0;

	float X[2], S[2], dY[2], A[2][2];

	X[0] = x1;
	X[1] = x2;
	y = 100 * powf(x2 - powf(x1, 2), 2) + powf((1 - x1), 2);

	printf("\n y = %f; X = [%f, %f]\n", y, X[0], X[1]);

	dY[0] = 400 * (powf(X[0], 3) - X[0] * X[1]) + 2 * X[0] - 2;
	dY[1] = 200 * (X[1] - powf(X[0], 2));

	norm = sqrtf(powf(dY[0], 2) + powf(dY[1], 2));
	printf("\n%f\n", norm);

	count++;

	if (norm > fe)
	{
		S[0] = -dY[0] / norm;
		S[1] = -dY[1] / norm;
		printf("\n%f %f\n", S[0], S[1]);

		A[0][0] = 1200 * powf(X[0], 2) - 400 * X[1] + 2;
		A[0][1] = -400 * X[0];
		A[1][0] = -400 * X[0];
		A[1][1] = 200;

		printf("\n%f %f %f %f\n", A[0][0], A[0][1], A[1][0], A[1][1]);

		a = -((dY[0] * S[0]) + (dY[1] * S[1]));
		b = (A[0][0] * powf(S[0], 2)) + (A[0][1] * S[0] * S[1]) + (A[1][0] * S[0] * S[1]) + (A[1][1] * powf(S[1], 2));
		a = a / b;
		printf("\n%f\n", a);
		X[0] = X[0] + a * S[0];
		//X[1] = X[1] + a * S[1];
		X[1] = X[0];
		y = 100 * powf(X[1] - powf(X[0], 2), 2) + powf((1 - X[0]), 2);

		printf("\nX[%f, %f], F(X) = %f\n", X[0], X[1], y);
		
		FastGra(X[0], X[1], fe);
	}
	else
	{
		mX[0] = X[0];
		mX[1] = X[1];
	}
}


void Newton(float x1, float x2, float fe)
{
	float a = 0;
	float b = 0;
	float norm = 0;
	float norm_ = 0;
	float y = 0;

	float X[2], S[2], dY[2], A[2][2], A_[2][2];

	X[0] = x1;
	X[1] = x2;
	y = 100 * powf(x2 - powf(x1, 2), 2) + powf((1 - x1), 2);

	printf("\n y = %f; X = [%f, %f]\n", y, X[0], X[1]);

	dY[0] = 400 * (powf(X[0], 3) - X[0] * X[1]) + 2 * X[0] - 2;
	dY[1] = 200 * (X[1] - powf(X[0], 2));

	norm = sqrtf(powf(dY[0], 2) + powf(dY[1], 2));
	printf("\n%f\n", norm);

	count++;

	if (norm > fe)
	{
		A[0][0] = 1200 * powf(X[0], 2) - 400 * X[1] + 2;
		A[0][1] = -400 * X[0];
		A[1][0] = -400 * X[0];
		A[1][1] = 200;

		norm_ = sqrtf(powf((A[0][0] * A[1][1] + A[0][1] * A[1][0]), 2));
		A_[0][0] = A[1][1] / norm_;
		A_[0][1] = -A[0][1] / norm_;
		A_[1][0] = -A[1][0] / norm_;
		A_[1][1] = A[0][0] / norm_;

		X[0] = X[0] - (A_[0][0] * dY[0] + A_[0][1] * dY[1]);
		X[1] = X[1] - (A_[1][0] * dY[0] + A_[1][1] * dY[1]);

		y = 100 * powf(X[1] - powf(X[0], 2), 2) + powf((1 - X[0]), 2);

		printf("\nX[%f, %f], F(X) = %f\n", X[0], X[1], y);

		Newton(X[0], X[1], fe);
	}
	else
	{
		mX[0] = X[0];
		mX[1] = X[1];
	}
}


int main(void)
{
	FastGra(mX[0], mX[1], 0.001);
	//Newton(mX[0], mX[1], 0.008);
	printf("\r\n count = %d", count);
	getchar();
}