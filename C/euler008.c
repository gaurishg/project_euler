#include<stdio.h>

#define N 13

long long int product(char *arr)
{
    long long int numbers[N];
    for(int i=0; i<N; ++i)
        numbers[i] = arr[i] - '0';
    long long int product = 1;
    for(int i=0; i<N; ++i)
        product *= numbers[i];
    return product;
}

int main(int argc, char const *argv[])
{
    char arr[1001];
    arr[1000] = 0; // NULL character
    int i=0, ch;

    while( (ch=getchar()) != EOF)
    {
        if(ch >= '0' && ch <= '9')
            arr[i++] = ch;
    }

    // printf("%s", arr);

    long long int p = 0;
    for(i=0; i<1000-N; ++i)
    {
        long long int temp = product(arr+i);
        if(p<temp)
            p = temp;
    }
    printf("%lld", p);
    return 0;
}
