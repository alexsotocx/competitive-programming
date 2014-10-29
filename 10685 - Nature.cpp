#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
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
int main()
{
    int n,m;

    while(cin>>n>>m && n+m)
    {
        UnionFind x(n);
        map<string,int>mp;
        int i=0;
        string n1,n2;
        int max = 1;
        while(n-- && cin>>n1)
            mp[n1] = i++;
        while(m-- && cin>>n1>>n2)
        {
            int ns = mp[n1];
            x.merge(ns,mp[n2]);
            max = (max<x.setSize(ns))?x.setSize(ns):max;
        }
        printf("%d\n",max);
    }
    return 0;
}
