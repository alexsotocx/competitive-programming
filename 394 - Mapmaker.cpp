#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<stack>
#include<cstring>
#include<queue>
#include<sstream>
#include<cmath>
using namespace std;
#define vi vector<int>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    map<string, vi >arrays;
    while(n--)
    {
        char y[10];
        int B,Cd,D;
        scanf("%s%d%d%d",&y,&B,&Cd,&D);
        vi C(D+1);
        vector<pair<int,int> >x;
       x.push_back(make_pair(0,0));
        for(int i=0; i<D; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            x.push_back(make_pair(a,b));
        }
        C[D] = Cd;
        for(int i=D-1; i>=1; i--)
            C[i] = C[i+1]*(x[i+1].second- x[i+1].first+1);
        C[0]=B;
        for(int i=1; i<=D; i++)
            C[0]-= C[i]*x[i].first;

        arrays[string(y)] = C;
    }
    while(m--)
    {
        char y[10];
        scanf("%s",&y);
        int D=arrays[string(y)].size();
        vi C = arrays[string(y)];
        int ans=C[0];
        stringstream ss;
        int a;
        scanf("%d",&a);
        ss<<y;
        ss<<"["<<a;
        ans+=C[1]*a;
        for(int i=2; i<D; i++)
        {
            scanf("%d",&a);
            ans+=C[i]*a;
            ss<<", "<<a;
        }
        ss<<"]";
        printf("%s = %d\n",ss.str().c_str(),ans);
    }
    return 0;

}
