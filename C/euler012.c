#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    int input;
    printf("Enter number: ");
    scanf("%d", &input);

    long long int n, n1;
    for(long long int i=1; ; ++i)
    {
        n = i * (i+1) / 2;
        n1 = n;
        // printf("%lld has ", n);
        int divisors = 1;
        int t = 0;
        for(t=0; n%2 == 0; ++t, n/=2);
        divisors *= (t+1);

        for(t=0; n%3 == 0; ++t, n/=3);
        divisors *= (t+1);

        for(long long int f=5; f <= n ; f+=6)
        {
            for(t=0; n%f == 0; ++t, n/=f);
            divisors *= (t+1);

            for(t=0; n%(f+2) == 0; ++t, n/=(f+2));
            divisors *= (t+1);
        }

        // printf("%d divisors.\n", divisors);
        
        if(divisors > input)
        {
            printf("%lld", n1);
            break;
        }
    }
    return 0;
}
