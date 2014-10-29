#include<stdio.h>
int main()
{
    /*int N,M;
    while(scanf("%d %d",&N,&M))
    {
        if(!N & !M)
            break;
        int mn = N-M;
        long int fact=1;
        if(mn)
           for(int i=mn+1; i<=N;fact*=)
    }*/
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &a,&b);
        if(a<b)
            printf("<\n");
        else if(a>b)
            printf(">\n");
        else
            printf("=\n");
    }

}
