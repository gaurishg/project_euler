#include<stdio.h>

#define LIMIT 100000001ll // More than this is not compilable
#define FIND_UPTO 1000000
#define DYNAMIC
#define LOWER_LIMIT 500001ll // See project euler overview for this

long long int arr[LIMIT];

void initiaze_array()
{
    arr[0] = 0ll;
    arr[1] = 1ll;
    for(long long int i=2ll; i<LIMIT; ++i)
        arr[i] = -1ll;
}

long long int collatz_length_dynamic_programming(long long int number)
{
    long long int length = 1;
    long long int next;

    while(number > LIMIT - 1)
    {
        if(number % 2)
            number = 3 * number + 1;
        else
            number = number / 2;
        ++length;
    }

    if(arr[number] != -1) // it covers 0 and 1
        return arr[number];

    if(number % 2)
        next = 3 * number + 1;
    else
        next = number / 2;

    length += collatz_length_dynamic_programming(next);
    arr[number] = length;
    return length;
}

long long int collatz_length(long long int number)
{
    long long int length = 1;
    while(number != 1)
        if(number%2)
        {
            number = 3 * number + 1;
            length++;
        }
        else
        {
            number /= 2;
            length++;
        }
    return length;
}

int main(int argc, char const *argv[])
{
    long long int max_length = 1, number = 1, length;

    #ifdef DYNAMIC
    initiaze_array();
    #endif

    for(long long int i=LOWER_LIMIT; i<FIND_UPTO; ++i)
    {
        #ifdef DYNAMIC
        length = collatz_length_dynamic_programming(i);
        #else
        length = collatz_length(i);
        #endif

        if(length>max_length)
        {
            number = i;
            max_length = length;
        }

        if(i%10000 == 0)
            printf("Checked %d numbers\n", i);
    }

    printf("%lld has max length: %lld\n", number, max_length);
    return 0;
}
