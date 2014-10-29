#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<sstream>
#include<cstring>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

#define all(A) A.begin(),A.end()
#define s(A) sort(all(A))
#define ub(A,k) upper_bound(all(A),k)
#define lb(A,k) lower_bound(all(A),k)
#define binary(A,k) binary_search(all(A),k)
#define PB push_back
#define sz(X) (int)X.size()
#define forn(i,a,b) for(int i=a;i<b;i++)
ll m;
ll power(ll b, ll p)
{
    if(!p)
        return 1;
    if(p==1)
        return b;
    ll aux = power(b,p/2);
    aux = ((aux%m) * (aux%m))%m;
    if(p&1) aux = ((aux%m)*(b%m))%m;
    return aux;
}
int main()
{
    ll b,p;
    while(scanf("%lld %lld %lld",&b,&p,&m)==3)
        printf("%lld\n",power(b,p));
    return 0;
}
