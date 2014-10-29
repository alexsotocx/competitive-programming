#include<iostream>
#include<cstdio>
#include<sstream>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;
map<string,bool>visited;
map<string,int>l;
map<string,set<string> >graph;
void bfs()
{
    visited = map<string,bool>();
    l["Erdos, P."] = 0;
    visited["Erdos, P."] =1;
    queue<string>qs;
    qs.push("Erdos, P.");
    while(!qs.empty())
    {
        string s= qs.front();
        qs.pop();
        //cout<<s<<endl;
        for(set<string>::iterator it=graph[s].begin(); it!=graph[s].end(); it++)
        {
            if(visited.find(*it)==visited.end())
            {
                //cout<<*it;
                visited[*it]=true;
                qs.push(*it);
                l[*it]=l[s]+1;

            }
        }
    }
}
int main()
{
    int c=1,cases;
    cin>>cases;
    while(cases--)
    {
        //printf("Scenario %d\n",c++);
        int n,m;
        cin>>n>>m;
        getchar();
        graph = map<string,set<string> >();
        while(n--)
        {
            string line;

            getline(cin,line);
            //cout<<line<<endl;
            stringstream ss(line);
            getline(ss,line,':');
            vector<string>lol;
            string aux;
            stringstream iss(line);
            int x=0;
            while(getline(iss,aux,','))
                lol.push_back(aux);
            vector<string> xd;

            for(int i=0; i<lol.size(); i+=2)
            {
                string s=lol[i]+","+lol[i+1];
                if(i) s = s.substr(1);
                //cout<<s<<endl;
                xd.push_back(s);
            }
           for(int i =0; i<xd.size(); i++)
                for(int j=0; j<xd.size(); j++)
                    graph[xd[i]].insert(xd[j]);


            //;


        }
       bfs();
        /*for(map<string,vector<string> >::iterator it = graph.begin(); it!=graph.end();it++)
           {
               cout<<it->first<<"->";
               for(int i=0;i<it->second.size();cout<<it->second[i++]<<"-");
               cout<<endl;
           }*/
        //bfs();
        while(m--)
        {
            string aux;
            getline(cin,aux);
            if(visited[aux]) printf("%s %d\n",aux.c_str(),l[aux]);
            else printf("%s infinity\n",aux.c_str());
        }
    }
}
