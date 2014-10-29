#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
vector<vector<bool> >visited;
vector<string>x;
int m;
bool inside(int i,int j)
{
     return i<0 || i ==x.size() || j<0 || x[i].length() == j || visited[i][j] || (x[i][j] != '*' && x[i][j] != ' ');
}
void dfs(int i,int j)
{
    if(inside(i,j)) return;
    visited[i][j]=true;
    x[i][j]='#';
    for(int d=0; d<4; d++)
        dfs(i+dr[d],j+dc[d]);
}

int main()
{
    int m;
    scanf("%d",&m);
    while(m--)
    {
        x = vector<string>();
        string c;
        visited = vector<vector<bool> >();
        while(getline(cin,c) && c[0]!='_'){
            visited.push_back(vector<bool>(c.length(),0));
            x.push_back(c);
        }
        bool ok = true;
        for(int i=0; i<x.size() && ok; i++)
            for(int j=0; j<x[i].length() && ok; j++)
                if(x[i][j]=='*')
                {
                    dfs(i,j);
                }
        for(int i=0; i<x.size(); i++)
            printf("%s\n",x[i].c_str());
        printf("%s\n",c.c_str());

    }
    return 0;
}
