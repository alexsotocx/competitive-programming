#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<string,int>x;
int main()
{
    int n;
    string s;
    map<string,int>::iterator it;
    while(cin>>n>>s)
    {
        x = map<string,int>();
        for(int i=0; i<s.length()-n+1; i++)x[s.substr(i,n)]++;
        string res;
        int max=-1;
        for(it=x.begin(); it!=x.end(); it++)
        {
            if((*it).second>max)
            {
                res=(*it).first;
                max=(*it).second;
            }
        }
        printf("%s\n",res.c_str());
    }
}
