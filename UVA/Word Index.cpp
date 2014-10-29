#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
    map<string, int>x;
    string a = "";
    for(int i=1;i<=26;i++)
        x[a+(char)(i+'a'-1)]=i;
    int count =26;
    for(int i=1;i<=26;i++)
        for(int j=i+1;j<=26;j++)
            x[a+(char)(i+'a'-1) + (char)(j+'a'-1) ]=++count;
    for(int i=1;i<=26;i++)
        for(int j=i+1;j<=26;j++)
             for(int k=j+1;k<=26;k++)
                x[a+(char)(i+'a'-1) + (char)(j+'a'-1)+ (char)(k+'a'-1) ]=++count;
    for(int i=1;i<=26;i++)
        for(int j=i+1;j<=26;j++)
             for(int k=j+1;k<=26;k++)
                for(int l=k+1;l<=26;l++)
                    x[a+(char)(i+'a'-1) + (char)(j+'a'-1)+ (char)(k+'a'-1)+ (char)(l+'a'-1) ]=++count;
    for(int i=1;i<=26;i++)
        for(int j=i+1;j<=26;j++)
             for(int k=j+1;k<=26;k++)
                for(int l=k+1;l<=26;l++)
                    for(int m=l+1;m<=26;m++)
                        x[a+(char)(i+'a'-1) + (char)(j+'a'-1)+ (char)(k+'a'-1)+ (char)(l+'a'-1)+ (char)(m+'a'-1) ]=++count;
    string s;
    while(cin>>s)
        if(x[s]) printf("%d\n",x[s]);
        else printf("0\n");
    return 0;
}
