#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
vector<vector<int> >g;
bool *vi;
void dfs(int s)
{
    vi[s] = true;
    for(int i=0;i<g[s].size();i++)
        if(!vi[g[s][i]])
            dfs(g[s][i]);

}
int main()
{
    int t,n,m,x,y;
    scanf("%d",&t);
    while(t-- && scanf("%d%d",&n,&m))
    {
        g = vector<vector<int> >(n);
        while(m-- && scanf("%d%d",&x,&y))
            g[x-1].push_back(y-1);
        vi = new bool[n];
        int ret=0;
        for(int i=0;i<n;i++)
            if(!vi[i])
            {
                dfs(i);
                ret++;
            }
        printf("%d\n",ret);

    }
    return 0;
}
