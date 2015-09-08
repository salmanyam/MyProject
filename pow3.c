#include <stdio.h>

int steps;

double power(double x, int n)
{
	int a;
	steps++;
	if(n == 1)return x;

	a = power(x, n/2);

	if(n % 2 == 0)
		return a*a;
	else
		return a*a*x;
}

int main()
{
	steps = 0;
	printf("Number of steps = %d, pow(1, 1000) = %lf\n", steps, power(1, 1000));
	return 0;
}
