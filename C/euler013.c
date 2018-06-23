#include<stdio.h>
#include"myfunctions.h"

int main()
{
    char carr[100][51];
    long long int iarr[100], sum=0;
    FILE *input = fopen(path_name("inputs,input013.txt"), "r");

    // This shows that windows gcc created 32 bit binary
    // windows msvc creates 64 bit program
    // linux gcc also created 64 bit program
    printf("This is %d bit program.\n", sizeof(void*) * 8);

    for(int i=0; i<100; ++i) // This loops should run 100 times but it runs only 97 times
    {
        // Takes the number as character array/string
        fscanf(input, "%s", carr[i]);

        // Prints input line number and input just taken
        printf("%d: %s -> ", i+1, carr[i]);

        // Makes 13th character as null so that sscanf reads only 12 characters
        carr[i][12] = 0;

        // Convert number in string to long long int
        sscanf(carr[i], "%lld", iarr+i);

        // prints the converted number
        printf("%lld\n", iarr[i]);

        // adds the number to sum
        sum += iarr[i];
    }

    // This statement doesn't get printed at all on windows gcc
    // On linux/ubuntu gcc shows error: **stack smashing detected** Aborted (core dumped)
    // Runs fine on msvc on windows
    printf("%lld", sum);

    return 0;
}
