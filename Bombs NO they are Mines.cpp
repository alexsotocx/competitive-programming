#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
#define M 1005
#define mp(x,y) make_pair(x,y)
bool visited[M][M];
int n,m;
int next[4][2] = { {0,-1},{-1,0},{0,1},{1,0}};
bool canGo(int u, int v)
{
    return u>=0 && u<n && v>=0 && v<m && !visited[u][v];
}
void bfs(int x, int y, int tx, int ty)
{
    queue<int>cost;
    queue<pair<int,int> >q;
    q.push(mp(x,y));
    cost.push(0);
    visited[x][y]=1;
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        int w = cost.front();
        q.pop();
        cost.pop();
        for(int i=0; i<4; i++)
        {
            int u = x + next[i][0];
            int v = y + next[i][1];
            if(canGo(u,v))
            {
                if(u==tx && v== ty)
                {
                    printf("%d\n",w+1);
                    return;
                }
                q.push(mp(u,v));
                visited[u][v]=1;
                cost.push(w+1);
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)==2 && n)
    {
        int l;
        memset(visited,0,sizeof(visited));
        scanf("%d",&l);
        while(l--)
        {
            int r, k,c;
            scanf("%d%d",&r,&k);
            while(k-- && scanf("%d",&c)==1)
                visited[r][c]=1;

        }
        int x,y,tx,ty;
        scanf("%d%d%d%d",&x,&y,&tx,&ty);
        //cout<<x<<" "<<y<<" "<<tx<<" "<<ty<<endl;
        bfs(x,y,tx,ty);
    }
    return 0;
}
