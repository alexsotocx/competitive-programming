#include <iostream>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <string.h>
#include <vector>
using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
#define PB(x) push_back(x)
int main()
{
    multimap<char*,char*>ok;
    char in[1000];
    freopen("in.txt","r",stdin);
    while(scanf("%s",&in)==1)
    {
        string input(in);
        char k[1000];
        strcpy(k,in);
        if(input=="XXXXXX")break;
        char y[1000];
        strcpy(y,in);
        sort(y,y+input.length());
        //cout<<y<<" "<<k<<endl;
        ok.insert(pair<char*,char*>(y,k));

    }
    char lol[1000];
    for (multimap<char*, char*>::iterator it1 = ok.begin();it1 != ok.end();++it1)
    {
        cout<<it1->first<<" "<<it1->second<<endl;
    }
    /*while(scanf("%s",&lol)==1&& lol!="XXXXXX")
    {
        string in(lol);
        sort(lol,lol+in.length());
        in = string(lol);

        if(ok.find(lol)==ok.end())
        {
            printf("%s\n******\n","NOT A VALID WORD");
            continue;
        }
        pair<multimap<char*,char*>::iterator, multimap<char*, char*>::iterator> ppp;
        ppp = ok.equal_range(lol);
        vector<char*>ans;
        for (multimap<char*, char*>::iterator it2 = ppp.first;it2 != ppp.second;++it2)
            ans.push_back(it2->second);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();printf("%s\n",ans[i++]));
        printf("******\n");

    }*/

    return 0;
}
