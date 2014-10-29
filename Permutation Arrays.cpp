#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;
class mycomparison
{

public:
    bool operator() (const pair<string,int> &l, const pair<string,int> &rhs) const
    {
        return l.second>rhs.second;
    }
};
int main()
{
    int n,lol=0;;
    scanf("%d\n\n",&n);
    string s;
    while(n-- && getline(cin,s))
    {

        stringstream ss1,ss2;
        ss2<<s;
        getline(cin,s);
        ss1<<s;
        int x;
        priority_queue< int, vector< pair<string,int> >, mycomparison > q;
        while(ss1>>s && ss2>>x)
            q.push(make_pair(s,x));
        while (!q.empty())
        {
            cout <<q.top().first<<endl;
            q.pop();
        }
        if(n)cout<<endl;
        getline(cin,s);

    }
    return 0;
}
