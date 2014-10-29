#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<list>
#include<vector>
#include<cstring>
#include<iterator>
#include<algorithm>
using namespace std;
map<int,vector<int> >graph;
map<int,bool >vi;
bool dfs(int s,int from)
{
    vi[s] = true;
    for(int i=0; i<graph[s].size(); i++)
        if(!vi[graph[s][i]])
        {
            if(!dfs(graph[s][i],s))
                return false;
        }
        else if (from != graph[s][i])
            return false;
    return true;
}
int main()
{
    int s,from,c=1;
    while(scanf("%d%d",&s,&from) && s+from >= 0)
    {
        int a=s,b=from;
        if(a+b == 0)
        {
            printf("Case %d is a tree.\n",c++);
            continue;
        }
        graph = map<int,vector<int> >();
        graph[a].push_back(b);
        graph[b].push_back(a);
        vi = map<int,bool >();
        while(scanf("%d%d",&a,&b) && a+b)
        {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool ok = dfs(s,-1);
        for(map<int,vector<int> >::iterator it = graph.begin(); ok && it!=graph.end(); it++)
            ok &= (vi[it->first] == true);
        if(ok)
            printf("Case %d is a tree.\n",c++);
        else
            printf("Case %d is not a tree.\n",c++);
    }
    return 0;
}
