#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>
using namespace std;
typedef  long long   ll;
#define forn(i,a,b) for(int i=a;i<b;i++)
ll d,n,m;
vector<vector<ll> > genmatriz(ll d,vector<ll> a)
{
    vector<vector<ll> > x(d,vector<ll>(d,0));
    forn(i,0,d-1)
    x[i][i+1]=1;
    forn(i,0,d)
    x[d-1][i]=a[d-1-i];
    return x;
}
vector<vector<ll> > matprod(const vector<vector<ll> > &a, const vector<vector<ll> > &b)
{
    vector<vector<ll> > ret(d, vector<ll> (d, 0));
    forn(i, 0, d) forn(j, 0, d) forn(k, 0, d) ret[i][j] = (ret[i][j] + a[i][k]*b[k][j] ) % m;
    return ret;
}

vector<vector<ll> > matexp(const vector<vector<ll> > &x, ll b)
{

    if(b == 0)
    {
        vector<vector<ll> > id(d, vector<ll>(d, 0));
        forn(i,0,d) id[i][i]=1;
        return id;
    }
    if(b == 1) return x;

    vector<vector<ll> > aux = matexp(x, b/2);
    aux = matprod(aux, aux);
    if(b&1LL) aux = matprod(aux, x);

    return aux;
}
void final(const vector<vector<ll> > &x, vector<ll> b)
{
    ll y=0;
    forn(i,0,d)
        y=(y+ (x[d-1][i]*b[i])%m)%m;
    printf("%lld\n",y);
}
int main()
{
    while(scanf("%lld %lld %lld",&d,&n,&m)==3)
    {
        if(!d && !n && !m) break;
        vector<ll> a(d,0);
        vector<ll> fn(d,0);
        forn(i,0,d) scanf("%lld",&a[i]);
        forn(i,0,d) scanf("%lld",&fn[i]);
        vector<vector<ll> >rec = genmatriz(d,a);
        vector<vector<ll> >ret = matexp(rec,n-d);
        final(ret,fn);
        string pal;
        getline(cin,pal);
    }
    return 0;
}
