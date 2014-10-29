#include<vector>
#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;
vector<string> table;
int count;
int m,n;
vector<vector<bool> >visited;
int dc[] = {-1,0,1,-1,1,-1,0,1};
int dr[] = {-1,-1,-1,0,0,1,1,1};
bool inside(int i,int j)
{
    return i>=0 && i<4 && j>=0 && j<4;
}
string stop;
bool xd=false;
void dfs(int x, int y, string s)
{
    //cout<<s<<endl;
    if(s==stop)
    {
        xd = true;
        return ;
    }

    string aux= s+stop[s.length()];

    for(int i=0; i<8; i++)
    {
        int u = x+dr[i];
        int v = y+dc[i];
        if(inside(u,v)  && table[u][v] == stop[(int)s.length()] && visited[u][v] == false)
        {
            //cout<<u<<" "<<v<<endl;
            visited[u][v]=true;
            dfs(u,v,aux);
            visited[u][v]=false;
            if (xd) return;

        }
    }
}
int main()
{
    int cases = 0;
    scanf("%d",&cases);
    int counter=1;
    while(cases--)
    {
        table = vector<string>(4,"");
        visited = vector<vector<bool> >(4,vector<bool>(4,0));
        for(int i=0; i<4; cin>>table[i++]);
        int dic;
        scanf("%d",&dic);
        int pointss = 0;
        while(dic-- && cin>>stop)
        {
            char c = stop[0];
            xd = false;
            for(int i=0; i<4 && !xd; i++)
                for(int j=0; j<4 && !xd; j++)
                    if(table[i][j]==c)
                    {
                        visited[i][j]=true;
                        dfs(i,j,string(stop.begin(),stop.begin()+1));
                        visited = vector<vector<bool> >(4,vector<bool>(4,0));
                    }

            int p = stop.length();

            if(xd)
            {
                if(p<3) continue;
                switch(p)
                {
                case 3:
                    pointss = pointss+1;
                    break;
                case 4:
                    pointss = pointss+1;
                    break;
                case 5:
                    pointss = pointss+2;
                    break;
                case 6:
                    pointss = pointss+3;
                    break;
                case 7:
                    pointss = pointss+5;
                    break;
                default:
                    pointss = pointss + 11;
                    break;

                }
            }
        }
        printf("Score for Boggle game #%d: %d\n",counter++, pointss);
    }
    return 0;
}
