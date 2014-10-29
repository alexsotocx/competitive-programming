#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class UnionFind
{
public:
    int *rank;
    int *size;
    int *maxperset;
    int *p;
    int set;
public:
    UnionFind(int n)
    {
        rank = new int[n];
        p = new int[n];
        size = new int[n];
        maxperset = new int[n];
        set = n;
        for(int i=0; i<n; i++)
            rank[i]=0,size[i]=1,p[i]=i;

    }
    int find(int x)
    {
        return p[x]==  x ? x : (p[x] = find(p[x]));
    }
    bool merge(int x,int y)
    {
        x = find(x);
        y = find(y);
        if(x==y) return false;
        if(rank[x]<rank[y])
            size[y] += size[x],p[x] = y;
        else
            p[y] = x, size[x]+=size[y];
        if(rank[x]==rank[y])
            rank[x]++;
        set--;
        return true;
    }
    bool sameset(int x,int y)
    {
        return find(x)==find(y);
    }
    int sizeofset(int x)
    {
        return size[find(x)];
    }
    int sets()
    {
        return set;
    }
};
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
    return a.w<b.w;
}
int c,s,q;
#define ii pair<int, int>

int main()
{
    int t,cc=1;
    scanf("%d",&t);
    while(t-- && scanf("%d%d%d",&c,&s,&q))
    {
        UnionFind un(c);
        int w,a,b;
        Edge *x = new Edge[s];
        for(int i=0; i<s; i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            x[i] = Edge(a-1,b-1,w);
        }
        sort(x,x+s,comp);
        int cost = 0,j=0;
        for(int i=0;i<s && j<c-1 &&    x[i].w<q;i++)
            if(un.merge(x[i].p1,x[i].p2))
                cost+=x[i].w,j++;
        cost+=q*un.sets();
        printf("Case #%d: %d %d\n",cc++,cost,un.sets());

    }
    return 0;
}
