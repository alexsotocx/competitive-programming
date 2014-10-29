#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
int main()
{
    int n;
    bool x=false;
    while(scanf("%d",&n)==1)
    {
        if(x) printf("\n");

        x=true;
        map<string,int>f;
        string s;
        vector<string>lol;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            lol.push_back(s);
            f[s]=0;
        }

        while(n--)
        {
            int a,b;
            cin>>s>>a>>b;
            f[s]-=(b)?(a/b)*b:0;
            //cout<<s<<" "<<f[s]<<endl;
            for(int i=0; i<b; i++){
                cin>>s; f[s]+=a/b;
            }

        }
        for(int i=0; i<lol.size(); i++)
            printf("%s %d\n",lol[i].c_str(),f.find(lol[i])->second);

    }
}
