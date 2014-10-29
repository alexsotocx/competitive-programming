#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ll x;
    while(scanf("%lld",&x)!=EOF && x)
    {
        ll p = sqrt(x);
        printf("%s\n",(p*p==x)?"yes":"no");
    }
    return 0;
}
