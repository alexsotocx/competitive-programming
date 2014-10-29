#include<stdio.h>
typedef long long ll;
ll bottles(ll a, ll c)
{
    if(c>a)
        return a;
    return a + bottles((a)/c,c);

}
int main()
{
    //freopen("in.in","r",stdin);
        ll e,f,c;
        while(scanf("%lld%lld",&e,&c)==2)
            printf("%lld\n",bottles(e,c));
        return 0;
}
