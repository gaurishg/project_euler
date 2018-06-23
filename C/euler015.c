#include<stdio.h>

// #define N 2

int main(int argc, char const *argv[])
{
    long long int N;
    printf("Enter size of grid: ");
    scanf("%lld", &N);
    // printf("%lld\n", (factorial(2 * N) / (factorial(N) * factorial(N)))); // prints 0, mayble fact(2n) is overflowing

    long long int answer = 1;
    for(int i= 2*N; i>N; --i)
        if(i%2)
            answer *= i;
        else
            answer *= 2;
    for(int i=2; i<=N/2; ++i)
        answer /= i;

    printf("%lld\n", answer);
    return 0;
}
