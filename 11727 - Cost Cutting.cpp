#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
int main()
{
    int *k = new int [3];
    int n;
    scanf("%d",&n);
    forn(i,0,n)
    {
        scanf("%d %d %d",&k[0],&k[1],&k[2]);
        sort(k,k+3);
        printf("Case %d: %d\n",i+1,k[1]);
    }
    return 0;
}
