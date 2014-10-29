#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int a,b;
    int i=1;
    while(cin>>a>>b && a+b)
        if(a<=26*b+b)
            printf("Case %d: %d\n",i++,(int)((a*25)/(b*27)));
        else
            printf("Case %d: impossible\n",i++);
            return 0;
}
