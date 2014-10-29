#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
class UnionFind
{
private:
    int *p;
    int *rank;
    int *size;
    int *money;
    int sets;
    int N;
ublic:
    UnionFind(int _N)
    {
        N = _N;
        p = new int[N];
        rank = new int[N];
        size = new int[N];
        money = new int[N];
        sets = N;
        for (int i = 0; i < N; ++i)
        {
            p[i] = i, rank[i] = 0,size[i] = 1;
            scanf("%d",&money[i]);
        }
    }
    int find(int u)
    {
        return p[u] == u ? u : (p[u] = find(p[u]));
    }
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v])
            size[v] += size[u],p[u] = v, money[v] += money[u];
        else
            size[u] += size[v],p[v] = u, money[u] += money[v];
        if (rank[u] == rank[v]) ++rank[u];
        --sets;
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
    bool moneyok(int x)
    {
        return !money[find(x)];
    }
};

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,m,c;
        scanf("%d%d",&n,&m);
        UnionFind x(n);
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            x.merge(a,b);
        }
        bool isok= true;
        for(int i=0; i<n && isok; i++)
            isok &= x.moneyok(i);
        if(isok)printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
}
