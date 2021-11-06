#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    int* Fib = malloc(sizeof(int) * (n+1));
    Fib[0]=1, Fib[1]=2;
    for(int i=2 ; i <= n; ++i)
    {
        Fib[i] = Fib[i-1] + Fib[i-2];
    }

    // printf("There are %d ways to climb to the top.", Fib[n]);

    volatile char *tx = (volatile char *)0x40002000;
    char *str = "There are "; //The largest number in the array is &#34;;
    while (*str)
    {
        *tx = *str;
        str++;
    }

    volatile int *tx2 = (volatile int *)0x40000008;
    *tx2 = Fib[n];
    
    *str = " ways to climb to the top.";
    while (*str)
    {
        *tx = *str;
        str++;
    }
}