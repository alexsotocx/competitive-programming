#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll> primeFactors(ll N)
{
    vector<ll>k;
    N= (N<0)?-1*N:N;
    for (ll p = 2; p * p <= N; ++p)
    {
        while (N % p == 0)
        {
            k.push_back(p);
            N/= p;
        }
    }
    if (N > 1)
        k.push_back(N);
    //sort(k.begin(),k.end());
    sort(k.begin(),k.end());
    return k;
}

int main()
{
    ll n,k;
    while(scanf("%lld",&n)==1 && n)
    {
        vector<ll> v = primeFactors(n);
        if(v.size()<=1 )
            printf("-1\n");
        else if(v[0]==v[v.size()-1] && n>0)
            printf("-1\n");
        else
            printf("%lld\n",v[v.size()-1]);
    }

    return 0;
}

