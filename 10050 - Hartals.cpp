#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int d,h,hi;
        scanf("%d%d",&d,&h);
        bool *days = new bool[d+1];
        while(h-- && scanf("%d",&hi))
        {
            for(int i=hi; i<=d; i+=hi)
            {
                if((i)%7 == 6 || (i)%7==0) continue;
                days[i]=1;
            }
        }
        printf("%d\n",count(days,days+d+1,1));
    }
    return 0;
}
