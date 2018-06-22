#include<stdio.h>

#define N 4

int main(int argc, char const *argv[])
{
    long long int a[20][20];
    char ch[3];
    ch[2] = 0;

    for(int i=0; i<20; i++)
        for(int j=0; j<20; ++j)
        {
            scanf("%s", ch);
            a[i][j] = (ch[0]-'0') * 10 + ch[1]-'0';
        }
    
    long long int max_product = 0, product;

    for(int i=0; i<20; ++i)
    {
        for(int j=0; j<20; ++j)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Horizontal
    for(int i=0; i<20; ++i)
        for(int j=0; j<17; ++j)
        {
            product = a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
            if(max_product < product)
                max_product = product;
        }
    printf("Horizontal done.\n");

    // Vertical
    for(int i=0; i<17; ++i)
        for(int j=0; j<20; ++j)
        {
            product = a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
            if(max_product < product)
                max_product = product;
        }
    printf("Vertical done.\n");
    
    // Diagonal
    for(int i=0; i<17; ++i)
        for(int j=0; j<17; ++j)
        {
            product = a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
            if(max_product < product)
                max_product = product;
        }
    printf("Diagonal done.\n");

    // Cross diagonal
    for(int i=0; i<17; ++i)
        for(int j=3; j<20; ++j)
        {
            product = a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
            if(max_product < product)
                max_product = product;
        }

    printf("%lld", max_product);
    return 0;
}
