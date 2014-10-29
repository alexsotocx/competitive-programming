#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a,num;
        priority_queue<int>pq;
        queue<int>q;
        stack<int>s;
        bool x[3]={1,1,1};
        while(n-- && scanf("%d %d",&a,&num))
        {
            if(!x[0] && !x[1] && !x[2] )continue;
            if(a==1)
            {
                if(x[0])
                    pq.push(num);
                if(x[1])
                    q.push(num);
                if(x[2])
                    s.push(num);
                continue;
            }
            if(!pq.empty() && x[0] && num == pq.top()) pq.pop();
            else x[0]=false;
            if(!q.empty() && x[1] && num == q.front()) q.pop();
            else x[1]=false;
            if(!s.empty() && x[2] && num == s.top()) s.pop();
            else x[2]=false;
        }
        int couns = x[0]+ x[2]+x[1];
        if(couns>=2) printf("not sure\n");
        else if(couns==0) printf("impossible\n");
        else if(x[0]) printf("priority queue\n");
        else if(x[1]) printf("queue\n");
        else printf("stack\n");
    }
    return 0;
}
