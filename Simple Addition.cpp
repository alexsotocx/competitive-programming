#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll sum(ll k)
{
    ll suma=0;
    while(k>0)
    {
        ll b = k%10;
        ll a = k/10;
        suma += (a*45)+(b*(b+1))/2;
        k/=10;
    }
    return suma;
}
int main()
{
    ll p,q;
    while(scanf("%lld%lld",&p,&q)!=EOF && p>=0 && q>=0)
        printf("%lld\n",sum(q)-sum(p-1));
    return 0;
}
