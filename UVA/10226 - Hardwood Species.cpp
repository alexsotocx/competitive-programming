#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d\n\n",&n);
    string s;
    while(n--)
    {
        map<string,int>x=map<string,int>();
        double con=0.0;
        while(getline(cin,s) && s!="")
        {
            x[s]++;
            con+=1.0;
        }
        for(map<string,int>::iterator it=x.begin();it!=x.end();it++)
            printf("%s %.04lf\n",(it->first).c_str(),(it->second)*100.0/con);
        if(n) printf("\n");
    }
}
