#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* multiply(char*, char*);
char* add(char*, char*);
char* substract(char*, char*);
char* substract_one(char*, int);
char* big_pow(char*, char*);
int is_zero(char *);
int numberlen(char*);

char* multiply(char* a_, char* b_)
{
    int length_a, length_b;
    int len_a_ = strlen(a_);
    int len_b_ = strlen(b_);
    int i;
    char *temp;

    for(i=0; a_[i]=='0'; ++i);
    char *a = malloc(sizeof(char) * len_a_ + 1 - i);
    strcpy(a, a_+i);

    for(i=0; b_[i]=='0'; ++i);
    char *b = malloc(sizeof(char) * len_b_ + 1 - i);
    strcpy(b, b_+i);

    length_a = strlen(a);
    length_b = strlen(b);

    int length_answer = length_a + length_b + 1;
    char *answer = malloc(sizeof(char) * length_answer);
    for(i=0; i<length_answer-1; ++i)
    {
        answer[i] = '0';
    }
    answer[i] = 0;

    while(!is_zero(b))
    {
        temp = add(answer, a);
        substract_one(b, length_b);
        for(i=0; temp[i]=='0'; ++i);
        strcpy(answer, temp+i);
        free(temp);
    }

    free(a);
    free(b);
    return answer;
}

char* add(char* a, char *b)
{
    int length_a = strlen(a);
    int length_b = strlen(b);
    int length_answer = (length_a>length_b?length_a:length_b) + 2;
    // + 2 because 99 + 1 = 100 and one extra for null

    char* answer = malloc(sizeof(char) * length_answer);
    answer[length_answer-1] = 0;

    char* small = length_a<length_b?a:b;
    char* big = length_a>=length_b?a:b;
    int small_len = strlen(small);
    int big_len = strlen(big);
    int size_diff = big_len - small_len;
    int carry = 0;
    int temp, i;
    for(i = 0;  i<small_len; ++i)
    {
        answer[length_answer - 2 - i] = big[big_len - 1 -i] + small[small_len - 1 -i] - '0' + carry;
        if(answer[length_answer - 2 -i] > '9')
        {
            temp = answer[length_answer - 2 -i] - '0';
            carry = temp / 10;
            answer[length_answer -2 - i] = temp % 10 + '0';
        }
        else
            carry = 0;
    }
    for(; i<big_len; ++i)
    {
        answer[length_answer - 2 - i] = big[big_len - 1 - i] + carry;
        if(answer[length_answer - 2 -i] > '9')
        {
            temp = answer[length_answer - 2 -i] - '0';
            carry = temp / 10;
            answer[length_answer -2 - i] = temp % 10 + '0';
        }
        else
            carry = 0;
    }
    for(; i<length_answer-1; ++i)
    {
        answer[length_answer - 2- i] = '0' + carry;
        if(answer[length_answer - 2 -i] > '9')
        {
            temp = answer[length_answer - 2 -i] - '0';
            carry = temp / 10;
            answer[length_answer -2 - i] = temp % 10 + '0';
        }
        else
            carry = 0;
    }
    answer[i] = 0;

    return answer;
}

int is_zero(char *a)
{
    for(int i=0; a[i]!=0; ++i)
        if(a[i]>'0')
            return 0;
    return 1;
}


char *substract(char *a_, char *b_) // a should be gt b for now
{
    int len_a_ = strlen(a_);
    int len_b_ = strlen(b_);

    char *a = malloc(sizeof(char) * len_a_ + 1);
    char *b = malloc(sizeof(char) * len_b_ + 1);

    strcpy(a, a_);
    strcpy(b, b_);

    // Get rid of leading 0s
    for(; a[0]=='0'; ++a);
    for(; b[0]=='0'; ++b);

    int length_a = strlen(a);
    int length_b = strlen(b);

    char *small;
    char *big;

    if(length_a<length_b)
    {
        small = a;
        big = b;
    }
    else if(length_a>length_b)
    {
        big = a;
        small = b;
    }
    else // lengths are equal
    {
        if(strcmp(a, b) > 0) // a>b
        {
            big = a;
            small = b;
        }
        else
        {
            small = a;
            big = b;
        }
    }

    int big_len = strlen(big);
    int small_len = strlen(small);
    int length_answer = big_len + 1;
    int i;

    char* answer = malloc(sizeof(char) * length_answer);
    answer[length_answer - 1] = 0;

    for(i=0; i<small_len; ++i)
    {
        if(big[big_len - 1 - i] < small[small_len - 1 - i])
        {
            big[big_len - 1 - i]+= 10;
            substract_one(big, big_len -1 -i);
        }
        answer[length_answer - 2 - i] = big[big_len - 1 - i] - small[small_len - 1 -i] + '0';
    }
    for(; i<big_len; ++i)
    {
        answer[length_answer - 2 - i] = big[big_len - 1 -i];
    }
    
    free(a);
    free(b);
    return answer;
}

char* substract_one(char *a, int size)
{
    if(a[size-1] == '0')
    {
        a[size-1] = '9';
        return substract_one(a, size-1);
    }
    --a[size-1];
    return a;
}

char* big_pow(char* a_, char* b_)
{
    int i;
    for(i=0; a_[i]=='0'; ++i);
    int length_a = strlen(a_) - i;
    char *a = malloc(sizeof(char) * length_a + 1);
    strcpy(a, a_+i);

    for(i=0; b_[i]=='0'; ++i);
    int length_b = strlen(b_) - i;
    char *b = malloc(sizeof(char) * length_b + 1);
    strcpy(b, b_+i);

    char *temp, *answer;
    temp = NULL;

    answer = multiply(a, "1");
    substract_one(b, length_b);

    while(!is_zero(b))
    {
        temp = answer;
        answer = multiply(answer, a);
        free(temp);
        substract_one(b, length_b);
    }

    free(a);
    free(b);
    return answer;
}

int numberlen(char* a)
{
    int i;
    for(i=0; a[i]=='0'; ++i);
    int length = 0;
    for(; a[i]!=0; ++i)
        length++;
    return length;
}