#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
bitset<1000001> s;
vector<ll> primes;
vector<ll> al;
#define all(X) X.begin(),X.end()
void sieve()
{

    int k = 1000001;
    s.set();
    s[0]=s[1]=0;
    for(ll i=2; i<=k; i++)
    {
        //cout<<"lol"<<endl;
        if(s[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=k;j+=i)
                s[j]=0;
        }
    }
}
bool isprime(ll n)
{

    if(n<1000001)
        return s[n];
    else
    {
        ll index = 0;
        ll pf = primes[index];
        ll m = sqrt(n);
        while(pf<=m)
        {
            if(n%pf==0)
                return false;
            pf = primes[++index];
        }
        return true;
    }
}
ll gcd(ll a,ll b) {
    return ((!b)?a:gcd(b,a%b));
}
int main()
{
    ll n;
    sieve();
    while(scanf("%lld",&n)!=EOF && n)
    {
        ll k=1;
        if(n%2==1)
        {
            bool pr = isprime(n);
            for(ll i=3;i<n;i+=2)
            {
                if(pr && isprime(i))
                    k++;
                else
                {
                    if(gcd(n,i)==1)
                        k++;
                }
            }
        }
        else{
            bool pr = isprime(n);
            for(ll i=2;i<n;i++)
            {
                if(pr && isprime(i))
                    k++;
                else
                {
                    if(gcd(n,i)==1)
                        k++;
                }
            }
        }
        printf("%lld\n",k);

    }
    return 0;
}
