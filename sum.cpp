#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,k,p;
        scanf("%d %d %d",&n,&k,&p);
        int aux = (p%n)+k;
        while(aux>n)
        aux = aux%n;
        printf("Case %d: %d\n", i,aux );
    }
    return 0;
}
