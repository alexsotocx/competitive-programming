#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
string a;
string fastpow(int n)
{
    if(n==0)return "";
    if(n==1)return a;
    string ret = fastpow(n/2);
    ret+=ret;
    if(n&1) ret+=a;
    return ret;
}
int main()
{
    string s;
    while(getline(cin,s) && s!=".")
    {
        int i;
        a="";
        for(i=0;i<s.size();i++)
        {
            a+=s[i];
            string ret = fastpow(s.size()/(i+1));
            if(ret==s) break;

        }

        printf("%d\n",(i==s.size())?0:s.size()/(i+1));
    }
    return 0;
}
