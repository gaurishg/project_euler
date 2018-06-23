#include<stdio.h>
#include"bigintfunctions.h"

int main()
{
    char base[100], power[100];
    printf("Enter base: ");
    scanf("%99s", base);
    printf("Enter exponent: ");
    scanf("%99s", power);
    char *answer = big_pow(base, power);
    printf("%s ^ %s = %s\n", base, power, answer);
    int sum = 0;
    for(int i=0; answer[i]!=0; ++i)
        sum+= answer[i] - '0';
    printf("Sum of digits: %d\n", sum);
    return 0;
}
