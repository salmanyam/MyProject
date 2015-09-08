#include <stdio.h>

int rf(int n)
{
	if(n == 0)return 0;
	else if(n == 1) return 1;
	
	return rf(n-2) + rf(n-1);
}

int main()
{
	printf("%d\n", rf(46));
	return 0;
}
