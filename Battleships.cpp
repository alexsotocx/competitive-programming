#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<sstream>
using namespace std;
vector<string> maze;
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
int n;
bool inside(int i,int j)
{
    return i>= 0 && i<n && j>=0 && j<n;
}
void dfs(int x, int y)
{
    maze[x][y]='.';
    for(int i=0; i<4; i++)
    {
        int u = x+dx[i];
        int v = y+dy[i];
        if(inside(u,v) &&  maze[u][v]!='.')
            dfs(u,v);
    }
}
int main()
{
    int c,cases=1;
    scanf("%d",&c);
    while(c-- && scanf("%d",&n))
    {
        maze = vector<string>(n,"");

        for(int i=0;i<n;cin>>maze[i++]);
        int con =0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            if(maze[i][j]=='x')
            {

                dfs(i,j);
                con++;
            }
        printf("Case %d: %d\n",cases++,con);
    }
    return 0;
}
