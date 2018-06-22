#include<stdio.h>
#include"myfunctions.h"

// #define N 100000000ll
#define TARGET 10001ll

int main(int argc, char const *argv[])
{
    long long int n = 1;
    long long int count = 0;
    long long int prime = 2;
    while(count < TARGET)
    {
        if(is_prime(++n))
            count++;
    }
    printf("Prime(%lld)= %lld", count, n);
    return 0;
}
