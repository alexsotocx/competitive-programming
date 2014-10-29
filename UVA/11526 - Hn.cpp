#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    vector<ll>x=vector<ll>(1,1ll);
    for(ll i = 1;i<23;i++)
        x.push_back((ll)(0.5+x[i-1]+exp(i*1.0)));
    for(ll i = 0;i<23;i++) cout<<x[i]<<endl;
    /*int n;
    scanf("%d",&n);
    ll s;
    while(n-- && scanf("%lld",&s))
        printf("%lld\n",(lower_bound(x.begin(),x.end(),s)-x.begin()+1)*s);*/
    return 0;
}
