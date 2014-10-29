#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    string a;
    while (getline(cin,a))
    {
        string s="";
        stack<char>b;
        for(int i=0; i<a.length(); i++)
            if(a[i]=='(' && a[i+1]=='*')
                s+='`',i++;
            else if(a[i]=='*' && a[i+1]==')')
                s+='\'',i++;
            else
                s+=a[i];
        int i;
        bool xd = false, ok = true;
        for(i=0; i<s.length(); i++)
        {

            if((s[i]==']' || s[i]==')'|| s[i]=='}' || s[i]=='\'' || s[i]=='>') )
            {

                if(!b.empty() && ((s[i]==']' && b.top()=='[') || (s[i]==')' && b.top()=='(') || (s[i]=='>' && b.top()=='<') || (s[i]=='\'' && b.top()=='`') || (s[i]=='}' && b.top()=='{')))
                {
                    b.pop();
                    continue;
                }
                    printf("NO %d\n",i+1);
                    ok=false;
                    break;
            }
            if(s[i]=='[' || s[i]=='('|| s[i]=='{' || s[i]=='`' || s[i]=='<')
                b.push(s[i]);
        }
        if(b.empty() && i==s.length()) printf("YES\n");
        else if(!b.empty()  && ok)printf("NO %d\n",i+1);
    }

    return 0;
}
