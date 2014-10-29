#include <cmath>
#include <cstdio>
using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)

int main()
{
    double n;
    int cases =1;
    while(scanf("%lf",&n)==1 && n>0)
        printf("Case %d: %d\n",cases++,(int) ceil(log(n)/log(2.0)));
    return 0;
}
