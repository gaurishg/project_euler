#include<stdio.h>

#define N 100
int main(int argc, char const *argv[])
{
    long long int sum_of_squares = 0;
    long long int square_of_sum = 0;

    long long int n=N;

    for(long long int i=1; i<=n; ++i)
    {
        sum_of_squares += i*i;
        square_of_sum += i;
    }
    square_of_sum *= square_of_sum;

    printf("%lld", square_of_sum - sum_of_squares);
    return 0;
}
