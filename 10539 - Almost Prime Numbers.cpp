#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
bitset<1000011> s;
vector<ll> primes;
vector<ll> al;
void sieve()
{

    int k = 1000000+1;

    s.set();
    s[0]=s[1]=0;
    for(ll i=2; i<=k; i++)
    {
        if(s[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=k; j+=i)
                s[j]=0;
            ll aux = i*i;
            while(aux<=1000000000000ll)
            {
                al.push_back(aux);
                aux*=i;
            }

        }

    }
}
int divisor(ll n)
{
    ll m =sqrt(n);
    set<ll> c;
    for(ll i=2; i<=m; i++)
    {
        if(n%i==0)
        {
            c.insert(i);
            c.insert(n/i);
        }
    }
    return c.size();
}


int main()
{
    int n;
    freopen("in.txt","r",stdin);
    sieve();
    sort(al.begin(),al.end());
    scanf("%d",&n);
    while(n--)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        int c=upper_bound (al.begin(), al.end(), b)-lower_bound (al.begin(), al.end(), a);

        printf("%d\n",c);
    }
    return 0;
}
