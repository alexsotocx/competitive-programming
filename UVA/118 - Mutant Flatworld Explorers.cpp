#include<vector>
#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;
int n,m;
int x,y;
char S;
bool inside(int i, int j)
{
    return i>=0 && i<=n && j>=0 && j<=m;
}
void front()
{
    if(S=='N') y++;
    else if(S=='S')
        y--;
    else if(S=='E')
        x++;
    else
        x--;
}
void right()
{
    if(S=='N')S='E';
    else if(S=='S')S='W';
    else if(S=='E')S='S';
    else S='N';
}
void left()
{
    if(S=='N') S='W';
    else if(S=='S')S='E';
    else if(S=='E')S='N';
    else  S='S';
}
int main()
{
    scanf("%d%d",&n,&m);
    string c;
    vector<vector<bool> > visited(m+1,vector<bool>(n+1,false));
    while(cin>>x>>y>>S>>c)
    {
        bool ok= true;

        for(int i=0; i<c.length(); i++)
        {
            //cout<<x<<" "<<y<<" "<<S<<endl;
            if(c[i]=='F')
            {
                int aux1=x,aux2=y;
                front();
                if(!inside(x,y) && !visited[aux1][aux2])
                {
                    visited[aux1][aux2]=true;
                    printf("%d %d %c LOST\n",aux1,aux2,S);
                    ok =false;
                    break;
                }
                else if(visited[aux1][aux2] && !inside(x,y))
                {
                    x=aux1;
                    y = aux2;
                    continue;
                }
            }
            else if(c[i]=='R')right();
            else  left();
        }
        if(ok)
            printf("%d %d %c\n",x,y,S);
    }
    return 0;
}
