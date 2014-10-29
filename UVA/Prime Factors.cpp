#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
vector<ll> factor(ll N)
{
    N = (N>0)? N:-1*N;
    vector<ll> primefactors;
    for(ll p=2;p*p<=N;p++)
    {
        while(N%p==0)
        {
            primefactors.push_back(p);
            N/=p;
        }
    }
    if(N!=1) primefactors.push_back(N);
    return primefactors;
}
int main()
{
    ll k;
    while(scanf("%lld",&k)==1 && k)
    {
        vector<ll> p = factor(k);
        printf("%lld = ",k);
        if(k<0)
            printf("-1 x %lld",p[0]);
        else
            printf("%lld",p[0]);
        int m= p.size();
        for(int i=1;i<m;printf(" x %lld",p[i++]));
        printf("\n");

    }
    return 0;
}
