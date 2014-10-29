#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
int n,m;
vector< vector<int> >c;
bool bfs(int x)
{
    queue<int>qx;qx.push(x);
    map<int,int>dist; dist[x]=0;
    while(!qx.empty())
    {
        int u = qx.front();qx.pop();
        for(int i=0;i<c[u].size();i++)
            if(!dist[c[u][i]])
            {
                dist[c[u][i]]=1-dist[u];
                qx.push(c[u][i]);
            }
            else if(dist[c[u][i]]==dist[u])
                return false;
    }
    return true;
}
int main()
{
    while(scanf("%d",&n)==1 && n)
    {
        c=vector< vector<int> >(n,vector<int>());
        scanf("%d",&m);
        int a,b;
        while(m-- && scanf("%d%d",&a,&b))
            c[a].push_back(b);
        printf("%s\n",(bfs(a))?"BICOLORABLE.":"NOT BICOLORABLE.");
    }
}
