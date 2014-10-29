#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#define MAX 30

using namespace std;

char layers[31][31][31];
int mov[31][31][31];
int L,R,C;

bool inside(int i, int j, int k)
{
    return i>=0 && i<L && j>=0 && j<R &&  k>=0 && k<C;
}
int next [6][3]= {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
bool cangoto(int u,int v, int w)
{
    return inside(u,v,w) &&  layers[u][v][w]!='#';
}
int bfs(int x,int y,int z)
{
    layers[x][y][z]='#';
    queue<int>qx,qy,qz;
    qx.push(x);
    qy.push(y);
    qz.push(z);
    mov[x][y][z]=0;
    while(!qx.empty())
    {
        x = qx.front();
        y = qy.front();
        z = qz.front();
        qx.pop();
        qz.pop();
        qy.pop();
        for(int i=0; i<6; i++)
        {
            int u = x+next[i][0];
            int v = y+next[i][1];
            int w = z+next[i][2];
            if(cangoto(u,v,w))
            {
                if(layers[u][v][w]=='E')
                    return mov[x][y][z]+1;
                layers[u][v][w]='#';
                qx.push(u);
                qy.push(v);
                qz.push(w);
                mov[u][v][w] = mov[x][y][z]+1;
            }

        }
    }
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int dx,dy,dz;
    while(scanf("%d%d%d\n",&L,&R,&C)==3 && L)
    {
        bool found=false;

        for(int i=0;i<L;i++)
        {
            for(int j=0;j<R;j++)
            {
                gets(layers[i][j]);
                //puts(layers[i][j]);
                if(found) continue;
                for(int k= 0; layers[i][j][k] ; k++)
                    if(layers[i][j][k]=='S')
                    {
                        found = true;
                        dx = i;
                        dy = j;
                        dz = k;
                    }
            }
            char blank[5];
            gets(blank);
        }


        int t=bfs(dx,dy,dz);
        if(t)  printf("Escaped in %d minute(s).\n",t);
        else printf("Trapped!\n");

    }
    return 0;
}
