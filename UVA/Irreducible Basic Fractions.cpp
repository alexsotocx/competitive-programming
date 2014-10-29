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
ll EulerPhi(ll n)
{
    ll ind=0,pf=primes[ind],ans=n,k=sqrt(n);

    while(n!=1 && pf<=k)
    {
        if(n%pf==0) ans-=ans/pf;
        while(n%pf==0)n/=pf;
        pf=primes[++ind];
    }
    if(n!=1) ans -= ans/n;
    return ans;
}
int main()
{
    sieve();
    ll k;
    while(scanf("%lld",&k)==1 && k) printf("%lld\n",(k==1)? 0: EulerPhi(k));
    return 0;
}
