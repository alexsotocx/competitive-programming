#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
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
        if (pu == pv) return true;
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
        return false;
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
    int v,e;
    while(cin>>v>>e)
    {
        char k,s;
        UnionFind x(v);
        map<char,int>mp;
        int j=0;
        int res=1;
        for(int i=0;i<e;i++){
            cin>>k>>s;
            if(mp.find(k)==mp.end())mp[k]=j++;
            if(mp.find(s)==mp.end())mp[s]=j++;
            if(x.merge(mp[k],mp[s]))res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
