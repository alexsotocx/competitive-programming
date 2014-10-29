#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
#include<sstream>
#include<cstring>
using namespace std;
#define All(x) x.begin(),x.end()
vector<char> sim;
vector<vector<int> > g;
int getPos(char &x)
{
    return lower_bound(All(sim),x) - sim.begin();
}
int n;
vector<int>inD;
vector<bool>used;
vector<char>permutation;
void backtrack(int len)
{
    if(len == n)
    {
        for(int i=0; i<n; i++)
            printf("%c",permutation[i]);
        printf("\n");
        return ;
    }
    for(int i=0; i<n; i++)
    {

        if(inD[i] == 0 && !used[i])
        {
            //cout<<sim[i]<<endl;
            used[i] = true;
            permutation[len] = sim[i];
            for(int j=0; j<g[i].size(); j++)
                inD[g[i][j]]--;
            backtrack(len+1);
            for(int j=0; j<g[i].size(); j++)
                inD[g[i][j]]++;
            used[i] = false;
        }
    }
}
int main()
{
    string s1;
    bool flag = false;
    while(getline(cin,s1))
    {
        if(flag) printf("\n");
        flag = true;
        stringstream ss;
        ss<<s1;
        sim = vector<char>();
        char x,b;
        while(ss>>x)
            sim.push_back(x);
        sort(All(sim));
        n = sim.size();
        inD = vector<int>(n,0);
        used =vector<bool>(n,0);
        permutation = vector<char>(n);
        g = vector<vector<int> >(n);
        getline(cin,s1);
        ss.clear();
        ss<<s1;
        while(ss>>x>>b)
        {
            int xx = getPos(x);
            int bb = getPos(b);
            g[xx].push_back(bb);
            inD[bb]++;
        }
        backtrack(0);
    }
    return 0;
}
