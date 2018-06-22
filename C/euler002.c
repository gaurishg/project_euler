#include<stdio.h>

#define N 4000000

int main()
{
	int a=3, b=5, sum = 2, i=0;

	for(; a<N;)
	{
		sum += (a+b);
		b = a + b;
		a = b - a;

		b = a + b;
		a = b - a;

		b = a + b;
		a = b - a;
	}
	printf("%d", sum);

	return 0;
}
