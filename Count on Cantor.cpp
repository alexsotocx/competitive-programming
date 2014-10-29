#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
#define N 65536
int bin(int low,int up, int tosearch)
{
    int n;
    while(up>low)
    {
        n = (up + low)/2;
        ll x = (n*(n+1))/2;
        if (x==tosearch) return n;
        if(x>=tosearch) up = n;
        else low = n+1;
    }
    return low;

}
int main()
{
    int n,a;
    while(scanf("%d",&n)==1 )
    {
        a=bin(1,N,n);
        a--;
        if(a%2 == 1)
            printf("TERM %d IS %d/%d\n",n,n - (a*(a+1))/2,a + 2 - n + (a*(a+1))/2);
        else
            printf("TERM %d IS %d/%d\n",n,a + 2 - n + (a*(a+1))/2,n - (a*(a+1))/2);
    }
    return 0;
}
