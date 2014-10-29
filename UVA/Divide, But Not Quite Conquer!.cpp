#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    while(scanf("%lld%lld",&n,&m)==2)
    {
        double k = log(n)/log(m);
        if(k==floor(k))
        {
            printf("%lld",n);
            while(n>1)
            {
                n/=m;
                printf(" %lld",n);
            }
            printf("\n");
        }
        else
            printf("Boring!\n");
    }
    return 0;
}
