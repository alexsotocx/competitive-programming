#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<list>
#include<sstream>
using namespace std;
typedef long long ll;
ll fastpow(ll x,ll n)
{
    if(n==0) return 1;
    if(n==1) return x;
    ll ret = fastpow(x,n/2);
    ret*=ret;
    if(n&1) ret*=x;
    return ret;
}
int main()
{
    string c,x;
    while(getline(cin,c) && getline(cin,x) )
    {
        vector<ll> coe;
        stringstream sc,sx;
        sc<<c;
        sx<<x;
        ll o,ans=0;
        while(sc>>o) coe.push_back(o);
        bool li=false,ot=false;
        while(sx>>o)
        {
            for(long i=coe.size()-1, j=0;i>=0 && j<coe.size();i--,j++)
                ans+=fastpow(o,i)*coe[j];
            if(!ot)
                printf("%lld",ans);
            else
                printf(" %lld",ans);
            ot=true;
            ans=0;
        }
        printf("\n");
    }
}
