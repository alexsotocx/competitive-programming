#include<iostream>
#include<vector>
#include<bitset>
#include<cmath>
#include<cstdio>
using namespace std;
bitset<1000001>s;
typedef long long ll;
ll m;
vector<ll>primes;
void sieve()
{
    s.set();
    ll k = 1000000;
    s[0]=s[1]=0;
    for(ll i=2; i<=k; i++)
        if(s[i])
        {
            //cout<<"lol"<<endl;
            primes.push_back(i);
            for(ll j=i*i; j<=k; j+=i)s[j]=0;
        }
}
bool isprime(ll k)
{
    if(k<=1000000) return s[k];
    ll index=0, pf = primes[index];
    while(pf*pf<=k)
    {
        if(k%pf==0) return false;
        pf = primes[++index];
    }
    return true;
}
ll fastpower(ll a,ll p)
{
    if(!p) return 1;
    if(p==1) return a%m;
    ll ret = fastpower(a,p/2);
    ret = ((ret%m)*(ret%m))%m;
    if(p&1) ret = ((ret%m)*(a%m))%m;
    return ret%m;
}
int main()
{
    ll a,p;
    sieve();
    while(scanf("%lld%lld",&p,&a)==2 && a && p)
    {
        m=p;
        //cout<<fastpower(a,p);
        if(isprime(a) && isprime(p))
        {
            printf("no\n");
            continue;
        }
        if(fastpower(a,p)==a)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
