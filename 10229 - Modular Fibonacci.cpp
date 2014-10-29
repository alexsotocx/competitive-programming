#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>
using namespace std;
typedef  long long   ll;
#define forn(i,a,b) for(int i=a;i<b;i++)
ll po[2][2] = {{1,1},{1,0}};
int mod;
vector<vector<ll> > matprod(const vector<vector<ll> > &a, const vector<vector<ll> > &b)
{
    vector<vector<ll> > ret(2, vector<ll> (2, 0));
    forn(i, 0, 2) forn(j, 0, 2) forn(k, 0, 2) ret[i][j] = (ret[i][j] + a[i][k]*b[k][j])%(mod) ;
    return ret;
}
vector<vector<ll> > matexp(const vector<vector<ll> > &m, ll b)
{

    if(b == 0)
    {
        vector<vector<ll> > id(2, vector<ll>(2, 0));
        id[0][0] = id[1][1] =  1;
        return id;
    }
    if(b == 1) return m;
    vector<vector<ll> > aux;
    if(b%2==0)
    {
        aux= matexp(m, b/2);
        aux = matprod(aux, aux);
    }
    else
    {
        aux= matexp(m, (b-1)/2);
        aux = matprod(aux, aux);
        aux = matprod(aux,m);
    }

    return aux;
}
int fast(int n)
{
    if(!n)
        return 1;
    else return 2<<n-1;
}
int main()
{
    ll n;
    //freopen("in.txt","r",stdin);
    while(scanf("%lld %d", &n, &mod)==2)
    {

        //mod =fast(mod);
        vector<vector<ll> > f(2, vector<ll>(2, 0));
        forn(i, 0, 2) forn(j, 0, 2) f[i][j] = po[i][j];

        vector<vector<ll> > ret = matexp(f, n);
        printf("%lld\n", (ret[1][0]));

    }
    return 0;
}
