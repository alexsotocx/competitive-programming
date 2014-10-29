#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        queue<int>c;
        for(int i=1; i<=n; c.push(i++));
        stringstream ss;
        ss<<"Discarded cards:";
        if(n==1)
        {
            printf("Discarded cards:\nRemaining card: 1\n");
            continue;
        }
        c.pop();
        c.push(c.front());
        c.pop();
        ss<<" 1";
        while(c.size()>=2)
        {
            ss<<", "<<c.front();
            c.pop();
            c.push(c.front());
            c.pop();
        }
        printf("%s\nRemaining card: %d\n",ss.str().c_str(),c.front());
    }
    return 0;
}
