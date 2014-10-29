#include<map>
#include<iostream>
#include<cmath>
#include<sstream>
#include<cstdio>
#include<vector>
using namespace std;
vector<bool> x(101,true);
vector<int>primes;
void sieve()
{
    x[0]=x[1] = false;
    for(int i=2; i<101; i++)
    {
        if(x[i])
        {
            for(int j=i*i; j<101; j+=i)
                x[j]=false;
            primes.push_back(i);
        }
    }
}
int main()
{
    sieve();
    map<int, map<int,int> > k;
    for(int i=2; i<=100; i++)
    {
        map<int,int>b;
        if(x[i])
        {
            b[i]=1;
            k[i] = b;
            continue;
        }
        int index=0;
        int pf = primes[index];
        int aux = i;
        while(aux!=1 && (pf<=aux))
        {
            b[pf]=0;
            while(aux%pf==0)
            {
                aux/=pf;
                b[pf]++;
            }
            pf = primes[++index];
        }
        k[i] = b;
    }
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        map<int,int>m;
        for(int i=2; i<=n; i++)
        {
            //cout<<i<<endl;
            for(int j=0; j<primes.size()&&primes[j]<=n; j++)
            {
                int pf = primes[j];
                if(m.find(pf)==m.end())
                    m[pf]=0;
                m[pf]+=k[i][pf];
                //cout<<pf<<" "<<m[pf]<<endl;
            }

        }
        printf("%3d! =%3d",n,m[2]);
        int count=1;
        for(map<int,int>::iterator it = ++m.begin(); it!=m.end(); it++)
        {
            if(count<15)
            {
                printf("%3d",it->second);
                count++;
                continue;
            }
            printf("\n%9d",it->second);
            count=1;
        }
        printf("\n");

    }
    return 0;
}
