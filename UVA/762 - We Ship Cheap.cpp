#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
map<string, vector<string> >graph;
map<string, bool>visited;
string stop;
void bfs(string x)
{
    queue<pair<string, string> >q;
    q.push(make_pair(x,""));
    visited = map<string,bool>();
    visited[x]=1;
    while(!q.empty())
    {
        x = q.front().first;
        string w = q.front().second;
        q.pop();
        vector<string> &aux = graph[x];
        for(int i=0;i<aux.size();i++)
            if(!visited[aux[i]])
            {
                visited[aux[i]]=1;
                if(aux[i]==stop) {printf("%s",(w+x+" "+aux[i]).c_str()); return;}
                q.push(make_pair(aux[i],w+x+" "+aux[i]+"\n"));
            }
    }
    printf("No route");
}
int main()
{
    int n;
    bool blank=0;
    while(scanf("%d",&n)==1)
    {

        string a,b;
        graph  = map<string,vector<string> >();
        while(n--)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cin>>a>>stop;
        bfs(a);
        printf("\n");

    }
    return 0;
}
