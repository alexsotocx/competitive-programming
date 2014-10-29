#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
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
        return p[u] == u ? u : (u = find(p[u]));
    }
    void merge(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
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
