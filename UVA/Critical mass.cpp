#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i, a, b) for(int i=(a);i<int(b);i++)
#define PB push_back
#define MP(X,Y) make_pair(X,Y)
#define SZ(X) ((int)(X.size()))
#define ALL(x)   (x).begin(),(x).end()
#define foreach(it, c)  for(typeof((c).begin()) it = (c).begin();it!=(c).end();++it)
#define F first
#define S second
#define CLEAR(A, V) memset(A, V, sizeof(A))

typedef  long long   ll;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<II> VII;

template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template<class T> inline T gcd(T a, T b){ return b?gcd(b, a%b):a;}
const double EPS = 1e-9;
const double PI = acos(-1.0);

#define MOD 1000000009LL

ll M[3][3] = {{0,1,0},{0,0,1},{1,1,1}};

vector<vector<ll> > matprod(const vector<vector<ll> > &a, const vector<vector<ll> > &b) {
	vector<vector<ll> > ret(3, vector<ll> (3, 0));
	forn(i, 0, 3) forn(j, 0, 3) forn(k, 0, 3) ret[i][j] = (ret[i][j] + a[i][k]*b[k][j] );
	return ret;
}

vector<vector<ll> > matexp(const vector<vector<ll> > &m, ll b) {

	if(b == 0) {
		vector<vector<ll> > id(3, vector<ll>(3, 0));
		id[0][0] = id[1][1] = id[2][2] = 1;
		return id;
	}
	if(b == 1) return m;

	vector<vector<ll> > aux = matexp(m, b/2);
	aux = matprod(aux, aux);
	if(b&1LL) aux = matprod(aux, m);

	return aux;
}

int main() {

	ll n;
	while(scanf("%lld", &n) != EOF && n) {

        if(n<=3)
        {
            switch(n)
            {
                case 1 : printf("1\n");break;
                case 2 : printf("1\n");break;
                case 3 : printf("2\n");break;
            }
            continue;
        }
		vector<vector<ll> > m(3, vector<ll>(3, 0));
		forn(i, 0, 3) forn(j, 0, 3) m[i][j] = M[i][j];

		vector<vector<ll> > ret = matexp(m, n-3);
		printf("%lld\n", (ret[2][2]));

	}
	return 0;
}
