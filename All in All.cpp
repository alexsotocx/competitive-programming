#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    string a,b;
    while(cin>>a>>b)
    {

        int j=0,i;
        for(i=0; i<a.length() && j<b.length(); i++){
            while(j<b.length())
                if(b[j++]==a[i]) break;
            if(b[j-1]!=a[i]) break;
        }
        if(i== a.length()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
