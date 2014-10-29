#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
long GCD (long a,long b)
{
    if(!b) return a;
    return GCD(b,a%b);
}
long LCM(long a,long b)
{
    return (a*b)/GCD(a,b);
}
int main()
{
    long n;
    while(scanf("%ld",&n)==1 && n)
    {
        vector<long>divisor;
        long m =sqrt(n);
        for(long i=1;i<=m;i++)
        {
            if(!(n%i))
            {
                divisor.push_back(i);
                if(i != n/i)
                    divisor.push_back(n/i);
            }
        }
        set<long>k;
        for(int i=0;i<divisor.size();i++)
        {
            for(int j=0;j<divisor.size();j++)
            {
                //cout<<divisor[i]<<" "<<divisor[j]<<endl;
                if(LCM(divisor[i],divisor[j])==n)
                    k.insert(divisor[i]+divisor[j]);
            }
        }
        printf("%d %d\n",n,k.size());
    }
}
