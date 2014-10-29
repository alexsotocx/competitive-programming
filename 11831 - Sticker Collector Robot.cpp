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
char maze[M][M];
int n,m,ors;
bool canGo(int u, int v)
{
    return u>=0 && u<n && v>=0 && v<m && maze[u][v]!='#';
}
char botor;
void Front(int &u, int &v)
{
    if(botor=='N')
        --u;
    else if(botor=='L')
        ++v;
    else if(botor=='S')
        ++u;
    else
        v--;
}
void D()
{
    if(botor=='N')
        botor='L';
    else if(botor=='L')
        botor='S';
    else if(botor=='S')
        botor='O';
    else
        botor='N';
}
void E()
{
    if(botor=='N')
        botor='O';
    else if(botor=='L')
        botor='N';
    else if(botor=='S')
        botor='L';
    else
        botor='S';
}
char orders[50005];
int iterat=0;
int dfs(int x,int y)
{
    int ans=(maze[x][y]=='*')?1:0;
    maze[x][y]='1';
    cout<<x<< " "<<y<<" "<<botor<<endl;
    if(iterat>=ors) return ans;
    char c= orders[iterat++];

    if(c=='F')
    {
        int xx =x;
        int yy = y;
        Front(xx,yy);
        if(canGo(xx,yy))
            ans+=dfs(xx,yy);
        else
            ans+=dfs(x,y);
    }
    else if(c=='D')
        D(),ans+=dfs(x,y);
    else
        E(), ans+=dfs(x,y);
    return ans;
}
bool isletter(char c)
{
    return c>='A' && c<='Z';
}
int main()
{
    while(scanf("%d%d%d\n",&n,&m,&ors)==3 && n+m+ors)
    {
        for(int i=0;i<n;gets(maze[i++]));
        gets(orders);
        bool lol = 0;
        for(int i=0;i<n && !lol;i++)
            for(int j=0;j<m && !lol;j++)
                if(isletter(maze[i][j]))
                {
                    iterat =0;
                    botor=maze[i][j];
                    printf("%d\n",dfs(i,j));
                    lol = 1;
                }

    }
}
