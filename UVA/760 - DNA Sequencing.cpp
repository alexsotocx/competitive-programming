#include<iostream>
#include<cstdio>
#include<set>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
bool comp(string a,string b)
{
    if(a.length()!=b.length()) return a.length()>b.length();
    return a<b;
}
int main()
{
    vector<string>x;
    string a,b;
    bool flag=false;
    while(getline(cin,a) && getline(cin,b))
    {
        string lol;
        getline(cin,lol);
        if(flag)printf("\n");
        flag=true;

        set<string>l;

        for(int i=0; i<b.length(); i++)
        {
            for(int j=i+1; j<b.length()+1; j++)
            {
                if(a.find(b.substr(i,j-i))!=-1)
                    l.insert(b.substr(i,j-i));
            }
        }

        if(!l.size())
        {
            printf("No common sequence.\n");
            continue;
        }
        x = vector<string>(l.begin(),l.end());
        sort(x.begin(),x.end(),comp);
        cout<<x[0]<<endl;
        for(int i=1; i<x.size(); i++)
            if(x[i].length()!=x[i-1].length()) break;
            else cout<<x[i]<<endl;


    }

    return 0;
}
