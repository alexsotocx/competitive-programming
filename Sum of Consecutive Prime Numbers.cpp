#include<vector>
#include<set>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<bitset>
using namespace std;
vector<int> primes;
bitset<10001>s;
void sieve()
{
    int n=10000+1;
    s.set();
    s[0]=s[1]=false;
    for(int i=2; i<=10000+1; i++)
    {
        if(s[i])
        {
            primes.push_back(i);
            for(int j=i*i; j<=10000+1; j+=i)
                s[j]=0;
        }
    }
}
int main()
{
    int n;
    sieve();
    while(scanf("%d",&n)==1 && n)
    {
        int ret=(s[n])?1:0;
        for (int i=0; i<primes.size() && n>primes[i]; i++)
        {

            int aux=primes[i];
            for(int j=i+1; j<primes.size() && aux<n; j++)
                aux+=primes[j];
            if(aux==n)
              ret++;
        }
        printf("%d\n",ret);
    }
}
