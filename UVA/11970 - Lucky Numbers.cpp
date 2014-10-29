#include <stdio.h>
#include <sstream>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    stringstream b;

    for(int i=1; i<=t; i++)
    {
        double n;
        scanf("%lf",&n);
        b<<"Case "<<i<<":";
        unsigned long k=1,count=sqrt(n);
        for(k=n-1; k>=1;)
        {
            unsigned long x = n-k;
            if(x%count == 0)
                b<<" "<<x;
            count--;
            k=count*count;
        }
        b<<"\n";
    }
    printf("%s",b.str().c_str());

    return 0;
}
