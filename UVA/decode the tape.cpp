#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long tobinary(string k)
{
    int binary=0;
    int a=k.length();
    int c=a;
    for(int i=0;i<c;i++)
    {
        int aux=a-i-2;
        if(aux==-1)
            binary+=(k[i]-'0')*(2<<(-1));
        else
            binary+=(k[i]-'0')*(2<<(aux));
        //cout<<(k[i]-'0')*(2<<a-i-2)<<endl;
        //binary+=*2<<((--a)-1);
    }
    return binary;
}
int main()
{
    string k;
    string anw="";
    while(getline(cin,k))
    {
        string binary="";

        for (int i=0; i<k.length(); i++)
        {
            if (k[i]=='|' || k[i]=='_')
                continue;
            if(k[i]=='.')
                continue;
            if(k[i]==' ')
                binary+='0';
            else
                binary+='1';
            //cout<<binary<<endl;

        }
        if(binary!="")
        anw+=tobinary(binary);
    }
    printf("%s",anw.c_str());
    return 0;
}
