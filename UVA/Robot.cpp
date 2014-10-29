#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define M 105
typedef vector<vector<bool> >vvb;
vector<string>maze;
int n,m;
vector< vector<int> >c;
bool cango(int u, int v)
{
    return u>=0 && u<n && v>=0 && v<m && maze[u][v]!='1';
}
bool wallrigth(int u, int v)
{
    if(botor=='E')
        return u+1==n || maze[u+1][v]=='1';
    else if(botor=='N')
        return v+1==m || maze[u][v+1]=='1';
    else if(botor=='W')
        return  u-1==-1 || maze[u-1][v]=='1';
    else
        return v-1==-1 || maze[u][v-1]=='1';
}

void bfs(int x,int y)
{
    queue<int>qx,qy;
    queue<int>qo;
    qx.push(x);
    qy.push(y);
    qo.push(1);
    int i=0;
    while(!qx.empty())
    {
        int xx = qx.front(),yy = qy.front(),o = qo.front();
        qx.pop();qy.pop();qo.pop();
        if(xx==x && yy==y && i) return;
        if(wallrigth(xx,yy))
        {
            if(cango(xx+,yyy))
            {

                i++;
                c[xx][yy]++;
                qx.push(xxx);
                qy.push(yyy);
                qo.push(botor);
            }
            else
            {
                L();
                qx.push(xx);
                qy.push(yy);
                qo.push(botor);
            }

        }
        else
        {
            R();
            Front(xxx,yyy);
            i++;
            c[xx][yy]++;
            qx.push(xxx);
            qy.push(yyy);
            qo.push(botor);

        }
    }
}

int main()
{
    while(scanf("%d%d\n",&n,&m)==2 && n+m)
    {
        maze=vector<string>(n,"");
        c = vector< vector<int> >(n,vector<int>(m,0));
        for(int i=0; i<n; cin>>maze[i++]);
        bfs(n-1,0);
        for(int con=0; con<5; con++)
        {
            int ret=0;
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    if(c[i][j]==con  && maze[i][j]!='1')
                        ret++;
            printf("%3d",ret);
        }
        printf("\n");
    }
}
