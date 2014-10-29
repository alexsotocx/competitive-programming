#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n;i++)
    {
        int a,b,suma=0;
        scanf("%d", &a);
        scanf("%d", &b);
        if(a%2==1)
        {
            suma=a;
            for(int j=a+2;j<=b;j+=2)
                suma+=j;
        }
        else
        {
           for(int j=a+1;j<=b;j+=2)
                suma+=j;
        }
        printf("Case %d: %d\n", i, suma);
    }
    return 0;
}
