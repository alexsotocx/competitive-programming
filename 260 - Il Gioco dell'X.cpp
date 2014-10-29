#include<vector>
#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;
vector<string> x;
int count;
int m;
bool win=false;
vector<vector<bool> >visited;
int dr[] = {-1,0,1,-1,0,1};
int dc[] = {-1,-1,0,0,1,1};
bool inside(int i,int j)
{
    return i>=0 && i<m && j>=0 && j<m;
}
void dfs(int i,int j)
{
    visited[i][j]=1;
    if(i==m-1)
    {
        win=true;
        return;
    }

    for(int d=0; d<6; d++)
    {
        int u = i + dr[d];
        int v = j + dc[d];
        if(inside(u,v) && !visited[u][v] && x[u][v]=='b')
            dfs(u,v);
    }
}
int main()
{
    int cases=1;
    while(scanf("%d",&m)==1 && m)
    {
        win = false;
        count =0;
        x = vector<string>(m,"");
        visited = vector<vector<bool> >(m,vector<bool>(m,0));
        for(int i=0; i<m; i++)
        {
            string c;
            cin>>c;
            x[i]=c;
        }

        for(int j=0; j<m; j++)
            if(x [0][j]=='b' && !visited[0][j])
                dfs(0,j);


        printf("%d %c\n",cases++,(win)?'B':'W');

    }
    return 0;

}
