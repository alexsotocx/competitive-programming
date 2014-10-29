#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(!n)
            break;
        if(n<4)
            printf("%d\n",n);
        else
            printf("%d\n",(n-3)*2+3);
    }
    return 0;
}
