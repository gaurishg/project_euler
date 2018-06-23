#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include"bigintfunctions.h"

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

int main()
{
    char a[] = "2", b[] = "15";
    printf("Max integer:\t\t %d\n", INT_MAX);
    printf("Max long integer:\t %ld\n", LONG_MAX);
    printf("Max long long integer:\t %lld\n", LLONG_MAX);
    printf("Path: %s\n", path_name("This,is,the,path,to,file"));
    printf("%s + %s = %s\n",a, b, add(a, b));
    // printf("%s - %s = %s\n", a, b, substract(a, b));
    printf("%s * %s = %s\n", a, b, multiply(a, b));
    printf("%s ** %s = %s\n", a, b, big_pow(a, b));
    return 0;
}
