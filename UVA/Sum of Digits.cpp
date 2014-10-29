#include<iostream>
#include<cstdio>
int sum(long k)
{
    if(k<10)
        return k;
    int ret=0;
    while(k>=1)
    {
        ret+=k%10;
        k/=10;
    }
    return sum(ret);
}
int main()
{
    long k;
    while(scanf("%ld",&k)!=EOF && k)
        printf("%d\n",sum(k));
    return 0;
}
