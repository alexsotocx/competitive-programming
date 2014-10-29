#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ll x[30];
    for(int i=0;i<30;i++)
        x[i]= (2<<i);
    int n;
    while(scanf("%d",&n) && n)
    {
        if(n==1) {printf("1\n",n);continue;}
        ll lo = *lower_bound(x,x+30,n);
        if(lo == n) {printf("%d\n",n);continue;}
        ll loa = lo/2;
        printf("%d\n",(n-loa)*2);

    }
    return 0;
}
