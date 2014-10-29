#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int dr[]= {0,1,0,-1};
int dc[]= {1,0,-1,0};
int m;
vector<vector<bool> >visited;
vector<vector<int> >x;
bool inside(int i,int j)
{
    return i>=0 && j>=0 && i<m && j <m;
}
int l=0;
int in;
int dfs(int i,int j)
{
    //cout<<i<<" "<<j<<" "<<x[i][j]<<endl;
    if(visited[i][j]) return 0;
    visited[i][j]=true;
    if (((inside(i+dr[l],j+dc[l]) && visited[i+dr[l]][j+dc[l]]) ||!inside(i+dr[l],j+dc[l])) && !(i+dr[l]==j+dc[l]&& i+dr[l]==in))
        l++;
    return x[i][j]+dfs(i+dr[l],j+dc[l]) ;
}
int main()
{
    int cases=0;
    while(scanf("%d",&m)==1 && m)
    {
        l=0;
        x = vector<vector<int> >(m,vector<int>(m,0));
        visited = vector<vector<bool> >(m,vector<bool>(m,0));
        for(int i=0; i<m; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&x[i][j]);
        printf("Case %d:",++cases);
        if(m>1)
        {

            for(int i=0; i<ceil(m*1.0/2); i++)
            {
                l=0;
                in = i;
                printf(" %d",dfs(i,i));
            }
        }
        else printf(" %d",x[0][0]);
        printf("\n");

    }
    return 0;
}
