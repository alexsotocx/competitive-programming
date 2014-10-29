#include <stdio.h>
int main()
{
    int n;
    char *fact[14];
    fact[8]="40320";
    fact[9]="362880";
    fact[10]="3628800";
    fact[11]="39916800";
    fact[12]="479001600";
    fact[13]="6227020800";
    while(scanf("%d",&n)==1)
    {
        if(n<0)
        {
            if((-1*n)%2)
                printf("Overflow!\n");
            else
                printf("Underflow!\n");
        }
        else if(n<8)
            printf("Underflow!\n");
        else if(n<=13)
            printf("%s\n",fact[n]);
        else
            printf("Overflow!\n");
    }
    return 0;
}
