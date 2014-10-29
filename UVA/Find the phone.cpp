#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
char c[]="10ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char fc[]="1022233344455566677778889999";
int main()
{
    string in;
    vector<char>x(c,c+28);
    while(cin>>in)
    {
        for(int i=0;i<in.length();i++)
        {
            if(in[i]=='-') continue;
            vector<char>::iterator p = find(x.begin(),x.end(),in[i]);
            in[i] = fc[p-x.begin()];
        }
        printf("%s\n",in.c_str());
    }
}
