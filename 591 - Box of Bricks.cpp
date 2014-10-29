#include<stdio.h>
int main()
{
    int n,count=1;
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        int sum=0;
        int *k = new int [n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&k[i]);
            sum+=k[i];
        }
        sum/=n;
        int steps=0;
        for(int i=0;i<n;i++)
        {
            if(k[i]>sum)
                steps+= (k[i]-sum);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",count++,steps);
        delete k;

    }
    return 0;
}
