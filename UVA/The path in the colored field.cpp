#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
vector<string>xi;
vector<vector<int> >leng;
int dr[]= {-1,0,1,0};
int dc[]= {0,1,0,-1};
int m;
bool inside(int i,int j)
{
    return i>=0 && i<m && j>=0 && j<m;
}
int bfs(int x,int y)
{
    leng = vector<vector<int> >(m,vector<int>(m,0));
    queue<int>qx,qy;
    qx.push(x);
    qy.push(y);
    leng[x][y]=0;
    while(!qx.empty())
    {
        x=qx.front();
        y=qy.front();
        qx.pop();
        qy.pop();
        for(int i=0; i<4; i++)
        {
            int u = x+ dr[i];
            int v = y+ dc[i];
            if(inside(u,v) && !leng[u][v])
            {
                leng[u][v] = leng[x][y]+1;
                qx.push(u);
                qy.push(v);
                if(xi[u][v]=='3') return leng[u][v];
            }
        }
    }
}
int main()
{
    while(scanf("%d",&m)==1)
    {
        xi= vector<string>(m,"");

        for(int i=0; i<m; cin>>xi[i++]);
        int maxx=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<m; j++)
            {
                int min =0;
                if(xi[i][j]=='1')
                    min = bfs(i,j);
                maxx=(maxx>min)?maxx:min;
            }
        printf("%d\n",maxx);
    }
    return 0;
}
