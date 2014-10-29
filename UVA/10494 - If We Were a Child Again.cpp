#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b;
    char c;
    while(scanf("%lld %c %lld",&a,&c,&b)==3)
        printf("%lld\n",(c=='%')?a%b:a/b);
    return 0;
}
