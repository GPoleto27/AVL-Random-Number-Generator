#include "Random.h"

void geraAleatorio(long long unsigned int *num)
{
    register int i;
    for (i = 0; i < 1 +(rand() % 15); i++)
    {
        *num *= 10;
        *num += rand()%10;
    }
}

void MaxMin1(int *a, long long unsigned int *Max, int *Min)
{
    register int i;
    *Max = a[0];
    *Min = a[1];
    for (i = 2; i < MAX_NUM; i++)
    {
        if (a[i] > *Max)
            *Max = a[i];
        if (a[i] < *Min)
            *Min = a[i];
    }
}

void MaxMin2(int *a, long long unsigned int *Max, int *Min)
{
    register int i;
    *Max = a[0];
    *Min = a[0];
    for (i = 1; i < MAX_NUM; i++)
    {
        if (a[i] > *Max)
            *Max = a[i];
        else if (a[i] < *Min)
            *Min = a[i];
    }
}

void MaxMin3(int *a, long long unsigned int *Max, int *Min)
{
    int fimDoAnel;
    register int i;
    if((MAX_NUM % 2)>0)
    {
        a[MAX_NUM]=a[MAX_NUM-1];
        fimDoAnel = MAX_NUM;
    }
    else
        fimDoAnel = MAX_NUM-1;

    if(a[0]>a[1])
    {
        *Max = a[0];
        *Min = a[1];
    }
    else
    {
        *Max = a[1];
        *Min = a[0];
    }

    i=2;

    while (i<=fimDoAnel)
    {
        if(a[i]>a[i+1])
        {
            if(a[i] > *Max)
                *Max=a[i];
            if(a[i+1] < *Min)
                *Min=a[i+1];
        }
        else
        {

            if(a[i] < *Min)
                *Min=a[i];
            if(a[i+1] > *Max)
                *Max=a[i+1];
        }
        i+=2;
    }
}
