#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
typedef long long ll;
ll a,b,c,l;
ll d;
ll evaluar(ll i)
{
    return ((a*i*i) + (b*i)+c);
}
int main()
{

    int cont =0;
    while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&l)==5)
    {
        cont=0;
        if(!a && !b && !c && !d && !l)
            break;
        for(ll i=0; i<=l; i++)
        {
            ll x = evaluar(i);
            if(x%d==0)
                cont++;
        }
        printf("%d\n",cont);
    }
    return 0;
}
