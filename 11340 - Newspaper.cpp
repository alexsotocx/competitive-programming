#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {

        char b;int m,a;
        scanf("%d\n",&m);
        map<char,int>c=map<char,int>();
        while(m--)
        {
            scanf("%c %d\n",&b,&a);
            c[b]=a;
        }
        scanf("%d\n",&m);
        string ac="",l;
        while(m-- && getline(cin,l) )
            ac+=l;
        double ret=0.0;
        for(map<char,int>::iterator it=c.begin();it!=c.end();it++)
            ret+=count(ac.begin(),ac.end(),it->first)*(it->second)*1.0;
        printf("%.2lf$\n",ret/100.0);
    }
    return 0;
}
