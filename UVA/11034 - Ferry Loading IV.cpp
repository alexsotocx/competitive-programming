#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.second<b.second;
}
int main()
{
    int c,l,t,m,ti;
    string y;
    scanf("%d",&c);
    while(c-- && scanf("%d%d",&l,&m))
    {

        queue<int>left,right;
        int i=0;

        while(m-- && cin>>ti>>y)
        {
            if(y=="left")
                left.push(ti);
            else
                right.push(ti);
        }
        int tim = 0;
        bool onleft=1;
        int nn=0;
        i=0;
        l*=100;
        while(!left.empty() || !right.empty())
        {
            if(onleft)
            {
                int lo=0;
                while(!left.empty() && lo+left.front()<=l)
                {
                    lo+=left.front();
                    left.pop();
                }
                tim++;
                onleft=false;
            }
            else
            {
                int lo=0;
                while(!right.empty() && lo+right.front()<=l)
                {
                    lo+=right.front();
                    right.pop();
                }
                tim++;
                onleft=true;
            }
        }
        printf("%d\n",tim);
    }
    return 0;
}
