#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<bitset>
#include<sstream>
using namespace std;
bitset<1000002>s;
typedef long long ll;
void sieve ()
{
    ll k = 1000000;
    ll m = sqrt(k);
    s.set();
    s[0]=s[1]=0;
    for(ll i = 2; i<=m; i++)
    {
        //cout<<"lol"<<endl;
        if(s[i])
        {
            for(ll j=i*i;j<=k;j+=i)
                s[j]=0;
        }
    }
}
bool isEmirp(ll k)
{
    stringstream ss,scp;
    string kto,otk;
    ss<<k;
    ss>>kto;
    otk = string(kto.rbegin(),kto.rend());
    if(otk==kto) return false;
    scp<<otk;
    ll ans;
    scp>>ans;
    return s[ans];
}
int main()
{
    ll k;
    sieve();
    while(scanf("%lld",&k)==1)
    {
        if(!s[k])
            printf("%lld is not prime.\n",k);
        else if(isEmirp(k))
            printf("%lld is emirp.\n",k);
        else
            printf("%lld is prime.\n",k);
    }
    return 0;
}
