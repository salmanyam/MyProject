#include <stdio.h>

int steps;

double power(double x, int n)
{
	steps++;
	if(n == 1)return x;
	return power(x, n/2) * power(x, (n+1)/2);
}

int main()
{
	steps = 0;
	printf("Number of steps = %d, pow(1, 1000) = %lf\n", steps, power(1, 1000));
	return 0;
}
