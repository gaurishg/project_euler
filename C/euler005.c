#include<stdio.h>
#include"myfunctions.h"

int main(int argc, char const *argv[])
{
    /* code */
    long long int answer = 1;
    for(long long int i=2; i<=20; ++i)
        answer = lcm(answer, i);
    printf("%lld", answer);
    return 0;
}
