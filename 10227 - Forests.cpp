#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
int n,p,t;
class UnionFind
{
public:
    int vistos[103][103];
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
        memset(vistos, 0, sizeof(vistos));
    }
    int find(int u)
    {
        return p[u] == u ? u : (p[u] = find(p[u]));
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
    bool SameOpinion(int i,int j)
    {
        for(int k = 0; k < t; ++k)
            if(vistos[i][k] != vistos[j][k])
                return false;
        return true;
    }
};
int main()
{

    cin>>n;
    getchar();
    getchar();
    while(n--)
    {
        cin>>p>>t;
        getchar();
        UnionFind x(p);
        string s;
        int a,b;
        while(getline(cin,s) && s!="")
        {
            sscanf(s.c_str(),"%d%d",&a,&b);
            x.vistos[a-1][b-1]=1;
        }

        for(int i=0; i<p; i++)
            for(int j=i+1; j<p; j++)
                if(x.SameOpinion(i,j))
                    x.merge(i,j);
        printf("%d\n",x.ssets());
        if(n)printf("\n");
    }
    return 0;
}
