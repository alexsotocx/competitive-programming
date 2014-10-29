#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
bool com(const string &a,const string &b)
{
    if(a[0]==b[0])
    {
        return a.size()<b.size() || a>b;
    }
    return b<a;
}
int main()
{
    int n;
    vector<string> lol;
    lol.push_back("90");
   // lol.push_back("9");
    lol.push_back("123");
    lol.push_back("124");
    lol.push_back("56");
    sort(lol.begin(),lol.end(),com);
    cout<<lol[0]<<" "<<lol[1]<<" "<<lol[2]<<" "<<lol[3]<<endl;
    while(scanf("%d",&n)!=EOF && n)
    {

        string t;
        cin>>t;
        //cout<<t<<endl;
        string answ="";
        n = (int)t.size()/n;
        for(int i=0;i<t.size();i+=n)
        {
            string sub = string(t.begin()+i,t.begin()+(i+n));
            answ+=string(sub.rbegin(),sub.rend());
        }
        printf("%s\n",answ.c_str());
    }
    return 0;

}
