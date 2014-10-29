#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define forn(i, a, b) for(int i=(a);i<int(b);i++)
using namespace std;
vector<vector<ll> > matprod(const vector<vector<ll> > &a, const vector<vector<ll> > &b)
{
    vector<vector<ll> > ret(2, vector<ll> (2, 0));
    forn(i, 0, 2) forn(j, 0, 2) forn(k, 0, 2) ret[i][j] = (ret[i][j] + a[i][k]*b[k][j] );
    return ret;
}
vector<vector<ll> > matexp(vector<vector<ll> >&x, int n)
{
    if(!n)
    {
        vector<vector<ll> > id(2,vector<ll>(2,0));
        id[0][0] = id[1][1] = 1;
        return id;
    }
    if(n==1)
        return x;
    else
    {
        vector<vector<ll> >aux(2,vector<ll>(2,0));
        if(n%2==0)
        {
            aux = matexp(x,n/2);
            return matprod(aux,aux);
        }
        else
        {
            aux = matexp(x,(n-1)/2);
            return matprod(matprod(aux,aux),x);
        }
    }


}


int main()
{
    //freopen("in.in","r",stdin);
    long m[2][2] = {{1,1},{1,0}};
    vector<vector<ll> > M(2, vector<ll>(2, 0));
    forn(i,0,2) forn(j,0,2) M[i][j] = m [i][j];
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        if(n<4)
            printf("%d\n",n);
        else {vector<vector<ll> > k = matexp(M,n+1);
        printf("%lld\n",k[0][1]);
        }
    }
    return 0;
}
