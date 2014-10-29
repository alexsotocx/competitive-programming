#include<vector>
#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
vector<string> x;

int m,n;
vector<vector<bool> >visited;
vector<vector<bool> >visited2;
int dr[] = {-1, 0, 0, 1};
int dc []= {0, -1, 1, 0};
bool inside(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m;
}
//int count;
void bfsx(int i,int j)
{
    visited2[i][j] = true;
    for (int d = 0; d < 4; ++d)
    {
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (inside(ni, nj) && !visited2[ni][nj] && x[ni][nj] == 'X')
            bfsx(ni, nj);
    }
}


int c=0;
void dfs(int i,int j)
{
    visited[i][j]=1;
    for(int d=0; d<4; d++)
    {
        int u=i+dr[d];
        int v=j+dc[d];
        if(inside(u,v) && !visited[u][v] && x[u][v]!='.')
        {
            if(x[u][v]=='X' && !visited2[u][v])
            {
                if(x[i][j]!='X')
                    c++;
                bfsx(u,v);
            }
            dfs(u,v);
        }
    }
}
int main()
{
    int cases=1;
    while(scanf("%d%d",&m,&n)==2 && m && n)
    {
        c=0;
        x = vector<string>(n,"");
        visited = vector<vector<bool> >(n,vector<bool>(m,0));
        visited2 = vector<vector<bool> >(n,vector<bool>(m,0));
        for(int i=0; i<n; i++)
        {
            string c;
            cin>>c;
            x[i]=c;
        }
        vector<int>ret;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {

                if(x [i][j]!='.' && !visited[i][j])
                {
                    c =0;
                    if(x[i][j]=='X')
                    {
                        c++;
                        bfsx(i,j);
                    }
                    dfs(i,j);
                    ret.push_back(c);
                }
            }
        }
        printf("Throw %d\n",cases++);
        sort(ret.begin(),ret.end());
        printf("%d",ret[0]);
        for(int i=1; i<ret.size(); i++)
            printf(" %d",ret[i]);
        printf("\n");
        printf("\n");

    }
    return 0;

}
