#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define FOR(i,n)    for(int i=0;i<(n);++i)
#define FORE(i,e,n) for(int i=(e);i<(n);++i)
#define all(A) A.begin(),A.end()
#define sz size()
#define pb push_back
#define N 65536

typedef unsigned long long int ulint;

vector<bool> primes(N + 1, true);
vector<ulint> super;

void generar(){
    int i, inc, j, root = (int)sqrt(N);
    primes[0] = false;
    for(i = 2;i <= root;++i)
        if(primes[i]){
            inc = (i > 2)? 2 * i : i;
            num = i;
	        power = 1;
	        top = ceil(lb / log(i));
	        FORE(j, 4, top){
	            if(!primes[j]){
	                while(power < j){
	                    num *= i;
	                    ++power;
	                }
    	            super.pb(num);
	            }
	        }
            for(j = i * i;j <= N; j += inc)
                primes[j] = false;
        }
}

int main() {
	unsigned int i, j, top, power;
	ulint num;
	double lb = log(18446744073709551616.);
	super.reserve(100000);
	super.pb(1);
	generar();


	sort(all(super));
	top = super.sz;
	FOR(i, top) printf("%llu\n", super[i]);
	return 0;
}
/*#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
using namespace std;
bitset<1000001>s;

typedef unsigned long long ll;
vector<ll>primes;
set<ll>pot;
ll lim = 18446744073709551615ll;
ll fastpow(ll k , int b)
{
    if(!b) return 1;
    if(b==1) return k;
    ll ret = fastpow(k,b/2);
    ret*=ret;
    if(b&1) ret*=k;
    return ret;
}
void sieve()
{
    s.set();
    s[0] = s[1]=0;
    pot.insert(1);
    for(ll i=2; i<65536; i++)
    {
        if(s[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=65536; j+=i)
                s[j]=0;
        }
    }
    for(int i=0;i<primes.size();i++)
    {
        int basemax = ceil((log(lim))/log(primes[i]));

        for(int j=4;j<=basemax;j++)
        {
            if(s[j]) continue;
            pot.insert(fastpow(primes[i],j));
        }


    }
}
int main()
{
    sieve();
    set<ll>::iterator it;
    for(it=pot.begin(); it!=pot.end(); it++)
        cout<<*it<<endl;
    return 0;
}*/
