#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int n,m;
vector<string> x;
int dc[] = {-1,0,1,-1,0,1,-1,0,1};
int dr[] = {-1,-1,-1,0,0,0,1,1,1};
vector<vector<bool> >visited;
bool inside(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m;
}
int dfs(int i,int j)
{
    if(x[i][j] =='L') return 0;
    int ans = 1;
    visited[i][j] =true;
    for(int h=0; h<9; h++)
    {
        int u=i+dr[h];
        int v=j+dc[h];
        if(inside(u,v) && x[u][v]=='W' && !visited[u][v])
            ans += dfs(u,v);
    }
    return ans;
}
int main()
{
    int cases =0;
    scanf("%d",&cases);
    int xd = 0;
    while(cases--)
    {
        x = vector<string>();
        n=0;
        string s;
        while(getline(cin,s) && count(s.begin(),s.end(),' ')!=1)
        {
            if(s=="")continue;
            x.push_back(s);
            n++;
        }
        m = x[0].length();
        int a,b;
        stringstream ss;
        ss<<s;
        ss>>a>>b;
        visited = vector<vector<bool> >(n,vector<bool>(m,0));
        //cout<<x[a][b-1]<<endl;
        printf("%d\n",dfs(a-1,b-1));
        while(getline(cin,s) && count(s.begin(),s.end(),' ')==1)
        {
            ss.clear();
            ss<<s;
            ss>>a>>b;
            visited = vector<vector<bool> >(n,vector<bool>(m,0));
            printf("%d\n",dfs(a-1,b-1));
        }
        if (cases) printf("\n");
    }
    return 0;
}
