#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    char a[1001],b[1001];
    while(gets(a) && gets(b))
    {
        int n=min(strlen(a),strlen(b));
        string ans="";
        if(n==strlen(a))
        {
            sort(a,a+strlen(a));
            for(int i=0; i<n; i++)
            {
                int aa = upper_bound(a,a+strlen(a),a[i]) - lower_bound(a,a+strlen(a),a[i]);
                int bb = count(b,b+strlen(b),a[i]);
                ans+=string(min(aa,bb),a[i]);
                i+=aa-1;
            }
        }
        else
        {
            sort(b,b+strlen(b));
            for(int i=0; i<n; i++)
            {
                int bb = upper_bound(b,b+strlen(b),b[i]) - lower_bound(b,b+strlen(b),b[i]);
                int aa = count(a,a+strlen(a),b[i]);
                ans+=string(min(aa,bb),b[i]);
                i+=bb-1;
            }
        }
        printf("%s\n",ans.c_str());
    }
}
