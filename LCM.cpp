#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
ll GCD (ll a,ll b)
{
    if(!b) return a;
    return GCD(b,a%b);
}
ll LCM(ll a,ll b)
{
    return (a*b)/GCD(a,b);
}
int main()
{
    ll k,lcm;
    while(scanf("%lld",&k)==1 && k)
    {
        lcm =1;
        for(ll i=2;i<=k;i++)
            lcm=LCM(lcm,i);
        int x;
        while(lcm>1)
        {
            x = lcm%10;
            if(x) break;
            lcm/=10;
        }
        printf("%d\n",x);
    }
    return 0;
}
