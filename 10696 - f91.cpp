#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        int a = n>=101 ? (n-10):91;
        printf("f91(%d) = %d\n",n,a);
        scanf("%d",&n);
    }
    return 0;
}
