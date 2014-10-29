#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<bitset>
using namespace std;

bitset<1100>s;

void sieve()
{
    int k = sqrt(1100);
    s.set();
    s[0]=s[1]=0;
    for(int i=2;i<=k;i++)
    {
        if(s[i])
        {
            for(int j=i*i;j<=1100;j+=i)
                s[j]=0;
        }
    }
}
bool isupper(char k)
{
    if(k>='A' && k<='Z')
        return true;
    return false;
}


int main()
{
    sieve();
    char k[20];
    while(scanf("%s",&k)==1)
    {
        int size = string(k).size();
        int sum=0;
        for(int i=0;i<size;i++)
        {
            if(!isupper(k[i]))
                sum+=1+(k[i]-'a');
            else
                sum+=1+(k[i]-'A')+26;
        }
        //cout<<sum<<endl;
        if(s[sum] || sum==1)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}
