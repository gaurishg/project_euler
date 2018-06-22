#include<stdio.h>

int main()
{
	long long int n = 600851475143ll;
	// printf("%lld", n);
	while(n%2 == 0)
		n/=2;
	if(n == 1)
	{
		printf("2");
		return 0;
	}

	long long int i;
	for(i=3; n >= i; i+=2)
	{
		while(n%i == 0)
			n/=i;
	}
	printf("%lld", i-2);

	return 0;
}
