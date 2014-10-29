#include<iostream>
#include<cstdio>
#include<cmath>
#define PI acos(-1);
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double a,b;
        scanf("%lf%lf",&a,&b);
        double rad = asin(b/sqrt(a*a + b*b));
        double func = a*sin(rad) + b*cos(rad);
        printf("%.2lf %.2lf\n",rad,func);
    }
    return 0;
}
