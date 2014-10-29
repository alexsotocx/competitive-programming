#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
vector<ll> factor(ll N)
{
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
    while(scanf("%lld",&k)==1 && k>0)
    {
        vector<ll> p = factor(k);
        int m= p.size();
        for(int i=0;i<m;printf("    %lld\n",p[i++]));
        printf("\n");
    }
    return 0;
}
