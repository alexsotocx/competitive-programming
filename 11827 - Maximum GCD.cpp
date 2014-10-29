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
    int n;
    char in[10000];
    gets(in);
    sscanf(in,"%d",&n);

    forn(i,0,n)
    {
        char in[10000];
        gets(in);
        stringstream iss;
        iss<<in;
        vector<int> k;
        int b;
        while(iss>>b)
            k.push_back(b);
        int maxgcd=0;
        forn(j,0,(int)k.size()-1)
            forn(l,j+1,(int)k.size())
                maxgcd = max(maxgcd,gcd(k[j],k[l]));
        printf("%d\n",maxgcd);
    }
    return 0;
}
