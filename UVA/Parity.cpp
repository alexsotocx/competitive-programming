#include<cstdio>
#include<cmath>
#include<iostream>
#include<bitset>
using namespace std;
string b;
int parity(long k)
{
    if(k==1 || k==0)
    {
        b=(char)k+'0';
        return k;
    }
    b="";
    int ret=0;
    while(k>=1)
    {
        ret+=k%2;
        b+=(char)(k%2 +'0');
        k/=2;
    }
    b= string(b.rbegin(),b.rend());
    return ret;
}
int main()
{
    long n;
    while(scanf("%ld",&n)==1 && n)
    {
        int s = parity(n);
        printf("The parity of %s is %d (mod 2).\n",b.c_str(),s);
    }

}
