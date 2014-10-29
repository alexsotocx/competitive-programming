#include<iostream>
#include<vector>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<sstream>
#include<queue>
using namespace std;
vector<bool> visited;
vector<vector<int> >adj;
void dfs(int i)
{
    for(int d=0; d<adj[i].size(); d++)
    {
        if(!visited[adj[i][d]])
        {
            visited[adj[i][d]]=1;
            dfs(adj[i][d]);
        }
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        adj=vector<vector<int> >(n+1,vector<int>());

        string s;
        while(getline(cin,s) && s!="0")
        {
            stringstream ss;
            ss<<s;
            int f,d;
            ss>>f;
            while(ss>>d && d)
                adj[f].push_back(d);
        }
        int cas;
        scanf("%d",&cas);
        while(cas--)
        {
            int start;
            scanf("%d",&start);
            visited = vector<bool>(n+1,0);
            dfs(start);
            int count=0;
            queue<int>ret;
            for(int i=1; i<n+1; i++)
            {
                if(!visited[i])
                {
                    count++;
                    ret.push(i);
                }
            }
            printf("%d",count);
            while(!ret.empty())
            {
                printf(" %d",ret.front());
                ret.pop();
            }
            printf("\n");
        }
    }
    return 0;
}
