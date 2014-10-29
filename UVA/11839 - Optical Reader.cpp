#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
int main()
{
    int n;
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)==1 && n)
    {
        forn(i,0,n)
        {
            char k='0';
            forn(j,0,5)
            {
                int gray;
                scanf("%d",&gray);
                if(gray<=127 && k=='0')
                {
                    k=65+j;
                    continue;
                }
                if(gray<=127)
                    k='*';
            }
            if (k=='0') k='*';
            printf("%c\n",k);
        }
    }
    return 0;
}
