#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#include<sstream>
using namespace std;
map<char,int>x;
struct classcomp
{
    bool operator() (const char& a, const int& b) const
    {
        if(x[a]>x[b]) return true;
        if(x[a]==x[b]) return a<b;
        return false;
    }
};
bool isletter(char x)
{
    return (x>='a' && x<='z') ||(x>='A' && x<='Z');
}
char toupper(char x)
{
    return (x>='A' && x<='Z')?x:x^32;
}

int main()
{
    string s;
    int a=0;
    scanf("%d\n",&a);
    x = map<char, int>();
    while(a--)
    {
        getline(cin,s);

        for(int i=0; i<s.length(); i++)
            if(isletter(s[i]))
                x[toupper(s[i])]++;


    }
    map<char,int,classcomp>m = map<char,int,classcomp>(x.begin(),x.end());
    map<char,int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
        printf("%c %d\n",it->first,it->second);
    return 0;
}
