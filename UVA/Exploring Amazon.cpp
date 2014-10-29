#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
bool visited[1000+5];
class nodo
{
public:
    int x;
    int y;
    nodo *ne1;
    nodo *ne2;
public:
    nodo() {}
    nodo(int xx, int yy)
    {
        x=xx;
        y= yy;
    }

};
map<pair<int,int> ,  int>pos;
vector<nodo> graph;
int n;
int con=0;
void dfs(nodo x)
{

    int ind = pos[make_pair(x.x,x.y)];
    if(visited[ind]) return;
    visited[ind]=1;
    con++;
    dfs(*x.ne1);
    dfs(*x.ne2);

}
double le(nodo &x, nodo &y)
{
    return sqrt((x.x-y.x)*(x.x-y.x) + (x.y-y.y)*(x.y-y.y));
}
int main()
{
    while(scanf("%d",&n)==1 && n)
    {
        pos = map< pair<int,int>,int>();
        graph = vector<nodo>();
        memset(visited,0,sizeof(visited));
        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            pii lol = make_pair(x,y);
            pos[lol]=i;
            graph.push_back(nodo(x,y));
        }
        if(n<=2) {printf("All stations are reachable.\n");continue;}
        for(int i=0; i<n; i++)
        {
            nodo *x = &graph[0];
            nodo *y = &graph[1];
            double dx=0.0;
            //cout<<x->x<<" "<<x->y<<" "<<dx<<endl;
            double dy=0.0;
            //cout<<i<<endl;
            for(int j=0; j<n; j++)
            {
                if(i==j) continue;
                //cout<<"dx = "<<dx<<endl;
                //cout<<"dy = "<<dy<<endl;
                double dl = le(graph[i],graph[j]);
                if(dl<dx  || dx==0.0 )
                    dx=dl, x = &graph[j];
                else if(dl<dy && dx<dy || dy==0.0)
                    dy=dl, y = &graph[j];
                else if(dl==dx && (x->x>graph[j].x || x->y>graph[j].y))
                    x = &graph[j];
                else if(dl==dy && dy>dx && (y->x>graph[j].x || y->y>graph[j].y))
                    y = &graph[j];

            }

            graph[i].ne1 = x;
            graph[i].ne2 = y;

        }
        con =0;
        dfs(graph[0]);
        if(con == n) printf("All stations are reachable.\n");
        else printf("There are stations that are unreachable.\n");
    }
    return 0;
}

