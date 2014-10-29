#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)

string ternary(int n)
{
    string k = "";
    while(n>0)
    {
        k+='0' + n%3;
        n/=3;
    }
    return string(k.rbegin(),k.rend());
}
int main()
{
    int n;
    while(scanf("%d",&n) && n>=0)
        printf("%s\n",(n)?ternary(n).c_str():"0");
    return 0;
}
