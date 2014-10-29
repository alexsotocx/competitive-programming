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
int main()
{
    ll n;
    sieve();
    //cout<<"s"<<endl;
    while(scanf("%lld",&n)==1 && n)
    {



        if(n&1) {printf("Goldbach's conjecture is wrong.\n");continue;}
        for(vector<ll>::iterator it=primes.begin();it!=primes.end() && *it<n;it++)
        {
            ll l= *it;
            if(s[n-l])
            {
                printf("%d = %d + %d\n",n,l,n-l);
                break;
            }
        }

    }
}

