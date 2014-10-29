#include<vector>
#include<cstdio>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>

using namespace std;
typedef  long long ll;
int main()
{
    set<int>k;
    for(int i=0;i<10;i++)
        k.insert(i);
    k.erase(5);
    set<int>::iterator it = k.lower_bound(-1);
    cout<<*it<<endl;
    it--;
    cout<<*it<<endl;
    it--;
    cout<<*it<<endl;
}
