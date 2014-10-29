#include<cmath>
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
int main()
{
    ll *fac = new ll[21];
    fac[0]=fac[1]=1;
    for(int i=2;i<21;i++)
        fac[i]=i*fac[i-1];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        string b;
        cin>>b;
        map<char,int>m;
        for(int j=0;j<b.size();j++)
        {
            char p = b[j];
            if(m.find(p)==m.end())
            {
                m[p]=0;
            }
            m[p]++;
        }
        ll f = fac[b.size()];
        for(map<char,int>::iterator a = m.begin();a!=m.end();a++)
            f/=fac[a->second];
        printf("Data set %d: %lld\n",i,f);
    }
    return 0;
}
