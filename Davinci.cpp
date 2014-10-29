#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
typedef long long ll;
using namespace std;
bool isupper(char x)
{
    return x>='A' && x<='Z';
}
int main()
{
    set<ll>fib;
    ll a=1,b=2,aux;
    fib.insert(a);
    fib.insert(b);
    for(int i=2;i<47;i++)
    {
        fib.insert(a+b);
        aux =b;
        b+=a;
        a=aux;
    }
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        vector<ll>f;
        int max=1;
        for(int i=0;i<x;i++)
        {
            ll aux;
            scanf("%lld",&aux);
            //cout<<aux<<endl;
            if(fib.find(aux)!=fib.end()){
                f.push_back(aux);max=(max<aux)?aux:max;}
        }
        scanf("\n");
        string s;
        getline(cin,s);
        vector<char>c;
        for(int i=0;i<s.length();i++)
            if(isupper(s[i]))c.push_back(s[i]);
        map<ll,char>pos;
        for(int i=0;i<c.size() && i<f.size();i++){
            pos[f[i]]=c[i];
        }
        int i=f.size();
        string ret="";

        for(set<ll>::iterator it=fib.begin();it!=fib.end() && *it<=max; it++)
        {
            if(pos.find(*it)!=pos.end()){ret+=(pos[*it]);}
            else ret+="#";
        }
        cout<<ret<<endl;
    }
}
