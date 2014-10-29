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
    long n;
    while(scanf("%ld",&n)==1)
    {
        long a = (n*n +2*n -1)/2;
        printf("%ld\n",(3*a)-6);
    }
    return 0;
}
