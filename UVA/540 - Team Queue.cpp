#include <iostream>
#include <math.h>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <deque>

using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
#define PB(x) push_back(x)
class mypair
{
    public:
    int f;
    int s;
    public:
    mypair(int x,int y)
    {
        f=x;
        s=y;
    }
};
class mycomparasion
{
    public:
    bool operator()(mypair x, mypair y)
    {
        return x.s>y.s;
    }
};
int main()
{
    queue<mypair> myq;
    myq.push(mypair(1,2));
    myq.push(mypair(5,1));
    myq.push(mypair(2,4));
    myq.push(mypair(3,2));
    myq.push(mypair(6,8));
    while(!myq.empty())
    {
        cout<<myq.front().f<<endl;
        myq.pop();
    }
    return 0;
}
