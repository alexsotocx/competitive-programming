#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long unsigned ll;
int main()
{
    ll n;
    int c;
    scanf("%d\n",&c);
    char x[22];
    ll fac[21];
    fac[0] = 1;
    for(ll i=i;i<21;i++)
        fac[i] = i*fac[i-1];
    while(c--)
    {
         gets(x);
         cin>>n;
         getchar();
        int s = strlen(x);
        sort(x,x+s);
        ll lo = n%fac[s];
        for(ll i = 0;i<lo;i++)
            next_permutation(x,x+s);
        printf("%s\n",x);
    }
    return 0;

}
