#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
char s[] = "0123456789ABCDEF";
string tohex(int a)
{
    string x(2,'-');
    x[1] = s[a%16];
    x[0] = s[(a/16)%16];
    return x;
}
int main()
{
    int T;
    cin>>T;
    getchar();
    int cas=1;
    while(T--)
    {
        char op[100002];
        gets(op);
        int n = strlen(op);
        int p=0;
        int x[100];
        for(int i=0; i<n; i++)
            if(op[i]!='.')
            {
                if(op[i]=='<')
                    p = (p-1)%100;
                else if(op[i]=='+')
                    x[p] = (x[p]+1)%256;
                else if(op[i]=='-')
                    x[p] = (x[p]-1)%256;
                else
                    p = (p+1)%100;
            }
        printf("Case %d:",cas++);
        for(int i=0;i<100;i++)
            printf(" %s",tohex(x[i]).c_str());
        printf("\n");

    }
}
