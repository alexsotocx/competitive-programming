#include<list>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
char s[100001];
int main()
{
    list<char>::iterator it;
    while(gets(s))
    {
        int n = strlen(s);
        bool x=true;
        list<char>out;
        for(int i=0; i<n; i++)
            if (s[i] == ']')
                x = true;
            else if (s[i] == '[')
                x = false;
            else if (x)
                out.push_back(s[i]);
            else if (!x)
            {
                it = out.begin();
                for(i;i<n && s[i]!='[' && s[i]!=']';i++)
                   out.insert(it,s[i]);
                i--;
            }
        for(list<char>::iterator it=out.begin(); it!=out.end(); it++)
            printf("%c",*it);
        printf("\n");
    }
}
