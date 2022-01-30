#include<iostream>
#include<stdlib.h>


int main(int argc, char const *argv[])
{
    int i = 0, a = 10;
    int *p = NULL;
    while (i <  4000)
    {
        p = (int*)malloc(4000 * sizeof(int));
        i++;
    }
    
    return 0;
}

