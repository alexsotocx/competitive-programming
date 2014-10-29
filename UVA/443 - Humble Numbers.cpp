#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<sstream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    long long s[5849];
   set<long long> x;
    x.insert(1);
    int i=1;
    while(i<=5843)
    {
        s[i]=*x.begin();
        x.erase(x.begin());
        x.insert(s[i]*2ll);
        x.insert(s[i]*3ll);
        x.insert(s[i]*5ll);
        x.insert(s[i++]*7ll);
    }
    int n;
    while(scanf("%d",&n) && n)
    {
        char *y;
        if(n%10 == 1 && n%100!=11) y="st";
        else if(n%10 == 2 && n%100!=12) y="nd";
        else if(n%10 == 3 && n%100!=13) y="rd";
        else y="th";
        printf("The %d%s humble number is %lld.\n",n,y,s[n]);
    }
    return 0;
}
