#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<stack>
#include<map>

#include<cstring>
#define INF 2147483647
using namespace std;
char currents[1000+5][1000+5];
bool visited[1000+5][1000+5];
int length[1000+5][1000+5];

//vector<vector<int> >length;
int n,m;
int next[8][2]= {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
bool cangoto(int u,int v)
{
    return u>=0 && u<n && v>=0 && v<m && !visited[u][v];
}
class Edge
{
  public:
  int x;
  int y;
  int w;
  public:
  Edge(int xx,int yy, int ww)
  {
      x=xx;
      y=yy;
      w = ww;
  }
  Edge(){}
};
class CompareEdges {
    public:
    bool operator()(Edge& e1, Edge& e2) // Returns true if t1 is earlier than t2
    {
       return e1.w>e2.w;
    }
};
int bfs(int x, int y, int tx,int ty)
{
    priority_queue<Edge,vector<Edge>,CompareEdges >q;
    memset(visited,0,m*n*sizeof(bool));
    memset(length,INF,m*n*sizeof(int));

    //length = vector<vector<int> >(n,vector<int>(m,INF));
    q.push(Edge(x,y,0));
    length[x][y]=0;
    while(!q.empty())
    {
        Edge aux = q.top();
        q.pop();
        //cout<<aux.x<<" "<<aux.y<<" "<<aux.w<<endl;
        if(aux.x==tx && aux.y == ty) return length[tx][ty];
        if(visited[aux.x][aux.y]) continue;
        visited[aux.x][aux.y]=1;
        for(int i=0; i<8; i++)
        {
            int u = aux.x + next[i][0];
            int v = aux.y + next[i][1];
            if(cangoto(u,v))
            {
                int cost= (i==(currents[aux.x][aux.y]-'0'))?0:1;
                if(length[u][v]>aux.w + cost)
                {
                    //cout<<u<<" "<<v<<" "<<aux.w + cost<<endl;
                    length[u][v]=aux.w + cost;
                    q.push(Edge(u,v,length[u][v]));
                }
            }
        }
    }
    return 0;
}
int main()
{

    while(scanf("%d%d\n",&n,&m)==2 && n)
    {

        for(int i=0; i<n; gets(currents[i++]));
        int c;
        scanf("%d",&c);
        while(c--)
        {
            int x,y,tx,ty;

            scanf("%d%d%d%d",&x,&y,&tx,&ty);
            printf("%d\n",bfs(x-1,y-1,tx-1,ty-1));
        }
    }
    return 0;
}
