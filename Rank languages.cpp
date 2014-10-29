#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>

using namespace std;
vector<vector<bool> > visited;
vector<string> maze;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
void dfs(int x, int y)
{
	visited[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int u = x+dx[i];
		int v = y+dy[i];
		if(inside(u,v) && !visited[u][v] && maze[u][v]==maze[x][y])
			dfs(u,v)
	}
	
}
int
