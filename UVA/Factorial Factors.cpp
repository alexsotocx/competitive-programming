#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
bitset<5000002> s;
vector<ll> deprimes(5000001,0);
vector<ll> al(5000001,0);

#define all(X) X.begin(),X.end()
void sieve()
{
    ll k = 5000001;
    ll m = sqrt(k);
    s.set();
    s[0]=s[1]=0;
    for(ll i=2; i<k; i++)
    {
        if(s[i])
        {
            al[i]=i;
            deprimes[i] = deprimes[i-1]+1;
            for(ll j=2*i; j<=k;j+=i)
            {
                s[j]=0;
                al[j]+=i;

            }
        }
        else
        {
            if(s[al[i]])
                deprimes[i]=deprimes[i-1]+1;
            else
                deprimes[i]=deprimes[i-1];
        }

    }
}
int main()
{
    sieve();
    ll a,b;
    while(scanf("%lld%lld",&a,&b)==2)
    {
        ll answer = deprimes[b]-deprimes[a];
        if(deprimes[a] > deprimes[a-1]) answer++;
        printf("%lld\n",answer);
    }
    return 0;
}
