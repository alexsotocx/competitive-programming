#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
bool isletter(char x)
{
    return  (x>='A' && x<='Z')||(x>='a' && x<='z');
}
int main()
{
    char c;
    int may=-1;
    int Ma[26]={0};
    int Mi[26]={0};
    while(scanf("%c",&c)==1)
    {

        if(c=='\n')
        {
            for(int i=0;i<26;i++)
                if(Ma[i]==may) printf("%c",(char)(i+'A'));
            for(int i=0;i<26;i++)
                if(Mi[i]==may) printf("%c",(char)(i+'a'));
            printf(" %d\n",may);
            may=-1;
            memset(Ma, 0, sizeof(Ma));
            memset(Mi, 0, sizeof(Mi));
        }
        else if(isletter(c))
        {
            if(c>='A' && c<='Z'){
                ++Ma[c-'A'];
                if(Ma[c-'A']>may)may=Ma[c-'A'];
            }
            else
            {
                ++Mi[c-'a'];
                if(Mi[c-'a']>may)may=Mi[c-'a'];
            }
        }
        else
            continue;
    }
    return 0;
}
