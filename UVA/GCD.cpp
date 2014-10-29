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
int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    int n;

    while(scanf("%d",&n)==1 && n)
    {
        cout<<"Algorithm: "<<endl;
        int G=0;
        for(int i=1; i<n; i++)
            for(int j=i+1; j<=n; j++)
            {
                cout<<i<<" "<<j<<" "<<gcd(i,j)<<endl;
                G+=gcd(i,j);
            }
        cout<<G<<endl;
        cout<<"Solution: \n";
        ll ans=0;
        for(int i=1; i<n; i++)
        {
            ll xd = ((n-i)/i)*i + (n - ((n-i)/i) -1);
            ans+=xd;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
