#include<cstdio>
#include<cmath>
int main()
{
    int a,b,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",(int)(ceil((a-2.0)/3.0) + ceil((b-2.0)/3.0)));
    }
    return 0;
}
