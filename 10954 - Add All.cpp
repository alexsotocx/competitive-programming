#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
class mycomparison
{
public:
    bool operator() (const int& lhs, const int&rhs) const
    {
        return (lhs>rhs);
    }
};
int main()
{

    int n;
    while(scanf("%d",&n)==1 && n)
    {
        priority_queue<int,vector<int>,mycomparison> cola;
        int k;
        forn(i,0,n)
        {
            scanf("%d",&k);
            cola.push(k);
        }
        int x=0;
        long acum=0;

        while(cola.size()>1)
        {
            x=cola.top();
            cola.pop();
            x+=cola.top();
            cola.pop();
            cola.push(x);
            acum+=x;
        }
        printf("%ld\n",acum);
    }
    return 0;
}
