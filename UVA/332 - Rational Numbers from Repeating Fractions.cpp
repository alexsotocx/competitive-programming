#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
#include<sstream>
using namespace std;
typedef long long ll;
ll GCD (ll a,ll b)
{
    return ((!b)? a:GCD(b,a%b));
}
ll LCM(ll a,ll b)
{
    return (a*b)/GCD(a,b);
}
int main()
{
    int j,k;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char c[110];
    ll *powers = new ll[10];
    powers[0]=1;
    for(int i=1; i<10; i++) powers[i]=powers[i-1]*10;
    int count=1;
    while(scanf("%d %s",&j,&c)==2 && j!=-1)
    {
        string ret(c);
        ret = ret.substr(2,ret.size());
        k = ret.size()-j;
        stringstream ss,sss;
        ll b = 0;
        if(j==0)
        {
            ss<<ret;
            ss>>b;
            ll gc = GCD(b,powers[k]);
            printf("Case %d: %lld/%lld\n",count++,b/gc,powers[k]/gc);
            continue;
        }

        ll a = 0;
        if(k>0)
        {
            ss<<ret.substr(0,k);
            ss>>a;
        }

        sss<<ret;
        sss>>b;
        ll answ1=b-a, answ2=powers[k+j]-powers[k];
        ll gc = GCD(answ1,answ2 );
        printf("Case %d: %lld/%lld\n",count++,answ1/gc,answ2/gc);
    }
    return 0;
}
