#include<iostream>
#include<cstdio>
#include<cmath>
#include<stdlib.h>
int main()
{
    long long a,b,n;
    while(scanf("%lld %lld %lld",&a,&b,&n)==3)
    {
        if(!a && !n && !b)
            break;
        switch(n%5)
        {
            case 0:
                printf("%lld\n",a);
                break;
            case 1:
                printf("%lld\n",b);
                break;
            case 2:
                printf("%lld\n",(1+b)/a);
                break;
            case 3:
                printf("%lld\n",(a+1+b)/(a*b));
                break;
            case 4:
                printf("%lld\n",(a+1)/b);
                break;

        }

    }
    return 0;
}
