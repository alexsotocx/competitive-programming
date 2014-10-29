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
#define ii pair<int,int>
map<int,vector< ii > >graph;
map<int,bool >vi;
typedef long long ll;
int farnode;
ll bfs(int s)
{
    vi = map<int,bool >();
    map<int,ll > dist;
    ll maxdist = 0;
    queue<int>q;
    q.push(s);
    vi[s]=true;
    farnode=s;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        if(maxdist < dist[s])
            farnode=s,maxdist=dist[s];
        for(int i=0; i<graph[s].size(); i++)
        {
            int u = graph[s][i].first;
            if(!vi[u])
            {
                vi[u] = true;
                dist[u] = dist[s] + graph[s][i].second;
                q.push(u);
            }
        }
    }
    return maxdist;
}
int main()
{
    int a,b,w;
    char s[100];
    while(gets(s))
    {
        if(strcmp("",s)==0)
        {
            printf("0\n");
            continue;
        }

        sscanf(s,"%d%d%d",&a,&b,&w);
        graph = map<int,vector< ii > >();
        map<int,bool >vi;
        graph[a].push_back(ii(b,w));
        graph[b].push_back(ii(a,w));
        while(gets(s) && strcmp(s,"")!=0 && sscanf(s,"%d%d%d",&a,&b,&w))
        {
            graph[a].push_back(ii(b,w));
            graph[b].push_back(ii(a,w));
        }
        bfs(1);
        printf("%lld\n",bfs(farnode));
    }

}

