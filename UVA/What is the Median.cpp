#include<set>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    set<long>x;
    long k;
    while( scanf("%ld",&k)!=EOF)
    {
        x.insert(k);
        int m = (int)x.size();
        //sort(x.begin(),x.end());
        set<long>::iterator it = (x.begin());
        it+=m/2;
        if(m&1)
            printf("%ld\n",*it);
        else
            printf("%ld\n",(*it+*(--it))/2);
    }
    return 0;
}
