#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    // 2/n = 1/n + 1/n
    //     = 1/n + 1/x + 1/y

    // i.e. 1/n = 1/x + 1/y
    //          = (x+y)/(x*y)
    //      x*y = n*x + n*y
    //      x*y - n*y = n*x
    //      y*(x - n) = n*x
    //      y = (n*x)/(x-n)
    // so, x must be greater than n
    // let, x = n+1,
    // then y = n*(n+1)/(n+1-n) = n*(n+1), satisfied !!

    // n, x, y is solution, where x = n+1, y = n*(n+1)
    // for n=1, no solution, because 2/1 = 2 = 1 + 1
    if(n==1) printf("-1\n");
    else printf("%d %d %d\n", n, n+1, n*(n+1));
    return 0;
}
