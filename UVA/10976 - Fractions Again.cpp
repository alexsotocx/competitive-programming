#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;
int main()
{
    int k;
    while(scanf("%d",&k)==1)
    {
        int count=0;
        stringstream ss;
        for(int i=k+1;i<=2*k;i++)
        {
            if(!((k*i)%(i-k)))
            {
                int x= (k*i)/(i-k);
                count++;
                ss<<"1/"<<k<<" = 1/"<<x<<" + 1/"<<i<<"\n";
            }
        }

        printf("%d\n%s",count,ss.str().c_str());


    }
    return 0;
}
