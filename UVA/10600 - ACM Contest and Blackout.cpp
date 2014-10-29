#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
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
class Edge
{
public:
    int p1;
    int p2;
    double w;
public:
    Edge() {}
    Edge(int p11,int p22,int cc)
    {
        p1 = p11;
        p2 = p22;
        w = cc;
    }
};
bool comp(const Edge &a,const Edge &b)
{
    return a.w<b.w;
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t-- && scanf("%d%d",&n,&m))
    {
        UnionFind x(n);
        Edge *p = new Edge[m];
        for(int i=0; i<m; i++)
        {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            p[i] = Edge(a-1,b-1,w);
        }
        sort(p,p+m,comp);
        int c1=0,c2=0;
        vector<int>se;
        for(int i=0; i<m; i++)
            if(x.merge(p[i].p1,p[i].p2)){se.push_back(i);
                c1+=p[i].w;
            }
        c2 =1<<29;
        for(int i=0; i<m; i++)
        {
            UnionFind x1(n);
            int c3=0;
            int nex = 0;
            bool diferente = false;
            for(int j=0; j<m; j++)
                if(i!=j && x1.merge(p[j].p1,p[j].p2))
                {
                    c3+=p[j].w;
                    if(se[nex++] != j) diferente=true;
                }
            if(diferente && x1.ssets()==1)
                c2 = min(c3,c2);
        }
        printf("%d %d\n",c1,c2);
    }
    return 0;
}
