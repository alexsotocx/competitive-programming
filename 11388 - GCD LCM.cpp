#include <iostream>
#include <math.h>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <deque>

using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
#define PB(x) push_back(x)
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
    int g,l;
    int n;
    scanf("%d",&n);
    forn(i,0,n+1)
    {
        scanf("%d%d",&g,&l);
        for(int j=1;j<=sqrt(l*g);j++)
        {
            if((l*g)%j==0)
            {
                int b=(l*g)/j;
                printf("%d %d\n",j,b);
                break;
            }
        }
    }
    return 0;
}
