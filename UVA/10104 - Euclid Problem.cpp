#include<cstdio>
typedef long long ll;
ll x,y,d;
ll GCD(ll a,ll b)
{
    return (!b)?a:GCD(b,a%b);
}
void ExtendedEuclid(int a, int b)
{
    if(!b)
    {
        x=1;y=0;d=a;
        return;
    }
    ExtendedEuclid(b,a%b);
    ll x1 = y;
    
    ll y1 = x-(a/b)*y;
    x = x1;
    y = y1;
}
int main()
{
    ll a,b;
    while(scanf("%lld%lld",&a,&b)==2)
    {
        //d = GCD(a,b);
        ExtendedEuclid(a,b);
        printf("%lld %lld %lld\n",x,y,d);

    }
    return 0;
}
