#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<list>
#include<vector>
#include<cstring>
#include<iterator>
#include<algorithm>
using namespace std;
map<int,vector<int> >graph;
map<int,bool >vi;
bool ok = true;
void dfs(int s)
{
    vi[s] = true;
    for(int i=0;i<graph[s].size();i++)
        if(!vi[graph[s][i]])
            dfs(graph[s][i]);
        else
            ok = false;
}
int main()
{
    int s,from,c=1;
    while(scanf("%d%d",&s,&from) && s+from >= 0)
    {
        int a=s,b=from;
        if(a+b == 0) {printf("Case %d is a tree.\n",c++);continue;}
        graph = map<int,vector<int> >();
        map<int,int> indegree = map<int,int>() ;
        graph[a].push_back(b);
        int root = a;
        indegree[a] = 0;
        indegree[b] = 1;
        vi = map<int,bool >();
        while(scanf("%d%d",&a,&b) && a+b)
        {
            if(indegree.find(a)==indegree.end()) indegree[a] = 0;
            if(indegree.find(b)==indegree.end()) indegree[b] = 0;
            graph[a].push_back(b);
            indegree[b]++;
            vi[a] = false;
            vi[b] = false;

        }

        int con=0;
        for(map<int,int>::iterator it = indegree.begin(); it!=indegree.end(); it++)
            if(it-> second == 0) root = it-> first,con++;
        //cout<<root<<endl;
        ok = (indegree[root] == 0 && con==1);
        if (ok) dfs(root);
        for(map<int,vector<int> >::iterator it = graph.begin(); ok && it!=graph.end(); it++){
            ok &= (vi[it->first] == true);
        }
        if(ok)
            printf("Case %d is a tree.\n",c++);
        else
            printf("Case %d is not a tree.\n",c++);
    }
    return 0;
}
