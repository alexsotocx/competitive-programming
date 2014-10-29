#include<cstdio>
#include<iostream>
using namespace std;
bool isletter(char x)
{
    return (x>='a' && x<='z') || (x>='A' && x<='Z');
}
char tolowercase(char x)
{
    return (x>='a' && x<='z')?x:(x+32);
}
int number(int x)
{
    return (x<10)?x:number(x%10 + number(x/10));
}
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        int x,y;
        x=y=0;
        for(int i=0; i<a.length(); i++)
            if(isletter(a[i]))
                x+=tolowercase(a[i])-'a'+1;
        for(int i=0; i<b.length(); i++)
            if(isletter(b[i]))
                y+=tolowercase(b[i])-'a'+1;
        x = number(x);
        y = number(y);
        double result = x*100.0/y;
        printf("%.2lf %c\n",(result<100.0)?result:y*100.0/x,'%');

    }
    return 0;
}
