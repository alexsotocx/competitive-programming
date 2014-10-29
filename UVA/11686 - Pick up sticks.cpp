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
int n,m;
vector<int>inD;
vector<bool>used;
vector<int>permutation;
int coun = 0;
bool backtrack(int len)
{
    if(len == n)
    {
        for(int i=0; i<n; i++)
            printf("%d\n",permutation[i]+1);
        return true;
    }
    for(int i=0; i<n; i++)
    {

        if(inD[i] == 0 && !used[i])
        {
            used[i] = true;
            permutation[len] = i;
            for(int j=0; j<g[i].size(); j++)
                inD[g[i][j]]--;
            if(backtrack(len+1));
                return true;
            for(int j=0; j<g[i].size(); j++)
                inD[g[i][j]]++;
            used[i] = false;
        }
    }
    return false;
}
int main()
{
    int a,b;
    bool flag = false;

    while(cin>>n>>m && n+m)
    {
        if(flag)
            printf("\n");
            flag = true;
        inD = vector<int>(n,0);
        used =vector<bool>(n,0);
        permutation = vector<int>(n);
        g = vector<vector<int> >(n);
        while(m-- && cin>>a>>b)
        {
            g[a-1].push_back(b-1);
            inD[b-1]++;
        }
        coun = 0;
        if(!backtrack(0))
            puts("IMPOSSIBLE");


    }
    return 0;
}
