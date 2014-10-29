#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

class Edge
{
public:
    int p1;
    int p2;
    int w;
public:
    Edge() {}
    Edge(int p11,int p22, int ww)
    {
        p1 = p11;
        p2 = p22;
        w = ww;
    }

};
bool comp(const Edge &a,const Edge &b)
{
    return a.w>b.w;
}
class UnionFind
{
private:
    int *p;
    int *rank;
    int *size;
    int sets;
    int N;
public:
    UnionFind(int _N)
    {
        N = _N;
        p = new int[N];
        rank = new int[N];
        size = new int[N];
        sets = N;
        for (int i = 0; i < N; ++i)
        {
            p[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    int find(int u)
    {
        return p[u] == u ? u : (p[u] = find(p[u]));
    }
    bool merge(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (rank[pu] < rank[pv])
        {
            size[pv] += size[pu];
            p[pu] = pv;
        }
        else
        {
            size[pu] += size[pv];
            p[pv] = pu;
        }
        if (rank[pu] == rank[pv])
            ++rank[pu];
        --sets;
        return true;
    }
    bool isSameSet(int u, int v)
    {
        return find(u) == find(v);
    }
    int setSize(int u)
    {
        return size[find(u)];
    }
    int ssets()
    {
        return sets;
    }
};
#define ii pair<int,int>
int main()
{
    int c,m,n,es=1;
    while(scanf("%d%d",&n,&m) && n+m)
    {
        Edge *x = new Edge[m];
        int c,y,w;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&c,&y,&w);
            x[i] =Edge(c-1,y-1,w);
        }
        int a,b;
        UnionFind un(n);
        sort(x,x+m,comp);
        int cost =(1<<29);
        scanf("%d %d %d",&c,&y,&w);
        for(int i=0; i<m; i++)
        {
            if(un.merge(x[i].p1,x[i].p2))
            {
                cost = min(cost,x[i].w);
                if(un.isSameSet(c-1,y-1)) break;
            }
        }

        cost--;
        if(c==y)
            printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",es++,0);
        else
            printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",es++,(w+cost)/cost);

    }

    return 0;
}
