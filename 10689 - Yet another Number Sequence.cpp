#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;
#define vii vector<vector<ll> >
#define forn(i,a,b) for(int i=a;i<b;i++)

int mods[]= {10,100,1000,10000,10000};
int mo;
vii idd(2,vector<ll>(2,0));
vii ret1(2,vector<ll>(2,1));


vii matmultplication(vii m,vii n)
{
    vii v(2, vector<ll>(2,0));
    forn(i,0,2)
    forn(j,0,2)
    forn(k,0,2)
    v[i][j]=(v[i][j]+((m[i][k])*(n[k][j])%mo))%mo;
    return v;

}
vii f(const vii &m, ll n)
{
    if(n==0)
        return idd;
    if(n==1)
        return m;
    vii aux = f(m, n/2);
    aux = matmultplication(aux, aux);
    if(n&1LL) aux = matmultplication(aux, m);
    return aux;

}
int main()
{
    idd[0][0]=1;
    idd[1][1]=1;
    ret1[0][0]=0;
    ll a,b,n;
    int m,c;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%lld%lld%lld%d",&a,&b,&n,&m);
        mo = mods[m-1];
        a%=mo;
        b%=mo;
        if(n==0) printf("%lld\n",a%mo);
        else if(n==1) printf("%lld\n",b%mo);
        else
        {
            vii ret = f(ret1,n-2);
            ll ans = (((ret[0][1]*b)%mo + (ret[0][0]*a)%mo)%mo + ((ret[1][0]*a)%mo + (ret[1][1]*b)%mo )%mo)%mo;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
