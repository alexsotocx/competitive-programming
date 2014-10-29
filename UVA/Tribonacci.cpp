#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
typedef vector<vector<ll> > vl;
ll in[3][3] = {{0,1,0},{0,0,1},{1,1,1}};
ll vin[3] = {0,1,2};
ll mod = 1000000009LL;
vector<vector<ll> > matmultplication(vector<vector<ll> > m,vector<vector<ll> > n)
{
    vector< vector<ll> > v(3, vector<ll>(3,0));
    forn(i,0,3)
    forn(j,0,3)
    forn(k,0,3)
    v[i][j]=(v[i][j]+(m[i][k])*(n[k][j]))%mod;
    return v;

}
vector<vector<ll> > matexp(const vector<vector<ll> > &m, ll b) {

	if(b == 0) {
		vector<vector<ll> > id(3, vector<ll>(3, 0));
		id[0][0] = id[1][1] = id[2][2] = 1;
		return id;
	}
	if(b == 1) return m;

	vector<vector<ll> > aux = matexp(m, b/2);
	aux = matmultplication(aux, aux);
	if(b&1LL) aux = matmultplication(aux, m);

	return aux;
}

int main()
{
    vector< vector<ll> > v(3, vector<ll>(3,0));
    forn(i,0,3) forn(j,0,3)
            v[i][j]=in[i][j];
    ll n;
    while(cin>>n && n)
    {


        if(n<=2)
            cout<<n-1<<endl;
        else
        {
            vector<vector<ll> >answ;
            answ =matexp(v,n-3);
            cout<<(answ[2][1] + (2ll*answ[2][2])%mod)%mod<<endl;
        }
      }
    return 0;
}
