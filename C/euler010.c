#include<stdio.h>
#include"myfunctions.h"

#define N 2000000

int main(int argc, char const *argv[])
{
    long long int n=2;
    long long int sum = 0;

    for(long long int i=2; i<N; ++i)
        if(is_prime(i))
            sum += i;
    printf("%lld", sum);
    return 0;
}
