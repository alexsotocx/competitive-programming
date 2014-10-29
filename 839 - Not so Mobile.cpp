#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int c;
    scanf("%d",&c);
    string lol;
    getline(cin,lol);
    while(c--)
    {
        string str;
        bool ok = true;
        while(str!="")
        {
            int w1,d1,w2,d2;
            getline(cin,str);
            sscanf(str.c_str(),"%d%d%d%d",w1,d1,w2,d2);
            if(w1*d1!=w2*d2) ok=false;
        }
        printf((ok)?"YES\n":"NO\n");
    }
    return 0;
}
