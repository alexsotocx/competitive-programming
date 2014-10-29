#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<bitset>
#include<sstream>

using namespace std;
bitset<20000002>s;
typedef long long ll;
vector<ll>primes;
vector<ll> ret;

void sieve ()
{
    ll k = 20000000;
    //ll m = sqrt(k);
    s.set();
    s[0]=s[1]=0;
    for(ll i = 2; i<=k; i++)
    {
        if(s[i])
        {
            primes.push_back(i);
            int si=primes.size();
            if(si>=3)
            {
                if(primes[si-1]-primes[si-2]==2)
                {
                    //cout<<""
                    //pair<ll,ll>p (primes[si-2],primes[si-1]);
                    ret.push_back(si-2);
                }
                if(ret.size()==100000) break;
            }
            for(ll j=i*i;j<=k;j+=i)
                s[j]=0;
        }
    }
}
int main()
{
    ll n;
    sieve();
    while(scanf("%d",&n)==1)
        printf("(%lld, %lld)\n",primes[ret[n-1]],primes[ret[n-1]]+2);
    return 0;
}
