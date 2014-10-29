#include<iostream>
#include<cstdio>
#include<cmath>
#include<stdlib.h>
int main()
{
    long a,b;
    while(scanf("%ld %ld",&a,&b)==2 && a && b)
    {
        long k = abs(a-b);
        long m = sqrt(k);
        int c = 0;
        for(long i=1; i<=m; i++)
        {
            if(k%i==0)
            {
                c++;
                if(i!=k/i)
                    c++;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
