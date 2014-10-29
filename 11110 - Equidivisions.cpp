#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<sstream>
using namespace std;
vector<vector<bool> > visited;
vector<vector<int> > maze;
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
int n;
bool inside(int i,int j)
{
    return i>= 0 && i<n && j>=0 && j<n;
}
int dfs(int x, int y)
{
    visited[x][y]=1;
    int ans=1;
    for(int i=0; i<4; i++)
    {
        int u = x+dx[i];
        int v = y+dy[i];
        if(inside(u,v) && !visited[u][v] && maze[u][v]==maze[x][y])
            ans+=dfs(u,v);
    }
    return ans;

}
int main()
{
    while(cin>> n && n)
    {

        maze = vector<vector<int> >(n,vector<int>(n,n-1));
        visited=vector<vector<bool> >(n,vector<bool>(n,0));
        for(int i=0; i<n-1; i++)
        {
            string x;
            getline(cin,x);

            stringstream ss;
            ss<<x;
            int a,b;
            while(ss>>a>>b)
                maze[a-1][b-1]=i;

        }
        bool good = true;
        for(int i=0; i<n && good; i++){
            for(int j=0; j<n && good; j++)
            {
                if(!visited[i][j])
                {
                    int aux2 = dfs(i,j);
                    if(aux2!=n) good=false;
                }
            }
        }
        if(good)cout<<"good\n";
        else cout<<"wrong\n";

    }
}
