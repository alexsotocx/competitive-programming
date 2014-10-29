#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        if(n==2)
            printf("0\n");
        else
            printf("%d\n",n/2);
        scanf("%d",&n);
    }
    return 0;
}
