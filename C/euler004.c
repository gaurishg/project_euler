#include<stdio.h>

int is_palindrome(int n)
{
	int n1 = n, n2 = 0;
	while(n)
	{
		n2 = n2 * 10 + n % 10;
		n/=10;
	}
	return n1 == n2;
}

int main()
{
	int largest_palindrome = 0;
	for(int i=100; i<998; ++i)
		for(int j=i+1; j<999; ++j)
			if(is_palindrome(i*j) && largest_palindrome < i*j)
				largest_palindrome = i*j;
	printf("%d", largest_palindrome);

	return 0;
}
