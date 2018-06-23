#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int string_len(const char *arr)
{
    int length=0;
    for(; arr[length]!=0; ++length);
    return length;
}

char* path_name(const char* arr)
{
    char *path = malloc(sizeof(char) * (2 * string_len(arr)));
    int path_pos, arr_pos;
    for(path_pos = arr_pos = 0; arr[arr_pos]!=0; ++arr_pos)
    {
        if(arr[arr_pos] != ',')
        {
            path[path_pos++] = arr[arr_pos];
        }
        else
        {
            #ifdef _WIN32
            path[path_pos++] = '\\';
            path[path_pos++] = '\\';
            #else
            path[path_pos++] = '/';
            #endif
        }
    }
    path[path_pos++] = 0;

    return path;
}


long long int hcf(long long int a, long long int b)
{
    if(a<b)
    {
        long long int temp = a;
        a = b;
        b = temp;
    }

    // Now a is always greater than b
    while(b%a)
    {
        long long int temp = a;
        a = b%a;
        b = temp;
    }
    return a;
}

long long int lcm(long long int a, long long int b)
{
    return a * b / hcf(a, b);
}

int* prime_sieve(long long int size)
{
    int *sieve = malloc(sizeof(int) * size);
    if(sieve == NULL)
    {
        printf("Memory not available");
        exit(1);
    }
    long long int i;
    for(i=0; i<size; ++i)
    {
        sieve[i] = 1;
    }
    sieve[0] = sieve[1] = 0;

    for(i=2; i<size; ++i)
    {
        for(long long int j=i*i; j<size; j+=i)
        {
            sieve[j] = 0;
        }
    }

    return sieve;
}

int is_prime(long long int n)
{
    if(n==1)
        return 0;
    else if(n<4)
        return 1; // 2 and 3 are prime
    else if(n%2 == 0)
        return 0;
    else if(n<9)
        return 1; // already excluded 4, 6 and 8
    else if(n%3 == 0)
        return 0;
    else // use the fact that primes are of form : 6k+-1
    {
        double r = floor(sqrt(n));
        long long int f = 5;
        while(f <= r)
        {
            if(n % f == 0)
                return 0;
            else if(n%(f+2) == 0)
                return 0;
            f+=6;
        }
        return 1; // True in all other cases.
    }
}

long long factorial(long long int n)
{
    long long int factorial = 1;
    if(n <= 1)
        return 1ll;
    for(int i=1; i<=n; ++i)
        factorial *= i;
    return factorial;
}

#endif // MYFUNCTIONS_H
