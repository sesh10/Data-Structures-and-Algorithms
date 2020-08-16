#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    if (n < 2)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    printf("Enter index: ");
    scanf("%d", &n);
    printf("Fibonacci is %d", fib(n));
    return 0;
}
