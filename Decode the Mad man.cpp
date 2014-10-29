#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
#include <ctype.h>
#define forn(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int pos(char b, char x[])
{
    forn(i,0,26)
        if(b==x[i])
            return i;
    return -1;
}
int main()
{
    //freopen("in.in","r",stdin);
    char bca[] = "ertyuiop[]dfghjkl;'cvbnm,.";
    char abc[] = "qwertyuiopasdfghjklzxcvbnm";
    char c[100000];
    stringstream ss;
    while(cin.getline (c,100000))
    {
        string n(c);
        forn(i,0,n.length())
        {
            if(n[i]==32)
            {
                ss<<" ";
                continue;
            }
            int p = pos(tolower(n[i]),abc);
            if(p!= -1)
                ss<<bca[p];
        }
        ss<<endl;
        printf("%s",ss.str().c_str());
    }


        return 0;
}
