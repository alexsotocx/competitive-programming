#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cmath>
using namespace std;
typedef long long ll;
vector<ll>primes;
bitset<100001>s;
void sieve()
{
    s.set();
    ll k = 100000;
    s[0]=s[1]=0;
    for(ll i=2;i<=k;i++)
    {
        if(s[i])
        {
            primes.push_back(i);
            for(ll j=i*i;j<=k;j+=i) s[j]=0;
        }
    }
}
ll numDiv(ll N)
{
    ll ind=0,pf=2,ans=1;
    while(N!=1 && (pf*pf<=N))
    {
        ll powers=0;
        while(N%pf==0) {N/=pf;powers++;}
        ans*=(powers+1);
        pf=primes[++ind];
    }
    if(N!=1) ans*=2;
    return ans;
}
int main()
{
    int i;
    scanf("%d",&i);
    sieve();
    while(i--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        ll max=numDiv(a),num=a;
        for(ll k=a+1;k<=b;k++)
        {
            ll aux=numDiv(k);
            if(aux>max){max=aux;num=k;}
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,num,max);
    }
    return 0;
}
