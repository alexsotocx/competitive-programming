#include<iostream>

#include<cstdio>
using namespace std;
int abs(int n)
{
    return (n>=0)?n:-n;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t-- && scanf("%d",&n))
        printf("%d\n",(abs((63*n +7492)*5-498)/10)%10);
    return 0;
}
