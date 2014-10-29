#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<sstream>
#include<algorithm>
using namespace std;
int n,m;
vector<vector <bool> >visited;
vector<vector<int> >ret;
vector<string>in;
int dc[] = {-1,0,1,-1,0,1,-1,0,1};
int dr[] = {-1,-1,-1,0,0,0,1,1,1};
bool isnotachar(char &a)
{
    return !((a>='a' && a<='z') ||(a>='A' && a<='Z'));
}

bool inside(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m;
}
int x=1;
void dfs(int i, int j, char &s)
{
    //cout<<s<<endl;
    visited[i][j]=true;
    ret[i][j]=x;
    for(int d = 0 ; d<9; d++)
    {
        int u = i + dr[d];
        int v = j + dc[d];
        if(inside(u,v) && !visited[u][v] && in[u][v]==s)
            dfs(u,v,s);
    }
}
int main()
{
    int continues = 1;
    while(continues)
    {
        string s;
        in = vector<string>();
        while(true)
        {

            if(!(getline(cin,s))){continues =0; break;}
            if(s=="%") break;
            int lol = s.length() - count_if(s.begin(),s.end(),isnotachar);
            remove_if(s.begin(),s.end(),isnotachar);
            s = string(s.begin(),s.begin()+lol);
            in.push_back(s);
        }

        m = in[0].length();
        n = in.size();
        x=1;
        visited = vector<vector<bool> >(n,vector<bool>(m,0));
        ret = vector<vector<int> >(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!visited[i][j]){
                    dfs(i,j,in[i][j]);
                    x++;
                }
        vector<int> max_length (m,0);
        for(int j=0;j<m;j++)
        {
            max_length[j] = ret[0][j];
            for(int i=1;i<n;i++)
                max_length[j] = (max_length[j]<ret[i][j])?ret[i][j]:max_length[j];
            int lol = 0;
            while(max_length[j]!=0){
                lol++;
                max_length[j]/=10;
            }
            max_length[j] = lol;
        }
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<m;j++)
                printf("%*d",(j)?max_length[j]+1:max_length[j],ret[i][j]);
            printf("\n");
        }
        printf("%\n");

    }
}
