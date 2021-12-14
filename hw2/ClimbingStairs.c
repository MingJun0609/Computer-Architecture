// #include <stdio.h>
// #include <stdlib.h>

int mod10(int a ) {
    unsigned int b = a & 1;           /* b = a mod 2 */
    a = a >> 1;			  /* a = a / 2   */

    /* now use code for a mod 5 */
    a = (a >> 16) + (a & 0xFFFF); /* sum base 2**16 digits */
    a = (a >>  8) + (a & 0xFF);   /* sum base 2**8 digits */
    a = (a >>  4) + (a & 0xF);    /* sum base 2**4 digits */
    if (a > 14) a = a - 15;
    /* now, we have mod 15 */
    if (a > 4) a = a - 5;
    if (a > 4) a = a - 5;

    return b + (a << 1);
}

void _start()
{
    int n = 10;
    int Fib[n+1];
    Fib[0]=1, Fib[1]=2;
    for(int i=2 ; i <= n; ++i)
    {
        Fib[i] = Fib[i-1] + Fib[i-2];
    }

    volatile char *tx = (volatile char *)0x40002000;
    const char *str = "There are ";

    while (*str)
    {
        *tx = *str;
        str++;
    }
    for (int i = 31; i >= 0; i--)
        if ((Fib[n] >> i) & 1)
            *tx = '1';
        else
            *tx = '0';
    const char *str2 = " ways to climb to the top.";
    while (*str2)
    {
        *tx = *str2;
        str2++;
    }
}