#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;

class Point
{
public:
    double x;
    double y;
public:
    Point()
    {

    }
    Point(double x, double y)
    {
        this -> x = x;
        this -> y = y;
    }
    double distances(Point a)
    {
        double xx = x - a.x;
        double yy = y - a.y;
        return sqrt(xx*xx + yy*yy);
    }
}points[1003];
class Edge
{
public:
    int p1;
    int p2;
    double w;
public:
    Edge() {}
    Edge(int p11,int p22)
    {
        p1 = p11;
        p2 = p22;
        w = points[p1].distances(points[p2]);
    }

};
bool comp(const Edge &a,const Edge &b)
{
    return a.w<b.w;
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
    int c=1,n,t;
    double m;
    scanf("%d",&t);
    while(t-- && scanf("%d%lf",&n,&m))
    {
        UnionFind un(n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&points[i].x,&points[i].y);
        vector<Edge> x;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                x.push_back(Edge(i,j));
        sort(x.begin(),x.end(),comp);
        double costr =0.0;
        int states =1;
        double costrails =0.0;
        for(int i=0;i<x.size();i++)
            if(x[i].w <= m && un.merge(x[i].p1,x[i].p2))
                costr += x[i].w;
            else if(x[i].w>m && un.merge(x[i].p1,x[i].p2)){
                costrails += x[i].w;
                states++;
            }

        printf("Case #%d: %d %d %d\n",c++,states,(int)(costr+0.5),(int)(costrails+0.5));

    }

    return 0;
}
