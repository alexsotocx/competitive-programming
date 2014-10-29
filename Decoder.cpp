#include<iostream>
#include<cstdio>
#include<sstream>
using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
char snv[] = "ertyuiop[]\dfghjkl;'cvbnm,./";
char abc[] = "qwertyuiop[asdfghjklzxcvbnm,";
int pos(char x)
{
    forn(i,0,13)
    {
        if(x==snv[i]) return i;
        if(x==snv[26-i]) return 26-i;
    }

    return -1;
}

int main()
{
    string ss;
    char aux[100000];
    while(gets(aux))
    {
        int lol = string(aux).length();
        forn(i,0,lol)
        {
            if(aux[i]==32)printf("%c",32);
            else printf("%c",abc[pos(tolower(aux[i]))]);
        }
        printf("\n");
    }
    return 0;
}
