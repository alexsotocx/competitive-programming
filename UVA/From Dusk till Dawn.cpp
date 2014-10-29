#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
struct node
{
    string city;
    int dt;
    int at;
};
map<string,bool>visited;
map<string, vector<node> >cities;
string stop;
int bfs(string c)
{

    queue<string>qc;
    qc.push(c);
    visited = map<string,bool>();
    visited[c]=1;
    while(!qc.empty())
    {
        c = qc.front();
        qc.pop;

    }
}

int main()
{
    int cases =0;
    scanf("%d",&cases);
    int cs =1;
    while(cases--)
    {
        int lines;
        scanf("%d",&lines);
        cities = map<string, vector<node> >();
        string d,a;
        while(lines--)
        {

            int dt,at;
            cin>>d>>a>>dt>>at;
            node aux;
            if(!((dt>=18 || (dt>=1 && dt<6)) && ((dt + at)%24<=6 || (dt + at)%24>=18))) continue;
            aux.city = a;
            aux.dt = dt;
            aux.at = ((at+dt)%24)?(at+dt)%24:24;
            cities[d].push_back(aux);
        }
        cin>>d>>stop;
        int ret = bfs(d);
        printf("Test Case %d.\n",cs++);
        if(ret)
            printf("Vladimir needs %d litre(s) of blood.\n",ret);
        else
            printf("There is no route Vladimir can take.\n");

    }
    return 0;
}
