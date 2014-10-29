#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
typedef long long unsigned llu;
int main()
{
    llu s;
        llu b=0;
        llu d;
        for(llu i=1; true; i+=2)
        {
            if(b>=100000000) {cout<<i <<" "<<b<<endl;break;}
            d = (llu)(sqrt(i*1.0));
            b +=d%100000000;
        }
        cout<<b<<endl;

    return 0;
}
