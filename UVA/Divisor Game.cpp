#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<long> fac(1000001,1);
vector<long> mayor(1000001,1);
void sieve()
{
    mayor[1]=1;
    fac[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        fac[i]++;
        mayor[i] = (fac[mayor[i-1]]>fac[i])? mayor[i-1]:i;
        for(int j=i*2;j<=1000000;j+=i)
            fac[j]++;
    }
}
void factors(int n)
{

}
int main()
{
    sieve();
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int j;
        scanf("%d",&j);
        printf("%d\n",mayor[j]);
    }
    return 0;
}
