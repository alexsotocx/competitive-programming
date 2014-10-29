#include<vector>
#include<algorithm>
#include<set>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<bitset>

using namespace std;
typedef long long ll;
vector<ll> primes;
bitset<1000000+1>s;
void sieve()
{
    ll n=1000000+1;
    s.set();
    s[0]=s[1]=false;
    for(ll i=2; i<=1000000+1; i++)
    {
        if(s[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=1000000+1; j+=i)
                s[j]=0;
        }
    }
}
bool isprime(ll k)
{
    if(k<=1000000)
        return s[k];
    else
    {
        ll index=0,pf=primes[index];
        while(pf*pf<=k)
        {
            if(k%pf==0)
                return false;
            pf=primes[++index];
        }
    }
    return true;
}
int main()
{
    ll n;
    sieve();
    //cout<<"s"<<endl;
    while(scanf("%lld",&n)==1 && n)
    {
        //if(n&1) {printf("%lld is not the sum of two primes!\n",n);continue;}
       // ll b = sqrt(n);
        vector<ll>::iterator it;
        bool ok = false;
        for(it=primes.begin();it!=primes.end() && *it<=n;it++)
        {
            ll l= *it;
            if((n-l)<=1000000 && s[n-l] && n-l != l)
            {
                printf("%lld is the sum of %lld and %lld.\n",n,l,n-l);
                ok = true;
                break;
            }else if(isprime(n-l)&& n-l != l)
            {
                printf("%lld is the sum of %lld and %lld.\n",n,l,n-l);
                ok = true;
                break;
            }
        }
        if(!ok)
        {printf("%lld is not the sum of two primes!\n",n);continue;}

    }
    return 0;
}
