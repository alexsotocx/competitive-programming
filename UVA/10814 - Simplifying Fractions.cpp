#include <iostream>
#include <math.h>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <deque>

using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
#define PB(x) push_back(x)
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        ll a,b;
        scanf("%lld / %lld",&a,&b);
        ll g = gcd(a,b);
        printf("%lld / %lld\n",a/g,b/g);
    }
    return 0;
}
