#include<stdio.h>

#define N 1000

int main(int argc, char const *argv[])
{
    int a, b, c;
    int i=0;
    for(a=1; a<N/2; ++a)
        for(b=a+1; b<N; ++b)
            for(c=b+1; c<N; ++c)
            {
                i++;
                if(a+b+c == N)
                {
                    if(a*a + b*b == c*c)
                    {
                        printf("Loop ran %d times\n", i);
                        printf("%d", a*b*c);
                        return 0;
                    }
                }
            }
    return 0;
}
