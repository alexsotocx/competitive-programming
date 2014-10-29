#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<sstream>
#include<cstring>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

#define all(A) A.begin(),A.end()
#define s(A) sort(all(A))
#define ub(A,k) upper_bound(all(A),k)
#define lb(A,k) lower_bound(all(A),k)
#define binary(A,k) binary_search(all(A),k)
#define PB push_back
#define sz(X) (int)X.size()
#define forn(i,a,b) for(int i=a;i<b;i++)
bitset<1000002> s;
vll primes;
void sieve()
{
    s.set();
    int m = 1000000;
    s[0]=s[1]=0;
    for(ll i=2;i<=m;i++)
    {
        if(s[i])
        {
            primes.PB(i);
            for(ll j=i*i;j<=m;j+=i)
                s[j]=0;
        }
    }
}
int factors(ll n)
{
    if(s[n]) return 1;
    set<ll>ret;
    ll k = 0;
    ll pf = primes[k];
    while(n!=1 && (pf*pf)<=n)
    {


        while(n%pf==0)
        {
            ret.insert(pf);
            n/=pf;
        }
        pf = primes[++k];
    }
    if(n>1)
        ret.insert(n);
    return sz(ret);
}
int main()
{
    sieve();
    ll n;

    while(scanf("%lld",&n) ==1 && n)
        printf("%lld : %d\n",n,factors(n));
    return 0;
}
