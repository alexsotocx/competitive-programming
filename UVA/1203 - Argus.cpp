#include<queue>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
class query
{
public:
    int key;
    int period;
    int actual;
public:
    query(int key,int period)
    {
        this -> key = key;
        this -> period = period;
        actual =period;
    }

};
class myquery
{
    public:
    bool operator() (const query &a,const query &b) const
    {

        if(a.actual!=b.actual)return a.actual>b.actual;
        return a.key>b.key;
    }
};
int main()
{
    priority_queue<query,vector<query>,myquery> q;
    string action;
    int key,period,k;
    while(cin>>action && action!="#" && cin>>key>>period){
        q.push(query(key,period));
    }
    cin>>k;
    while(k--)
    {
        query x = q.top();
        q.pop();
        printf("%d\n",x.key);
        x.actual+=x.period;
        q.push(x);
    }
    return 0;
}
