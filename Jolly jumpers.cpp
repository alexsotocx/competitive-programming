#include<stdlib.h>
#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        bool *jolly = new bool[n+1];
        for(int i=1; i<n+1; jolly[i++]=true);
        int *num=new int[n];
        for(int i=0; i<n; i++)
            scanf("%d",&num[i]);

            for(int i=0; i<n-1; i++)
            {
                int c=abs(num[i]-num[i+1]);
                if(c>n-1)
                    break;
                jolly[c]=false;
            }

            bool ok=true;
            for(int i=1; i<n; i++)
            {
                if(jolly[i])
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
                printf("Jolly\n");
            else
                printf("Not jolly\n");

    }
    return 0;
}
