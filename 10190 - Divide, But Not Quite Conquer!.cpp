#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#include<iostream>
#include<sstream>
using namespace std;

bool xd=true;
string divide(long n,long &m)
{
    if(n==1) return "1";
    if(n%m==0)
    {
        stringstream bug;
        bug<<n;
        string aux = (bug.str()+" ");
        return aux.append(divide(n/m,m));
    }
    xd = false;
    return divide(n/n,m);
}
int main()
{
    long a,b;
    while(scanf("%ld%ld",&a,&b)!=EOF)
    {
        xd=true;
        if (a < 2 || b < 2 || (a < b)){printf("Boring!\n");continue;}
        string aux=divide(a,b);
        if(xd) printf("%s\n",aux.c_str());
        else printf("Boring!\n");
    }
    return 0;
}
