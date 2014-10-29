#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
int n,m;
vector< vector<int> >c;

int st,en;
vector<int>vs;
bool bfs()
{
    queue<int>qx;
    vector<bool>vi =vector<bool>(n+1,0);
    vs =vector<int>(n+1,0);
    qx.push(st);
    vi[st]=0;
    while(!qx.empty())
    {
        st = qx.front();
        qx.pop();
        //cout<<st<<endl;
        if(st==en) return 1;
        for(int i=0; i<c[st].size(); i++)
        {
            if(!vi[c[st][i]])
            {
                qx.push(c[st][i]);
                if(!vs[c[st][i]])
                    vs[c[st][i]]=st;
                else
                    vs[c[st][i]]=(vs[c[st][i]]>st)?st:vs[c[st][i]];
            }
            vi[c[st][i]]=1;
        }
    }
    return 0;
}
void print(int en, int &st)
{
    if(en == st)
    {
        printf("%d",en);
        return;
    }
    print(vs[en],st);
    printf(" %d",en);
}
int main()
{

    while(scanf("%d\n",&n)==1)
    {
        c = vector< vector<int> >(n+1,vector<int>());
        for(int i=0; i<n; i++)
        {
            stringstream ss;
            string s;
            getline(cin,s);
            replace(s.begin(),s.end(),',',' ');
            replace(s.begin(),s.end(),'-',' ');
            ss<<s;
            int p;
            ss>>p;
            int x;
            while(ss>>x)
                c[p].push_back(x);
        }
        scanf("%d",&m);
        printf("-----\n");
        while(m-- && scanf("%d%d",&st,&en))
        {
            int aux = st;
            if(bfs())
                print(en,aux);
            else
                printf("connection impossible");
            printf("\n");
        }
    }
    return 0;
}
