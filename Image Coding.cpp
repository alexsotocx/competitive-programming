#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<cstring>
#include<list>
#include<sstream>
using namespace std;
typedef long long ll;
int main()
{
    int x,r,c,m,n;
    cin>>x;
int abc[26];
    int cas = 0;
    while(n-- && cin>>r>>c>>m>>n)
    {
        int maxs=0;

        memset(abc,0,sizeof(abc));
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                char s;
                cin>>s;
                abc[s-'A']++;
                maxs = (maxs<abc[s-'A'])?abc[s-'A']:maxs;
            }
        }
        int ans=0;
        for(int i=0; i<26; i++){//cout<<(char)('A' + i)<<" "<<abc[i]<<endl;
            if(abc[i]==maxs) ans+=abc[i]*m;
            else  ans+=abc[i]*n;
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
