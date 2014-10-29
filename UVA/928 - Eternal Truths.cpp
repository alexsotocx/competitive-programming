#include<vector>
#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

bool visited[300][300][4];
int length[300][300][4];
vector<string>s;
int d=1;
int m,n;
int dr[]= {0,1,0,-1};
int dc[]= {1,0,-1,0};
bool inside(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m;
}
int bfs(int x,int y)
{
    d=1;
    queue<int>qx,qy;
    queue<int>qd;
    qx.push(x);
    qy.push(y);
    qd.push(d);
    while(!qx.empty())
    {

        x = qx.front();
        y = qy.front();
        d = qd.front();
        cout<<x<<" "<<y<<" "<<d<<endl;
        qx.pop();
        qy.pop();
        qd.pop();
        if(s[x][y]=='E')
        {
            return 1;
        }

        for(int j=0; j<4; j++)
        {
            int u = x + dr[j]*d;
            int v = y + dc[j]*d;
            if(inside(u,v) && visited[u][v][d] && s[u][v]!='#')
            {

                visited[u][v][d]=true;
                qx.push(u);
                qy.push(v);
                int aux= (d%3 + 1);
                qd.push((aux);
                if(d==1)length[u][v][aux]= length[x][y][d]+1;
                if(d==2)length[u][v][aux]= length[x][y][d]+1;
                if(d==3)length[u][v][aux]=length[x][y][d]+1;

            }
        }

    }
    return 0;
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&m,&n);
        s = vector<string>(n,"");
        visited = new bool[n][m][3];
        length = new int[n][m][3];
        for(int i=0; i<n; i++)
        {
            string c;
            cin>>c;
            s[i]=c;
        }
        int ret=-1;
        for(int i=0; i<n && ret==-1; i++)
            for(int j=0; j<m && ret==-1; j++)
                if(s[i][j]=='S')
                    ret = bfs(i,j);
        if(!ret) printf("NO\n");
        else printf("%d\n",ret);

    }
    return 0;

}
