#include<vector>
#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;
vector<string> x;
int count;
int m;
vector<vector<bool> >visited;
int dr[] = {-2,-2,-1,1,2,2,-1,1};
int dc[] = {1,-1,2,2,1,-1,-2,-2};
string c1,c2;
bool inside(int i,int j)
{
    return i>=0 && i<8 && j>=0 && j<8;
}
string numtostring(int i, int j)
{
    stringstream ss;
    ss<<(char)(i+'a')<<j+1;
    return ss.str();
}
int xf,yf;
vector<vector<string> >lengths;
void bfs(int i,int j)
{
    lengths = vector<vector<string> >(8,vector<string>(8,numtostring(i,j)));
    queue<int> qx,qy;
    if(i==xf && j==yf) return;
    visited[i][j] = true;
    qx.push(i);
    qy.push(j);
    int ret =0;
    vector<int>aux;;
    while(!qx.empty())
    {
        int x=qx.front(),y=qy.front();
        qx.pop();
        qy.pop();
        //cout<<(char)(x+'a')<<y+1<<endl;
        if(x==xf && yf==y) return;
        for(int i=0; i<8; i++)
        {
            if(inside(x+dr[i],y+dc[i]) && !visited[x+dr[i]][y+dc[i]])
            {

                qx.push(x+dr[i]);
                qy.push(y+dc[i]);
                visited[x+dr[i]][y+dc[i]]=true;
                lengths[x+dr[i]][y+dc[i]] = lengths[x][y]+"-"+ numtostring(x+dr[i],y+dc[i]);
            }
        }


    }

}
int main()
{

    while(cin>>c1>>c2)
    {
        count =0;
        xf = c2[0]-'a';
        yf= c2[1]-'1';
        visited =vector<vector<bool> >(8,vector<bool>(8,0));
        bfs(c1[0]-'a',c1[1]-'1');
        printf("%s\n",lengths[xf][yf].c_str());

    }
    return 0;

}
