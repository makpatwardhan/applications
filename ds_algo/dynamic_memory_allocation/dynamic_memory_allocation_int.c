#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

void allocate_single_int()
{
    int i = 5;
    int *ptr = (int *)malloc(sizeof(int));
    assert(ptr != NULL);
    ptr = &i;
    printf("%d\n",*ptr);
}

void allocate_int_array()
{
    int *p = (int *)malloc(5*sizeof(int));

    for(int i = 0 ; i < 5 ;i++)
    {
        p[i] = i;
    }
    for(int i = 0 ; i < 5 ;i++)
    {
        printf("%d\n",p[i]);
    }
    free(p);
}
int main(void)
{
    allocate_single_int();
    allocate_int_array();
}
