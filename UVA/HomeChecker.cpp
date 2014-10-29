#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
using namespace std;
int main()
{
    int a,b,c;
    char s;
    int correct=0;
    stringstream ss;
    while(scanf("%d%c%d=",&a,&s,&b)==3)
    {
        string d;
        cin>>d;
        ss<<d;
        if(d=="?") continue;
        ss>>c;
        if(s=='+') correct+=(a+b==c)?1:0;
        else correct+=(a-b==c)?1:0;
    }
    printf("%d\n",correct);
}
