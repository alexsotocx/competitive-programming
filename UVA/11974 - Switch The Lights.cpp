#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
bool visited[32768+10];
int le[32768+10];
vector<int>graph;
int n,m,t;
int bfs()
{
    queue<int>state;

    memset(visited,0,sizeof(visited));
    state.push((1<<n)-1);
    le[(1<<n)-1]=0;
    visited[(1<<n)-1]=1;
    while(!state.empty())
    {
        int l= state.front();
        state.pop();
        //cout<<l<<endl;
        for(int i=0; i<m; i++)
        {
            int x = l;
            x^=graph[i];
            //cout<<x<<endl;
            if(visited[x]) continue;
            if(!x) return le[l]+1;
            le[x]= le[l]+1;
            visited[x]=1;
            state.push(x);
        }
    }
    return 0;
}
int main()
{
    scanf("%d",&t);
    int c =1;
    while(t-- && scanf("%d%d",&n,&m))
    {
        graph = vector<int>(m,0);
        for(int j=0; j<m; j++)
        {
            for(int i=0; i<n; i++)
            {
                int a;
                scanf("%d",&a);
                if(a) graph[j]^=((1<<i));

            }
            //for(int i=0;i<graph[j].size();cout<<graph[j][i++]<<endl);
        }

        int ret = bfs();
        if(ret) printf("Case %d: %d\n",c++,ret);
        else printf("Case %d: IMPOSSIBLE\n",c++);
    }
    return 0;
}
