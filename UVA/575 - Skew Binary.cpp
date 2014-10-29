#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
    string a;
    cin>>a;
    while(a[0]!='0')
    {
        long int b=0;
        int k=a.length();
        int c = k;
        for (int i = 0; i<c; i++)
            b+= (a[i]-'0')*((2<<--k)-1);
        printf("%ld\n",b);
        cin>>a;
    }
}
