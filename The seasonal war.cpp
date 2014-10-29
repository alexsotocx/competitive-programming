#include<vector>
#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;
vector<string> x;
int count;
int m;
vector<vector<bool> >visited;
int dc[] = {-1,0,1,-1,0,1,-1,0,1};
int dr[] = {-1,-1,-1,0,0,0,1,1,1};
bool inside(int i,int j)
{
    return i>=0 && i<m && j>=0 && j<m;
}
void dfs(int i,int j)
{
    if(!visited[i][j] && x[i][j]=='1')
    {
        visited[i][j] = true;
        for(int k=0; k<9; k++)
            if(inside(i+dr[k],j+dc[k]))
                dfs(i+dr[k],j+dc[k]);
    }
}
int main()
{
    int cases=1;
    while(scanf("%d",&m)==1)
    {
        count =0;
        x = vector<string>(m,"");

        visited = vector<vector<bool> >(m,vector<bool>(m,0));
        for(int i=0; i<m; i++)
        {
            string c;
            cin>>c;
            x[i]=c;
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(x [i][j]=='1' && !visited[i][j])
                {
                    count++;
                    dfs(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",cases++,count);

    }
    return 0;

}
