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
int n,m;
bool canGo(int u, int v)
{
    return u>=0 && u<n && v>=0 && v<m && maze[u][v]!='*';
}
char botor;
void Front(int &u, int &v)
{
    if(botor=='N')
        --u;
    else if(botor=='E')
        ++v;
    else if(botor=='S')
        ++u;
    else
        v--;
}
void R()
{
    switch(botor){
		case 'N': botor = 'E'; break;
		case 'E': botor = 'S'; break;
		case 'S': botor = 'W'; break;
		case 'W': botor = 'N'; break;
	}
}
void L()
{
    switch(botor){
		case 'N': botor = 'W'; break;
		case 'W': botor = 'S'; break;
		case 'S': botor = 'E'; break;
		case 'E': botor = 'N'; break;
	}
}

void dfs(int x,int y)
{
    char c;
    scanf("%c",&c);
    if(c==' ') dfs(x,y);
    else if(c == 'Q'){ printf("%d %d %c\n",x,y,botor);return;}
    else if(c=='F')
    {
        int xx =x;
        int yy = y;
        Front(xx,yy);
        if(canGo(xx,yy))
            dfs(xx,yy);
        else
            dfs(x,y);
    }
    else if(c=='R')
        R(),dfs(x,y);
    else
        L(),dfs(x,y);
}

int main()
{
    int cases;
    scanf("%d\n",&cases);
    while(cases--)
    {
        scanf("%d%d\n",&n,&m);
        for(int i=0;i<n;gets(maze[i++]));
        int x,y;
        scanf("%d%d",&x,&y);
        botor= 'N';
        dfs(x-1,y-1);
        if(cases) printf("\n");
    }
}
