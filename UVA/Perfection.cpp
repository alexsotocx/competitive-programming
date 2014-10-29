#include<cmath>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
long sumdivisors(int n)
{
    long sum=1;
    int m = sqrt(n);
    for(int i=2;i<=m;i++)
    {
        if(n%i==0)
        {
            sum+=i;
            if(i!=n/i)
                sum+=n/i;
        }
    }
    return sum;
}
int main()
{
    int n;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n)==1 && n)
    {
        if(n==1)
        {
            printf("%5d  DEFICIENT\n",n);
            continue;
        }

        int sum = sumdivisors(n);
        if(sum==n)
            printf("%5d  PERFECT\n",n);
        else if(sum>n)
            printf("%5d  ABUNDANT\n",n);
        else
            printf("%5d  DEFICIENT\n",n);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
