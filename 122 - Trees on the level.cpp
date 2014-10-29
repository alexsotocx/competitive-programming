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
struct ii
{
    int pos;
    int x;
    ii(int post, int xx)
    {
        pos = post;
        x = xx;
    }


};

class mycomparison
{
public:
    bool operator() (const ii& a, const ii&b) const
    {
        return b.pos<a.pos;
    }
};

int getpos(char x[])
{
    int n = strlen(x)-1;
    int ret =0;
    for(int i=0; i<n; i++)
        ret += (x[i]=='L')? -1:1;
    return ret;
}

int main()
{
    char s[400];
    while(scanf("%s",&s)==1)
    {
        if(strcmp(s,"()")==0)
        {
            printf("\n");
            continue;
        }
        vector<priority_queue<ii,vector<ii>,mycomparison> >levels(400);
        map<string,bool> vi;
        bool *vil = new bool[400];
        int pos;
        int level;
        int number;
        char b[400];
        sscanf(s,"(%d,%s",&number,&b);
        level = strlen(b)-1;
        vi[string(b,b+level)] = 1;
        vil[level] = 1;
        pos = getpos(b);
        levels[level].push(ii(pos,number));
        bool complete = true;
        int maxx=level;
        while(scanf("%s",&s)==1 && strcmp(s,"()")!=0)
        {
            sscanf(s,"(%d,%s",&number,&b);
            level = strlen(b)-1;
            if(vi[string(b,b+level)]) complete = false;
            vi[string(b,b+level)] = 1;
            vil[level] = 1;
            pos = getpos(b);
            levels[level].push(ii(pos,number));
            maxx = max(maxx,level);
        }
        for(int i=0; i<=maxx && complete; i++)
            complete &= vil[i];
        if(!complete)
        {
            printf("not complete\n");
            continue;
        }
        printf("%d",levels[0].top().x);
        for(int i=1; i<=maxx; i++)
        {
            if(levels[i].empty()) break;
            while(!levels[i].empty())
            {
                printf(" %d",levels[i].top().x);
                levels[i].pop();
            }
        }
        printf("\n");

    }
}

