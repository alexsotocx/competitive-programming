#include<iostream>
#include<cstdio>
#include<bitset>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
vector<int>x;
string xd()
{
    int max = x[0];
    //cout<<x['s'-'a']<<endl;
    string ret = "a";
    for(int i=1;i<26;i++)
    {
       // cout<<x[i]<<endl;
        if(x[i]>max) max=x[i],ret=(char)(i+'a');
        else if(x[i]==max) ret+=(char)(i+'a');
    }
    return ret;
}
char tolower(char x)
{
     return ((x>='a' && x<='z'))? x:x^32;
}
bool isaletter(char x)
{
    //x=tolower(x);
    return (x>='a' && x<='z') || (x>='A' && x<='Z');
}
int main()
{
    string s;
    int n;
    scanf("%d\n",&n);
    while(n--)
    {
        getline(cin,s);
        x=vector<int>(26,0);
        for(int i=0;i<s.length();i++)
        {
            //cout<<"lol"<<endl;
            if(isaletter(s[i]))
                x[tolower(s[i])-'a']++;
        }
        printf("%s\n",xd().c_str());
    }
    return 0;
}
