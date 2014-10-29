#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
map<long, long> x;
long s;
long solve(long n,int i)
{

    if(n==s) return i;

    if (n==0)
        return solve(1,1);
    if(n<s)
    {
        long b=0;
        if (n*2<=s)
            b = solve(n*2,i+1);
        long a = solve(n+1,i+1);
        x[n] = (a>b && b!=0)?b:a;
        return x[n];
    }
    long a = solve(n-1,i+1);
    x[n]= (a<x[n])?a:x[n];
    return x[n];
}
int main()
{
    while(scanf("%ld",&s)==1)
        printf("%ld\n",solve(0,0));
    return 0;
}
