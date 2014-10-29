#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
#define N 1<<30
ll bin(ll low,ll up, ll tosearch)
{
    ll n;
    while(up>low)
    {
        n = (up + low)/2;
        ll x = (n*(n+1))/2;
        if (x==tosearch) return n;
        if(x>=tosearch) up = n;
        else low = n+1;
    }
    return low;

}
int main()
{
    ll n,a;
    while(scanf("%lld",&n)==1 )
    {
        a=bin(1ll,N,n);
        a--;
        printf("%lld/%lld\n",a + 2 - n + (a*(a+1ll))/2ll,n - (a*(a+1ll))/2ll);
    }
    return 0;
}
