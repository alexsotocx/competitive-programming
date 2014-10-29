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
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    multimap<int,string>::iterator it;
    forn(i,0,n)
    {
        multimap<int,string>d;
        int lmax=-50;
        forn(j,0,10)
        {
            string a;
            int k;
            cin>>a;
            scanf("%d",&k);
            d.insert(pair<int,string>(k,a));
            lmax=max(lmax,k);
        }
        pair<multimap<int,string>::iterator,multimap<int,string>::iterator> ret;
        ret = d.equal_range(lmax);
        printf("Case #%d:\n",i+1);
        for (it=ret.first; it!=ret.second; ++it)
            printf("%s\n",it->second.c_str());
    }
    return 0;
}
