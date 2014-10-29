#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int pos(char a,char b[])
{
    for (int i=0; i<41;i++)
    {
        if(b[i]==a)
        return i;
    }
}
int main()
{
    char q[] ={'Q','W','E','R','T','Y','U','I','O','P','[',']'
    ,'A','S','D','F','G','J','K','L',';'
    ,'Z','X','C','V','B','N','M',',','.'
    ,'`','1','2','3','4','5','6','7','8','9','-'};
    char w[] = {'W','E','R','T','Y','U','I','O','P','[',']','\\',
    'S','D','F','G','J','K','L',';','\'',
    'X','C','V','B','N','M',',','.','/'
    ,'1','2','3','4','5','6','7','8','9','-','='};
    string a;

    while(cin.getline(a,256))
    {
        string ans="";
        for(int i=0;i<a.length();i++)
        {
            if(a[i]==32)
            {
                cout<<"Space\n";
                ans+=32;
            }
            else
            ans+=q[pos(a[i],w)];
        }
        cout<<ans<<endl;
    }
}
