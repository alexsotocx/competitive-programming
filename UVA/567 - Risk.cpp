#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
#define mp(x,y) make_pair(x,y)
vector<vector<int> >graph;
bool visited[21];
int tx;
void bfs(int x)
{
    memset(visited,0,sizeof(visited));
    queue<pair<int,int> >q;
    q.push(mp(x,0));
    visited[x]=1;
    while(!q.empty())
    {
        int xx=q.front().first;
        int w = q.front().second;
        q.pop();
        for(int i=0; i<graph[xx].size(); i++)
            if(!visited[graph[xx][i]])
            {
                visited[graph[xx][i]]=1;
                if(graph[xx][i]==tx)
                {
                    printf("%2d to %2d: %d\n",x,tx,w+1);
                    return;
                }
                q.push(mp(graph[xx][i],w+1));
            }
    }
}
int main()
{
    int n;
    int t=1;
    while(scanf("%d",&n)==1)
    {
        graph = vector<vector<int> >(22,vector<int>());
        for(int i=0; i<n; i++)
        {
            int j;
            scanf("%d",&j);
            graph[1].push_back(j);
            graph[j].push_back(1);
        }
        for(int i=2;i<20;i++)
        {
            scanf("%d",&n);
            int j;
            while(n-- && scanf("%d",&j)==1)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
         printf("Test Set #%d\n",t++);
         scanf("%d",&n);
         int x;
         while(n-- && scanf("%d%d",&x,&tx)==2)
            bfs(x);
        printf("\n");
    }
    return 0;
}
