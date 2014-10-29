#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<sstream>
using namespace std;
int main()
{
    string s1,s2;
    int n;

    map<string, int>m;
    while(getline(cin,s1))
    {
        int i=0;
        vector<string>x;
        stringstream ss1,ss2;
        ss1<<s1;
        while(ss1>>s1)
            x.push_back(s1);
        ss2<<x[x.size()-1];
        ss2>>n;
        if(x.size()==3)
            m[x[0]+x[1]]+=n;
        else
            m[x[0]]+=n;

    }
    for(map<string,int>::iterator it = m.begin();it!=m.end();it++)
        cout<<it->first<<": "<<it->second<<endl;
    return 0;
}
