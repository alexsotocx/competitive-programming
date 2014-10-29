#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
#define vll vector<vector<ll> >

int l,s;
vll multiply(const vll &m, const vll &n)
{
    vll v(s,vector<ll>(s,0));
    for(int i=0; i<s; i++)
        for(int j=0; j<s; j++)
            for(int k=0; k<s; k++)
                v[i][j]|=m[i][k]&n[k][j];
    return v;
}
void prints(const vll &a)
{
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            cout<<a[i][j]<<" ";
        }
    cout<<endl;
    }
}
vll fastpow(vll g,ll d)
{
    vll t(s,vector<ll>(s,0));
    for(int i=0; i<s; i++)
        t[i][i]=1;
    while(1)
    {
        if(d&1ll) t=multiply(t,g);
        if(!(d>>1)) break;
        g = multiply(g,g);
        d >>= 1;
    }
    return t;
}
int main()
{
    while(scanf("%d%d",&s,&l) && s+l)
    {
        vll g= vll(s,vector<ll>(s,0));
        int a,b,d;
        for(int i=0; i<l; i++)
        {
            scanf("%d%d",&a,&b);
            g[a-1][b-1] = g[b-1][a-1] =1;
        }
        scanf("%d%d%d",&a,&b,&d);
        vll ret = fastpow(g,d);
        if(ret[a-1][b-1]) printf("Yes, Teobaldo can travel.\n");
        else printf("No, Teobaldo can not travel.\n");
    }
}
