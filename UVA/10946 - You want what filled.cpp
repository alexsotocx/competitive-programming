#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
vector<pair<char,int> >l;
vector<char>charac;
vector<string>x;
vector<vector<bool> >visited;
int n,m;
bool comp(const pair<char,int> &a,const pair<char,int> &b)
{
    if(a.second > b.second)
        return true;
    if (a.second == b.second)
        return a.first<b.first;
    return false;
}
bool inside(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m;
}
int dr[]={0,-1,0,1};
int dc[]={-1,0,1,0};
int dfs(int i,int j, char &s)
{
    int ans=1;
    visited[i][j]=1;
    for(int d=0;d<4;d++)
        if(inside(i+dr[d],j+dc[d]) &&  !visited[i+dr[d]][j+dc[d]] && x[i+dr[d]][j+dc[d]]==s)
            ans+=dfs(i+dr[d],j+dc[d],s);
    return ans;
}
int main()
{
    int cases=1;
    while(scanf("%d%d",&n,&m)==2 && n && m)
    {
        x=vector<string>(n,"");
        visited = vector<vector<bool> >(n,vector<bool>(m,0));
        l=vector<pair<char,int> >();
        for(int i=0;i<n;cin>>x[i++]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(x[i][j]!='.' && !visited[i][j])
                    l.push_back(pair<char,int>(x[i][j],dfs(i,j,x[i][j])));
        printf("Problem %d:\n",cases++);
        sort(l.begin(),l.end(),comp);
        for(int i=0;i<l.size();i++)
            printf("%c %d\n",l[i].first,l[i].second);
    }
    return 0;
}
