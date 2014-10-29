#include<iostream>
#include<cstdio>
#include<bitset>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
bitset<2500>x;
void sieve()
{
    int n = 2500;
    x.set();
    x[0]=x[1]=0;
    for(int i=2;i*i<=n;i++)
        if(x[i])
            for(int j=2*i; j<=n;j+=i)
                x[j]=0;
}
int main()
{
    sieve();
    int n;
    int cases=1;
    string s;
    scanf("%d",&n);
    while(n-- && cin>>s)
    {
        map<char,int>m;
        for(int i=0;i<s.length();m[s[i++]]++);
        map<char,int>::iterator it;
        string c;
        for(it=m.begin();it!=m.end();it++)
            if(x[it->second])
                c+=it->first;
        if(c.length())
            printf("Case %d: %s\n",cases++,c.c_str());
        else
            printf("Case %d: empty\n",cases++);
    }
    return 0;
}
