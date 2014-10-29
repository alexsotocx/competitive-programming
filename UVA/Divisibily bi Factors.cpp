
#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
ll primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 ,97};
bitset<102>s;

map<ll, map<ll,int> > fact;
void factorialp(ll k)
{
    map<ll, int>ret = fact[k-1];
    ll aux = k;
    ll ind=0,pf=2;
    while(k!=1 && (pf*pf<=k))
    {
        if(ret.find(pf)==ret.end()) ret[pf]=0;
        while(k%pf==0)
        {

            k/=pf;
            ret[pf]++;
        }
        pf=primes[++ind];
    }
    if(k!=1)
    {
        if(ret.find(k)!=ret.end())ret[k]++;
        else ret[k]=1;
    }
    fact[aux] = ret;

}
ll sol(ll N,ll D)
{
    ll ret = 1;
    ll ind =0, pf=2,aux=D;
    map<ll,int>k;
    for(ll i=0; i<26 && primes[i]*primes[i]<=D; i++)
    {
        ll pf = primes[i];
        k[pf] = 0;
        while(D%pf==0)
        {
            if(fact[N].find(pf)==fact[N].end()) return 0;
            D/=pf;
            k[pf]++;
        }

    }
    if(D!=1 && D<100){ k[D]=1;if(fact[N].find(D)==fact[N].end()) return 0;}
    if(D>100) return 0;
    ll s;
    for(map<ll,int>::iterator it=fact[N].begin(); it!=fact[N].end(); it++)
    {
        s = it->first;
        if(k[s]>it->second) return 0;
        ll m=fact[N][s];
        ll n = k[s];
        ret*=(m-n+1);
    }

    return ret;

}

int main()
{

    fact[2][2]=1;
    for(ll i=3; i<=100; i++) factorialp(i);
    ll N,D;
    while(scanf("%lld%lld",&N,&D)!=EOF)
    {

        if(!D && !N)break;
        if(N==0 || N==1 )
        {
            if((D==1 || D==-1))
                printf("1\n");
            else
                printf("0\n");
            continue;
        }
        if(D==0)
        {
            printf("0\n");
            continue;
        }
        printf("%lld\n",sol(N,(D>0)?D:-1*D));
    }


    return 0;
}
