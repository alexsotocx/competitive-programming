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
    int c,n,t,m,ti;
    string y;
    scanf("%d",&c);
    while(c-- && scanf("%d%d%d",&n,&t,&m))
    {

        queue<pair<int ,int> >left,right;
        int i=0;

        while(m-- && cin>>ti>>y)
        {
            if(y=="left")
                left.push(make_pair(ti,i++));
            else
                right.push(make_pair(ti,i++));
        }
        int tim = 0;
        bool onleft=1;
        int nn=0;
        i=0;

        map<int,int>x;
        //cout<<"xD"<<endl;
        while(!left.empty() || !right.empty() || nn)
        {
            if(onleft)
            {
                if(!left.empty() && !right.empty() && tim< left.front().first){
                    if(left.front().first<= right.front().first)
                        tim=left.front().first;
                    else
                    {
                        onleft=false;
                        tim = max(right.front().first+t,tim+t);

                        continue;
                    }
                }
                else if(right.empty())
                    tim=max(left.front().first,tim);
                else if(left.empty())
                {
                    onleft=false;
                    tim = max(right.front().first+t,tim+t);
                    continue;
                }
                nn=0;
                while(!left.empty() && tim>=left.front().first && nn<n)
                {
                   x[left.front().second] = tim+t;
                    left.pop();
                    nn++;
                    if(!left.empty() && left.front().first<=tim) continue;
                    if(!right.empty() && tim+t>= right.front().first) break;

                }
                tim+=t;
                onleft=false;
            }
            else
            {
                if(!left.empty() && !right.empty() && tim< right.front().first){
                    if(left.front().first>= right.front().first)
                        tim=right.front().first;
                    else
                    {
                        onleft=true;
                        tim = max(left.front().first+t,tim+t);
                        continue;
                    }
                }
                else if(left.empty())
                    tim=max(right.front().first,tim);
                else if(right.empty())
                {
                    onleft=true;
                    tim = max(left.front().first+t,tim+t);
                    continue;
                }
               // cout<<"Derecha = "<<++i<<" "<<tim<<endl;
                nn=0;

                while(!right.empty() && tim>=right.front().first && nn<n)
                {
                    x[right.front().second] = tim+t;
                    right.pop();
                    nn++;
                    if(!right.empty() && right.front().first<=tim) continue;
                    if(!left.empty() && tim+t>= left.front().first) break;
                }
                tim+=t;
                onleft=true;
            }
        }
        for(map<int,int>::iterator it = x.begin();it!=x.end();it++)
                printf("%d\n",it->second);
        if(c)printf("\n");
    }
    return 0;
}
