#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
class Edge
{
public:
    int p1;
    int p2;
    int w;
public:
    Edge() {}
    Edge(int p11,int p22,int ww)
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

int main()
{
    int t,n,m;
    scanf("%d",&t);
    int c=1;
    while(t-- && scanf("%d%d",&n,&m))
    {
        UnionFind un(n);
        Edge *p = new Edge[m];
        for(int i=0;i<m;i++)
        {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            p[i] = Edge(a,b,w);
        }
        sort(p,p+m,comp);
        int cost=99999999;
        for(int i=0;i<m;i++){
            if(un.merge(p[i].p1,p[i].p2))
                cost=min(p[i].w,cost);
        }
        printf("Case #%d: %d\n",c++,cost);

    }
    return 0;
}
